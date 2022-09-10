//
// Created by Alias on 9/10/2022.
//
#include <bits/stdc++.h>
using namespace std;

class Handler{
protected:
public:
    explicit Handler(Handler *successor) : successor(successor) {}

protected:
    Handler* successor = nullptr;
public:
    virtual void handle() = 0;
};

class Handler1: public Handler{
public:
    using Handler::Handler;

    void handle() override {
        bool handled = false;
        //check is handled
        cout << "check Handle1" << endl;
        if (!handled && successor != nullptr) {
            successor->handle();
        }
    }
};

class Handler2: public Handler{
public:
    using Handler::Handler;

    void handle() override{
        bool handled = false;
        cout << "check handle2" << endl;
        if (!handled && successor != nullptr) {
            successor->handle();
        }
    }
};

int main() {
    Handler* handler1 = new Handler1(nullptr);
    Handler2* handler2 = new Handler2(handler1);
    handler2->handle();
    return 0;
}
