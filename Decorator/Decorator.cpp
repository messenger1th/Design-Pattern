//
// Created by Alias on 9/10/2022.
//
#include <bits/stdc++.h>
using namespace std;




class Base{
public:
    virtual void f() {
        cout << "Base" << endl;
    }
};

class ADecorator: public Base{
    shared_ptr<Base> base;
public:
    explicit ADecorator(Base* base) : base(base) {}

public:
    void f() override {
        cout << "A: do extra work" << endl;        //do extra work;
        base->f();
        cout << "A: do extra work" << endl;        //do extra work;
    }
};


class BDecorator: public Base{
    shared_ptr<Base> base;
public:
    explicit BDecorator(Base* base) : base(base) {}

public:
    void f() override {
        cout << "B: do extra work" << endl;        //do extra work;
        base->f();
        cout << "B: do extra work" << endl;        //do extra work;
    }
};

int main() {
    ADecorator* aDecorator = new ADecorator(new Base);
    BDecorator* bDecorator = new BDecorator(aDecorator);
    aDecorator->f();
    cout << endl;
    bDecorator->f();

}