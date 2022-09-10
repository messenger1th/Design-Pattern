# Singleton Evolution

## Implementation

### Thread Safe

For Lazy Initialization Class, for example **Lazy Singleton**, consider code as follow.

```cpp
Singleton* Singleton::CreateInstance()  {
    /* traditional implementation. */
    if (instance == nullptr) {
        std::unique_lock<std::mutex> lock(m); 
        if (instance == nullptr)
            instance = new Singleton;
    }
    return instance;
}
```

when other thread changed the  instance pointer, which is not `nullptr` already, will return a undefined  value with incomplete assignment.

As a solution, Use `atomic` to avoid incomplete assignment.

Specially, Use C++11 feature `one_flag` and `call_once` to solve it.

```cpp
std::once_flag onceFlag;
Singleton* instance(nullptr);

Singleton *Singleton::CreateInstance()  {
    /* C++11 elegant implement. */
    std::call_once(onceFlag, [&] { instance = new Singleton; } );
    return instance;
}
```

By the way, `[&] { instance = new Singleton; }` Lambda Function is C++11feature, too.



Honestly, use `static` is a solution, too.

```cpp
Singleton *Singleton::CreateInstance()  {
    static instance* = new Singleton;
    return instance;
}
```



### Distributed

 deserialize it from shared space(e.g. file) and serialize it into file. 



## Disadvantage

1. hide the dependency of different class (without pass params or explicit create).
2. Bad extensibility.(e.g. extend to two instances. one day)
3. Bad testability.(hard to test by inheriting it)
4. constructor without params.







