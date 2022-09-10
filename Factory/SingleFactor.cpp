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

class SimpleFactory {
    class NoSupportClass{};
    static Base* createClass(const char& params) {
        switch (params) {
            case 'B': return new B();
            case 'A': return new A();
            default: throw NoSupportClass();
        }
    }
};



int main() {

    return 0;
}