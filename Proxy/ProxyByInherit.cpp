//
// Created by Alias on 9/10/2022.
//

#include <bits/stdc++.h>
using namespace std;

class Base {
public:
    virtual void f() {
        cout << "Base work" << endl;
    }
};


class Derived: public Base {
public:
    void f() override {
        cout << "extra work" << endl; //do extra work
        Base::f();
    }
};


int main() {
    Base *ptr = new Derived;
    ptr->f();
    return 0;
}