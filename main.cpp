#include <iostream>
#include <share.h>
#include <bits/stdc++.h>
#include <shared_mutex>
#include <bits/stdc++.h>
using namespace std;


std::mutex m;
bool empty() {
    std::unique_lock<std::mutex> lock(m);
    return true;
}

bool check() {
    std::unique_lock<std::mutex> lock(m);
    if (empty()) return false;
    return true;
}

class Base {
public:
    virtual void print() {

        cout << "base " << endl;
    }
};

class D: public Base{
public:
    virtual void print() {
        Base::print();
        cout << " d" << endl;
    }
};

int main() {
    D* d = new D;
    d->print();
}
