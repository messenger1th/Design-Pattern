# 单例

## 关键点

- 变量单例：类中变量设置为static
- 访问入口：只提供一个CreateInstance入口，删除拷贝构造函数、移动构造函数等
- 并发安全：用原子变量实现double check，第一次检查通过原子加载，第二次检查为空时加锁更新。



## 易错点

未用原子变量

```C++
static Singleton* CreateInstance() {
    // double check第一部分：这里存在并发问题，没用原子变量，所以可能临界态的值
    if (instance != nullptr) {
        return instance;
    }
    // double check第二部分：加锁再更新
    unique_lock<mutex> lock(m);
    if (instance == nullptr) {
        instance = new Singleton;
    }
    return instance;
}
```



## 参考代码

### 实现版

```C++
#include <thread>
using namespace std;

class Singleton {
private:
    static atomic<Singleton*> instance;
    static std::mutex m;

private: // 访问控制
    Singleton() = default;
    Singleton(const Singleton& rhs) = delete;
    Singleton& operator=(const Singleton& rhs) = delete;

public: // 只提供一个访问
    static Singleton* CreateInstance() {
      	// double check第一部分：用原子变量检查
        Singleton* tempPtr = instance.load();
        if (tempPtr != nullptr) {
            return tempPtr;
        }
				// double check第二部分：加锁再更新
        unique_lock<mutex> lock(m);
        tempPtr = instance.load();
        if (tempPtr == nullptr) {
            instance.store(new Singleton);
        }
        return tempPtr;
    }
};
```

### `call_once` API版本

类似实现版，once flag实际上包含一个flag和mutex，封装了double check。

```C++
#include <thread>
#include <future>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static once_flag init_flag;

private:
    Singleton() = default;
    Singleton(const Singleton& rhs) = delete;
    Singleton& operator=(const Singleton& rhs) = delete;

public:
    static Singleton* CreateInstance() {
        call_once(init_flag, [&] () { // call_once和flag搭配使用，其底层封装了double check和原子读的功能
            instance = new Singleton();
        });
        return instance;
    }
};
```



