//
// Created by Epoch on 2022/8/8.
//

#ifndef DESIGN_PATTERN_SINGLETON_H
#define DESIGN_PATTERN_SINGLETON_H

#include <thread>
#include <future>

using namespace std;

class Singleton {
private:
    static shared_ptr<Singleton> instance;
    static once_flag onceFlag;
    static atomic<int> count;

    /* for later concurrent work */
    static std::mutex m;
    static std::unique_lock<std::mutex> lock;

private:
    Singleton() = default;
    Singleton(const Singleton& rhs) = delete;
    Singleton& operator=(const Singleton& rhs) = delete;

public:
    static shared_ptr<Singleton> CreateInstance();

    //Resource recycle by reference counting.
    ~Singleton();
};

#endif //DESIGN_PATTERN_SINGLETON_H
