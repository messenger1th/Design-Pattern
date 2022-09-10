//
// Created by Alias on 9/10/2022.
//

#include <bits/stdc++.h>
using namespace std;

class Base {
public:
    void f() {
        cout << "Base Work" << endl;
    }
};

class IBase {
public:
    virtual void f() = 0;
    //add all function need proxy.
};

class BaseProxy: public IBase {
public:
    BaseProxy(Base* base): basePtr(base) {}
    shared_ptr<Base> basePtr;
    void f() override {
        cout << "extra work" << endl; //do extra work
        basePtr->f();
    }
};


int main() {
    BaseProxy* proxy = new BaseProxy(new Base());
    proxy->f();
    return 0;
}