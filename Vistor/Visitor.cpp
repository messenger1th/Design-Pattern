//
// Created by Alias on 9/10/2022.
//
#include <bits/stdc++.h>
using namespace std;
class D1;
class D2;
class D3;

class Visitor {
public:
    void operation(D1* p) {
        cout << "D1" << endl;
    }
    void operation(D2* p) {
        cout << "D2" << endl;
    }
    void operation(D3* p) {
        cout << "D3" << endl;
    }
};
class IVisitor{
public:
    virtual void accept(Visitor* visitor) = 0;
};

class Base: public IVisitor{};

class D1: public Base {
public:
    void accept(Visitor* visitor) override {
        cout << "Visit: ";
        visitor->operation(this);
    }
};

class D2: public Base {
public:
    void accept(Visitor* visitor) override {
        cout << "Visit: ";
        visitor->operation(this);
    }
};
class D3: public Base {
public:
    void accept(Visitor* visitor) override {
        cout << "Visit: ";
        visitor->operation(this);
    }
};



int main() {
    vector<Base*> data{new D1, new D2, new D3};
    Visitor* visitor = new Visitor;
    for (const auto& ptr: data) {
        ptr->accept(visitor);
    }
    return 0;
}