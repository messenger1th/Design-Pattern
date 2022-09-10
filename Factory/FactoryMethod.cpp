//
// Created by Alias on 9/7/2022.
//
#include <bits/stdc++.h>
using namespace std;

/*/
 * Simple Factory Pattern
 */
class Base{

};

class A: public Base{

};

class B: public Base{

};

/*/
 * Factory Method Pattern
 */
class IFactor{
public:
    virtual Base* create(); //create relevant class.
};

class AFactory: public IFactor{
public:
    Base* create() override; //create A;
};

class BFactory: public IFactor{
public:
    Base* create() override; //create B;
};

class FactoryMethod {
    class NoSupportClass{};
    static Base* createClass(const char& params) {
        IFactor* factor = nullptr;
        switch (params) {
            case 'A': factor = new AFactory(); break;
            case 'B': factor = new BFactory(); break;
            default: throw NoSupportClass();
        }
        return factor->create();
    }
};

/*
 * Abstract Factory Pattern
 */


int main() {

    return 0;
}