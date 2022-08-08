//
// Created by Epoch on 2022/8/8.
//
#include "Singleton.h"


/* implementation */
std::atomic<Singleton*> Singleton::instance(nullptr);
std::atomic<int> Singleton::count(0);
std::once_flag Singleton::onceFlag;
std::mutex Singleton::m;
std::unique_lock<std::mutex> Singleton::lock;

Singleton *Singleton::CreateInstance()  {

    /* traditional implementation. */
    /*
    if (instance == nullptr) {
        std::unique_lock<std::mutex> lock(m);
        if (instance == nullptr)
            instance = new Singleton;
    }
    */

    /* C++11 elegant implement. */
    std::call_once(onceFlag, [] { instance = new Singleton; } );

    ++count;
    return instance;
}

Singleton::~Singleton()  {
    --count;
    if (count == 0) {
        delete instance;
    }
}