# Factory Pattern

## Simple Factory Pattern

```cpp
class Base{};

class A: public Base{};

class B: public Base{};

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
```





## Factory Method Pattern

replace `if`branch by Polymorphism;

```cpp
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
```





## Abstract Factory Pattern

suit for multi varying dimension.



## Application

* DI container



