# Design Pattern

## 命令模式

在游戏内的应用：将命令封装成一个类，例如RPC。

* 可以让用户自定义按键对应的功能。**虚函数的简单应用**。
* 将输入与角色解耦，让AI角色可用同样的输入逻辑控制。**给函数传递角色引用，角色实现所需接口即可**。
* 支持撤销操作。在类中定义操作对于的`undo`函数实现即可。



## 观察者模式

这个在游戏内应用应该算是很广泛了。像是对碰撞的处理函数，事件，按键触发的各种输入绑定等等等等。

无需观察者每帧主动地检测，只需向被观察者注册要调用地函数。当触发条件满足时，被观察者通知注册的函数，告诉它们该执行了。



## 单例模式

> 保证一个类只有一个实例，并且提供了访问该实例的全局访问点。

像是游戏的World等通常定义为单例。

* 如果没人用，就不必创建实例。
* 它在运行时实例化。
* 可继承单例。

需要考虑的地方

* 理解代码更加困难
* 促进耦合的发生
* 对并行不友好。全局就意味着能被多线程访问，也就要考虑这方面的问题。



## 建造者模式

在创建对象之前进行一些校验、检测等工作。

可用于设定复制参数而非通过构造+`setter`的方式。

与工厂模式的不同：

1. 校验
2. 创建的是同一种对象，但参数可不一样。





## 组件模式

将一个本来庞大的类按逻辑区分成多个组件，各司其职，通过特定方式通信，如

* 通过修改容器（储存组件指针的类）的状态
* 通过互相引用。**但会使得互相引用的类耦合**
* 通过发送消息。**能使得组件之间解耦**



## 桥接模式

用于应对两种变化的类。假设两类有M、N种。

采用继承，需要设计维护M*N个类，而桥接模式采用组合来实现。仅需要M + N个类。



## 门面模式

让不同的系统采用相同的同一的接口，定义高层接口让子系统更容易使用。



## 组合模式

应用：目录树



## 模板方法模式

将流程的框架定好，可随意更改每个部分的具体实现。



## 策略模式

特定情况下，将`if`分支转为查表，如根据命名创建对象，由哈希表映射。



## 状态模式

对于状态的处理，如果简单判断逻辑就很容易让逻辑混乱，代码冗长难以维护。

* 常用的处理方式是**有限状态机**。将状态转移的逻辑分隔开到每一个部分（可以是状态类）中。

* 但是，这种状态机处理不了移动和开枪两部分的状态，而且添加状态会使得状态处理呈指数级增长。因此，引入**并发状态机**。将自身状态和武器状态分割成两个状态机。

* 为了解决状态代码重复的问题。还有**分层状态机**，将通用的部分抽象成基类。
* 为了解决开火并停火后不知道之前的状态的问题。引出**下推状态机**。使用栈来存储。



## 迭代器模式

将集合的存储和访问解耦，单一职责。



## 备忘录模式

* 存储副本以便恢复。
* 不违背封装的原则。



## 访问者模式

对象调用函数，例如`obj.func(params)`

具体调用哪个函数，取决于`obj`的类型和参数`parms`。

对于**Single Dispatch**的编程语言来说，对象是由动态绑定的。而`parms`是静态的，在编译期确定。

对于**Double Dispatch**的编程语言来说，都是根据运行的具体类型决定。

**Single Dispatch**语言为了实现**Double**的效果，就诞生了访问者模式。让需要动态确定的`parms`，让具有多态性质的对象来承担选择责任。



## 其他

* 享元模式：资源共享，优化渲染。
* 原型模式：根据类型`clone`出一样的的。
* 双缓冲模式
* 游戏循环
* 更新方法：每一帧都调用。如UE中的`Tick`
* 解释器模式：自己实现一个虚拟机。
* 中介模式



## 实现

**参考代码见同目录下由模式m'm各文件夹**



## 参考资料

* 《大话设计模式》
* 《Head First设计模式》
* [游戏编程模式 (tkchu.me)](https://gpp.tkchu.me/)
* 《设计模式之美》
