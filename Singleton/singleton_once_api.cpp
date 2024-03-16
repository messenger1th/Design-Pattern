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