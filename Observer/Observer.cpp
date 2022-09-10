//
// Created by Alias on 9/10/2022.
//

#include <bits/stdc++.h>
using namespace std;

class Observer{
public:
    virtual void update() = 0;
};

class ConcreteObserver: public Observer{
public:
    void update() override {
        cout << "ConcreteObserver" << endl;
    }
};

class Obj {
public:
    list<shared_ptr<Observer>> observers;

    void addObserver(Observer* observer) {
        observers.emplace_back(observer);
    }
    void notify() {
        for (const auto& observerPtr: observers) {
            observerPtr->update();
        }
    }
};


int main() {
    Obj* obj = new Obj;
    obj->addObserver(new ConcreteObserver);
    obj->notify();
    return 0;
}