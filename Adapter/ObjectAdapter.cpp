//
// Created by Alias on 9/10/2022.
//
#include <bits/stdc++.h>
using namespace std;

class IAdapter {
public:
    virtual void f() = 0;
};

class Adaptee{
public:
    void fa() {
        cout << "Adaptee" << endl;
    }
};

class Adaptor: public IAdapter{
    shared_ptr<Adaptee> adaptee;
public:
    Adaptor(Adaptee* adaptee): adaptee(adaptee) {}

    void f() override {
        cout << "Adaptor" << endl;
        adaptee->fa();
    }
};

int main() {
    Adaptor* adaptor = new Adaptor(new Adaptee);
    adaptor->f();
    return 0;
}
