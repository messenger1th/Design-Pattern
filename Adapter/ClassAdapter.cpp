//
// Created by Alias on 9/10/2022.
//
#include <bits/stdc++.h>
using namespace std;

class IAdapter{
public:
    virtual void f1() = 0;
};

class Adaptee{
public:
    void f1() {
        cout << "Adaptee" << endl;
    }
};

class Adaptor: public Adaptee, public IAdapter {
public:
    void f1() override {
        cout << "Adaptor" << endl; //do some adapt work
        Adaptee::f1();
    }
};

int main() {
    IAdapter* obj = new Adaptor();
    obj->f1();
    return 0;
}