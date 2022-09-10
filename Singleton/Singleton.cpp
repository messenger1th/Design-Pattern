//
// Created by Epoch on 2022/8/8.
//
#include "Singleton.h"


/* implementation */
std::shared_ptr<Singleton> Singleton::instance(nullptr);
std::once_flag Singleton::onceFlag;

//variable for traditional implementation.
std::mutex Singleton::m;
std::unique_lock<std::mutex> Singleton::lock;

shared_ptr<Singleton> Singleton::CreateInstance()  {

    /* traditional implementation. */
    /*
    if (instance == nullptr) {
        std::unique_lock<std::mutex> lock(m);
        if (instance == nullptr)
            instance = new Singleton;
    }
    */

    /* C++11 elegant implement. */
    std::call_once(onceFlag, [&] { instance.reset(new Singleton); } );
    return instance;
}

Singleton::~Singleton() = default;