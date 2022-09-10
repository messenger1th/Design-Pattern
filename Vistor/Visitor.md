# Visitor

Consider this situation.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Base {};
class D1: public Base {};
class D2: public Base {};
class D3: public Base {};

class Tools {
public:
    static void operation(D1* d1)  {}
    static void operation(D2* d2) {}
    static void operation(D3* d3) {}
};


int main() {
    vector<Base*> data{new D1, new D2, new D3};

    for (const auto& ptr: data) {
        Tools::operation(ptr); //error: No matching function for call to 'operation'
    }
    return 0;
}
```



## Single Dispatch

like `obj.func(params)`

The actual function called Depends on the ***running time object***(called running time Polymorphism) and  the ***compiling time parameters***.



## Double Dispatch

The actual function called Depends on the ***running time kind of Object and parameters.***



## Visitor Design Pattern

To implement double dispatch for single dispatch language, it happens.

```cpp
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
    virtual void accpet(Visitor* visitor) = 0;
};
class Base: public IVisitor{};
class D1: public Base {
public:
    void accpet(Visitor* visitor) override {
        cout << "Visit: ";
        visitor->operation(this);
    }
};

class D2: public Base {
public:
    void accpet(Visitor* visitor) override {
        cout << "Visit: ";
        visitor->operation(this);
    }
};
class D3: public Base {
public:
    void accpet(Visitor* visitor) override {
        cout << "Visit: ";
        visitor->operation(this);
    }
};



int main() {
    vector<Base*> data{new D1, new D2, new D3};
    Visitor* visitor = new Visitor;
    for (const auto& ptr: data) {
        ptr->accpet(visitor);
    }
    return 0;
}
```

