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