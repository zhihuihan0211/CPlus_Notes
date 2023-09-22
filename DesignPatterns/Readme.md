
# c++ 设计模式

- [c++ 设计模式](#c-设计模式)
  - [设计模式的目标](#设计模式的目标)
  - [设计模式原则](#设计模式原则)
    - [1、依赖倒置原则（Dependence Inversion Principle，DIP）](#1依赖倒置原则dependence-inversion-principledip)
    - [2、开放封闭原则（OCP）](#2开放封闭原则ocp)
    - [3、单一职责原则（SRP）](#3单一职责原则srp)
    - [4、Liskov 替换原则（LSP）](#4liskov-替换原则lsp)
    - [5、接口隔离原则（ISP）](#5接口隔离原则isp)
    - [6、优先使用对象组合，而不是类继承](#6优先使用对象组合而不是类继承)
    - [7、封装变化点](#7封装变化点)
    - [8、针对接口编程，而不是针对实现编程](#8针对接口编程而不是针对实现编程)
    - [9、迪米特法则（Law Of Demter）](#9迪米特法则law-of-demter)
  - [23 种设计模式](#23-种设计模式)
    - [1、模板方法模式（Template Method Pattern）](#1模板方法模式template-method-pattern)
    - [2、策略模式（Strategy Pattern）](#2策略模式strategy-pattern)
    - [3、观察者模式（Observer Pattern）](#3观察者模式observer-pattern)
    - [4、装饰模式（Decorator Pattern）](#4装饰模式decorator-pattern)
    - [5、桥模式（Bridge Pattern）](#5桥模式bridge-pattern)
    - [6、工厂方法模式（Factory Method Pattern）](#6工厂方法模式factory-method-pattern)
    - [7、抽象工厂模式（Abstract Factory Pattern）](#7抽象工厂模式abstract-factory-pattern)
    - [8、构建器模式（Builder Pattern）](#8构建器模式builder-pattern)
    - [9、单例模式（Singleton Pattern）](#9单例模式singleton-pattern)
      - [单例模式存在的一些问题](#单例模式存在的一些问题)
    - [10、享元模式（Flyweight Pattern )](#10享元模式flyweight-pattern-)
    - [11、外观模式（Facade Pattern）---(门面模式)](#11外观模式facade-pattern---门面模式)
    - [12、代理模式（Proxy Pattern )  ---“接口隔离”模式—————解决耦合度太高的问题](#12代理模式proxy-pattern------接口隔离模式解决耦合度太高的问题)
    - [13、适配器模式（Adapter Pattern）-----接口隔离”模式——解决耦合度太高的问题](#13适配器模式adapter-pattern-----接口隔离模式解决耦合度太高的问题)
    - [14、中介者模式（Mediator Pattern） -----接口隔离”模式——解决耦合度太高的问题](#14中介者模式mediator-pattern------接口隔离模式解决耦合度太高的问题)
    - [14、中介者模式（Mediator Pattern） -----接口隔离”模式——解决耦合度太高的问题](#14中介者模式mediator-pattern------接口隔离模式解决耦合度太高的问题-1)

设计模式是通过抽象等方式提高代码复用，易于扩展，更好的应对开关过程中遇到的一些变化的程序设计模式
## 设计模式的目标   
- 松耦合思想     
- 设计原则   
- 重构   
- GOF设计模式    

## 设计模式原则

### 1、依赖倒置原则（Dependence Inversion Principle，DIP）
- 高层模块(稳定)不应该依赖于低层模块(变化)，二者都应该依赖于抽象(稳定) 。   
- 抽象(稳定)不应该依赖于实现细节(变化) ，实现细节应该依赖于抽象(稳定)。 

    #### 传统的自顶向下设计 
    传统设计方式采用自顶向下的原则， 逐级依赖，中层模块和高层模块的耦合度很高，如果需要修改其中的一个模块，则可能会导致其它很多模块也需要修改，牵一发动全身，不易于维护。 不使用依赖反转的系统构架，控制流和依赖关系流的依赖箭头是一个方向的，由高层指向底层，也就是高层依赖底层
    高层模块 ----> 中层模块 ------> 底层模块


    ### 依赖倒置原则的好处:
    - 减少类之间的耦合性，提高系统的稳定性。（根据类与类之间的耦合度从弱到强排列：依赖关系、关联关系、聚合关系、组合关系、泛化关系和实现关系）  
    - 降低并行开发引起的风险（两个类之间有依赖关系，只有指定两者之间的接口（或抽象类）就可以独立开发了）    
    - 提高代码的可读性和可维护性    
    高层模块 ----> 抽象层 <------ 底层模块



### 2、开放封闭原则（OCP）
对扩展开放和对修改关闭表示当一个类或一个方法有新需求或者需求发生改变时应该采用扩展的方式而不应该采用修改原有逻辑的方式来实现。因为扩展了新的逻辑如果有问题只会影响新的业务，不会影响老业务；而如果采用修改的方式，很有可能就会影响到老业务。 开闭原则是所有设计模式最核心目标，也是最难实现的目标，但是所有的软件设计模式都应该以开闭原则当作标准，才能使软件更加稳定和健壮。

- 对扩展开放，对更改封闭。  
- 类模块应该是可扩展的，但是不可修改。

**优点：**  
- 新老逻辑解藕，需求发生改变不会影响老业务的逻辑
- 改动成本最小，只需要追加新逻辑，不需要改的老逻辑
- 提供代码的稳定性和可扩展性



### 3、单一职责原则（SRP）
一个类或模块只完成一个职责（或功能）,单一职责原则的定义描述非常简单。一个类只负责完成一个职责或功能，也就是说在类的设计中，我们不要设计大而全的类，而是设计粒度小、功能单一的类。
- 一个类应该仅有一个引起它变化的原因。  
- 变化的方向隐含着类的责任。    

**如何判断一个类的职责是否单一？** (这里没有什么特别死的规则，都是从实际需求出发，代码是服务于需求的。但是也有一些侧面指标可以参考：)
* 类中的代码数、函数、属性非常多  
* 类依赖的其他类很多  
* 私有方法很多    
* 类中有大量的方法都是集中操作类中的几个属性  


### 4、Liskov 替换原则（LSP）
如果S是T的子类型，对于S类型的任意对象，如果将他们看作是T类型的对象，则对象的行为也理应与期望的行为一致。(子类对象能够替换程序中父类对象出现的任何地方，并且保证原来程序的逻辑行为不变及正确性不被破坏)

- 子类必须能够替换它们的基类(IS-A)。    
- 继承表达类型抽象。    

**什么是替换？**    
替换的前提是面向对象语言支持的多态特性，同一个行为具有多个不同表现形式或形态的能力。    

**么是与期望行为一致的替换？**  
在不了解派生类的情况下，仅通过接口或基类的方法，即可清楚的知道方法的行为，而不管哪种派生类的实现，都与接口或基类方法的期望行为一致。    

    不需要关心是哪个类对接口进行了实现,因为不管底层如何实现,最终的结果都会符合接口中关于方法的描述(也就是与接口中方法的期望行为一致). 或者说接口或基类的方法是一种契约，使用方按照这个契约来使用，派生类也按照这个契约来实现。这就是与期望行为一致的替换





### 5、接口隔离原则（ISP）   

接口隔离原则定义：客户端不应该被迫依赖于它不使用的方法 (该原则还有另一个定义：一个类对另一个类的依赖应该建立在最小的接口上) 

    通俗解释 : 要为各个类建立它们需要的专用接口，而不要试图去建立一个很庞大的接口供所有依赖它的类去调用

- 不应该强迫客户程序依赖它们不用的方法。    
- 接口应该小而完备。  

接口隔离原则于单一职责原则的区别 接口隔离原则和单一职责都是为了提高类的内聚性、降低它们之间的耦合性，体现了封装的思想，但两者不同的：

    单一职责原则注重的是职责，而接口隔离原则注重的是对接口依赖的隔离
    单一职责原则主要是约束类，它针对的是程序中的实现和细节；接口隔离原则主要约束接口，主要针对抽象和程序整体框架构建。

遵循接口隔离原则的优势

    将臃肿庞大的接口分解为多个粒度小的接口，可以预防外来变更的扩展，提高系统的灵活性和可维护性。使用多个专门的接口还能够体现对象的层次，因为可以通过接口的继承，实现对总接口的定义。能够减少项目工程的代码冗余。过大的大接口里面通常放置许多不用的方法，当实现这个接口的时候，被迫设计冗余代码。


### 6、优先使用对象组合，而不是类继承


- 类继承通常为“白箱复用”，对象组合通常为“黑箱复用”。    
- 继承在某种程度上破坏了封装性，子类父类耦合度高。  
- 而对象组合则只要求被组合的对象具有良好定义的接口，耦合度低。



### 7、封装变化点
- 使用封装来创建对象之间的分界层，让设计者可以在分界层的一侧进行修改，而不会对另一侧产生不良的影响，从而实现层次间的松耦合。


### 8、针对接口编程，而不是针对实现编程
- 不将变量类型声明为某个特定的具体类，而是声明为某个接口。  
- 客户程序无需获知对象的具体类型，只需要知道对象所具有的接口。  
- 减少系统中各部分的依赖关系，从而实现“高内聚、松耦合”的类型设计方案。

### 9、迪米特法则（Law Of Demter）
迪米特法则又叫最少知识原则，指的是一个类/模块对其他的类/模块有越少的了解越好。简单来说就是：只和最亲密的朋友交往，不和陌生人来往。

**迪米特思想就是：不该有直接依赖关系的类之间，不要有依赖；有依赖关系的类之间，尽量只依赖必要的接口**

    如果两个软件实体无需直接通信，那么就不应当发生直接的互相调用，可以通过第三方转发该调用。其目的是降低类之间的耦合度，提高模块的相对独立性。

    迪米特法则的独特之处在于它简洁而准确的定义，它允许在编写代码时直接应用，几乎自动地应用量适当的封装、高内聚和低耦合。 但是，过度使用迪米特法则则会使系统产生大量的中介类，从而增加系统的负责性，使模块之间的通信效率降低。所以，在采用迪米特法则时需要反复权衡，确保高内聚和低耦合的同时，保证系统结构清晰。


## 23 种设计模式

### 1、模板方法模式（Template Method Pattern）  

模板方法模式（Template Method Pattern）是一种行为型模式，它允许你定义一个算法的骨架，但将一些步骤的具体实现留给子类。这个模式通过定义一个模板方法，该方法包含了算法的主要步骤，然后由子类提供或覆盖某些步骤的具体实现。

    定义一个操作中的算法的骨架 (稳定)，而将一些步骤延迟(变化)到子类中。Template Method使得子类可以不改变(复用)一个算法的结构即可重定义(override 重写)该算法的某些特定步骤。

以下是模板方法模式的一些关键要点：

     模板方法（Template Method）：这是定义算法的骨架的方法，它包含一个序列的步骤，这些步骤可以是抽象的或具体的。这些步骤中的某些步骤可以在模板方法中具体实现，而其他步骤则由子类来实现。

    抽象方法（Abstract Methods）：这些方法在模板方法中声明但没有具体实现。子类必须提供这些方法的具体实现，以使模板方法能够工作。

    钩子方法（Hooks）：这些是在模板方法中声明的方法，但它们的实现是可选的。子类可以选择覆盖这些方法，以改变算法的行为，或者可以使用默认实现。

```c++
#include <iostream>
class AbstractClass {
public:
    // 模板方法，定义了算法的骨架
    void templateMethod() {
        // 这是算法的步骤1
        step1();
        
        // 这是算法的步骤2
        step2();
        
        // 这是算法的步骤3
        step3();
    }

    // 抽象方法，子类必须提供具体实现
    virtual void step1() = 0;
    virtual void step2() = 0;

    // 钩子方法，子类可以选择覆盖
    virtual void step3() {
        std::cout << "Default implementation of step3" << std::endl;
    }
};

class ConcreteClass : public AbstractClass {
public:
    void step1() override {
        std::cout << "ConcreteClass: Step 1" << std::endl;
    }

    void step2() override {
        std::cout << "ConcreteClass: Step 2" << std::endl;
    }

    void step3() override {
        std::cout << "ConcreteClass: Custom implementation of Step 3" << std::endl;
    }
};

int main() {
    AbstractClass* abstractObject = new ConcreteClass();
    abstractObject->templateMethod();

    delete abstractObject;
    
    return 0;
}
```

### 2、策略模式（Strategy Pattern）
策略模式（Strategy Pattern）是一种行为型设计模式，它允许在运行时选择算法的行为。策略模式将算法独立于其使用者，并通过将不同的算法封装在各自的策略类中，使得这些算法可以互相替换，而不会影响到使用它们的代码。这种模式促使开放-封闭原则的实现，允许在不修改现有代码的情况下添加新的算法。
    定义一系列算法，把它们一个个封装起来，并且使它们可互相替换（变化）。该模式使得算法可独立于使用它的客户程序(稳定)而变化（扩展，子类化）。——《设计模式》GoF

**以下是策略模式的关键要点：**

    策略接口（Strategy Interface）：这是一个定义算法策略的接口或抽象类。通常，策略接口中会声明一个或多个方法，这些方法用于执行算法的不同部分。

    具体策略（Concrete Strategies）：这是实现策略接口的具体类，每个具体策略类都代表一个不同的算法或策略。它们实现了策略接口中定义的方法，以提供算法的具体实现。

    上下文（Context）：上下文类包含一个成员变量，它是一个策略接口类型的引用。上下文类可以在运行时设置或切换不同的策略，以改变其行为。

```c++ 
#include <iostream>

// 策略接口
class Strategy {
public:
    virtual void execute() = 0;
};

// 具体策略1
class ConcreteStrategy1 : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy 1" << std::endl;
    }
};

// 具体策略2
class ConcreteStrategy2 : public Strategy {
public:
    void execute() override {
        std::cout << "Executing Strategy 2" << std::endl;
    }
};

// 上下文类
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strat) : strategy(strat) {}

    void setStrategy(Strategy* strat) {
        strategy = strat;
    }

    void executeStrategy() {
        strategy->execute();
    }
};

int main() {
    ConcreteStrategy1 strategy1;
    ConcreteStrategy2 strategy2;

    Context context(&strategy1);
    context.executeStrategy();

    context.setStrategy(&strategy2);
    context.executeStrategy();

    return 0;
}
```
在这个示例中，我们定义了一个 Strategy 接口，其中包含一个 execute 方法。然后，我们创建了两个具体策略类 ConcreteStrategy1 和 ConcreteStrategy2，它们分别实现了 execute 方法以提供不同的算法实现。

Context 类代表上下文，在构造函数中接受一个策略对象，并提供了设置和执行策略的方法。在 main 函数中，我们创建了两个具体策略对象，并使用 Context 类来执行它们。这允许我们在运行时切换不同的策略，而不需要修改上下文中的代码。

策略模式有助于提高代码的可维护性和灵活性，因为它允许添加新的策略或修改现有策略而不会影响到客户端代码。它通常在需要多个算法互相替换的情况下使用，例如排序算法、计算算法等。


### 3、观察者模式（Observer Pattern）
观察者模式（Observer Pattern）是一种行为型设计模式，用于定义对象之间的一对多依赖关系，使得当一个对象的状态发生变化时，所有依赖于它的对象都能够自动得到通知并更新。这种模式中，被观察的对象称为主题（Subject），而依赖于主题状态变化的对象称为观察者（Observer）。观察者模式有助于实现松耦合（Loose Coupling）的设计，其中主题和观察者可以独立演化而不互相影响。
**"动机"**

    在软件构建过程中，我们需要为某些对象建立一种“通知依赖关系” ——一个对象（目标对象）的状态发生改变，所有的依赖对象（观察者对象）都将得到通知。如果这样的依赖关系过于紧密，将使软件不能很好地抵御变化。]

**观察者模式的结构图如下所示：**

    +---------------------+     +---------------------+
    |      Subject        |     |       Observer      |
    +---------------------+     +---------------------+
    | + addObserver()     |     | + update()          |
    | + removeObserver()  |     +---------------------+
    | + notifyObservers() |             / \
    +---------------------+              |
             /|\                         |
              |                          |
              |                          |
              |                          |
    +---------------------+     +---------------------+
    |  ConcreteSubject   |     |  ConcreteObserver   |
    +---------------------+     +---------------------+
    | + setState()       |     | + update()          |
    +---------------------+     +---------------------+

在上面的结构图中，有以下关键元素：

    Subject（主题）：它是一个抽象类或接口，定义了添加、删除和通知观察者的方法。具体的主题类将实现这些方法，并维护观察者的列表。

    ConcreteSubject（具体主题）：它是具体的主题类，实现了主题接口。它维护了一个观察者列表，并在状态变化时通知观察者。

    Observer（观察者）：它是一个抽象类或接口，定义了更新方法，用于在主题状态变化时被观察者调用。具体的观察者类将实现这个方法。

    ConcreteObserver（具体观察者）：它是具体的观察者类，实现了观察者接口的更新方法。它会接收主题的通知并执行相应的操作。

    观察者模式的关键思想是主题和观察者之间的松耦合。主题知道有一组观察者，但不需要知道它们的具体类别或行为。观察者可以独立地订阅或取消订阅主题，并在主题状态变化时自动接收通知和执行操作。这使得系统更具灵活性和可扩展性。

**以下是观察者模式的关键要点：**

    主题（Subject）：主题是被观察的对象，它维护一组观察者，并在自身状态发生变化时通知观察者。主题通常提供方法来添加、删除和通知观察者。

    观察者（Observer）：观察者是依赖于主题状态变化的对象。它们实现了一个更新方法，以在主题状态发生变化时被调用，从而执行相应的操作。

    具体主题（Concrete Subject）：具体主题是主题的具体实现，它维护了状态并在状态变化时通知观察者。

    具体观察者（Concrete Observer）：具体观察者是观察者的具体实现，它实现了更新方法以响应主题的通知。

```c++
#include <iostream>
#include <vector>

// 观察者接口
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// 具体观察者
class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& n) : name(n) {}

    void update(const std::string& message) override {
        std::cout << name << " received message: " << message << std::endl;
    }
};

// 主题接口
class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& message) = 0;
};

// 具体主题
class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyObservers(const std::string& message) override {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }

    void setState(const std::string& message) {
        std::cout << "State changed to: " << message << std::endl;
        notifyObservers(message);
    }
};

int main() {
    ConcreteSubject subject;

    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.setState("New state 1");
    
    subject.removeObserver(&observer1);
    
    subject.setState("New state 2");

    return 0;
}
```
    在这个示例中，我们定义了一个 Subject 接口和一个 Observer 接口，分别用于主题和观察者的抽象。然后，我们创建了具体的主题类 ConcreteSubject 和具体的观察者类 ConcreteObserver，并实现了相应的方法。

    在 main 函数中，我们创建了一个具体主题对象 subject 和两个具体观察者对象 observer1 和 observer2。我们通过 addObserver 方法将观察者添加到主题的观察者列表中，然后通过 setState 方法改变主题的状态，从而通知观察者。观察者收到通知后，执行其 update 方法来响应状态变化。

    观察者模式有助于实现松耦合的设计，其中主题和观察者相互独立，可以轻松添加或删除观察者而不影响主题或其他观察者。这使得它非常适用于需要在对象之间建立动态依赖关系的场景，例如事件处理系统或图形用户界面框架。

### 4、装饰模式（Decorator Pattern）
装饰模式（Decorator Pattern）是一种结构型设计模式，它允许你在不改变对象接口的情况下，动态地将新行为附加到对象上。这个模式以一种透明的方式来扩展对象的功能，同时保持对象的接口不变。

装饰模式通过将装饰器类包装在具体组件类周围，以添加新功能，实现了 ***开放-封闭原则*** ，允许你在不修改现有代码的情况下添加新的功能。

**动机**        
在某些情况下我们可能会“过度地使用继承来扩展对象的功能”，由于继承为类型引入的静态特质，使得这种扩展方式缺乏灵活性；并且随着子类的增多（扩展功能的增多），各种子类的组合（扩展功能的组合）会导致更多子类的膨胀。


**以下是装饰模式的关键要点：**      

- 组件接口（Component Interface）：这是抽象组件类或接口，定义了具体组件和装饰器都必须实现的方法。通常包括了一些核心的操作。
- 具体组件（Concrete Component）：这是实现组件接口的具体类，它是被装饰的对象，可以添加功能的基础。
- 装饰器（Decorator）：这是实现组件接口并持有一个组件对象的抽象类。装饰器可以添加新的行为或修改组件的行为，但不改变组件的接口。
- 具体装饰器（Concrete Decorator）：这是具体的装饰器类，扩展了装饰器抽象类并实现了新的功能或修改了组件的行为。
```c++
#include <iostream>

// 组件接口
class Coffee {
public:
    virtual void brew() = 0;
};

// 具体组件
class SimpleCoffee : public Coffee {
public:
    void brew() override {
        std::cout << "Brewing a simple coffee" << std::endl;
    }
};

// 装饰器抽象类
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}

    void brew() override {
        coffee->brew();
    }
};

// 具体装饰器1
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    void brew() override {
        CoffeeDecorator::brew();
        addMilk();
    }

    void addMilk() {
        std::cout << "Adding milk to the coffee" << std::endl;
    }
};

// 具体装饰器2
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    void brew() override {
        CoffeeDecorator::brew();
        addSugar();
    }

    void addSugar() {
        std::cout << "Adding sugar to the coffee" << std::endl;
    }
};

int main() {
    Coffee* coffee = new SimpleCoffee();
    coffee->brew();

    Coffee* milkCoffee = new MilkDecorator(new SimpleCoffee());
    milkCoffee->brew();

    Coffee* sugarMilkCoffee = new SugarDecorator(new MilkDecorator(new SimpleCoffee()));
    sugarMilkCoffee->brew();

    delete coffee;
    delete milkCoffee;
    delete sugarMilkCoffee;

    return 0;
}
```

    在这个示例中，我们有一个 Coffee 接口，以及一个具体组件 SimpleCoffee，它实现了 brew() 方法，用于简单的咖啡冲泡。 

    然后，我们定义了装饰器抽象类 CoffeeDecorator，它也实现了 brew() 方法，但它持有一个 Coffee 对象，以便在调用 brew() 时能够委托给具体组件。

    接着，我们创建了两个具体装饰器类 MilkDecorator 和 SugarDecorator，它们分别添加牛奶和糖到咖啡中，并在 brew() 方法中调用相应的方法。

    在 main 函数中，我们演示了如何使用装饰器来动态扩展咖啡的功能。你可以看到，通过将装饰器堆叠在一起，我们可以根据需要组合不同的功能，而不改变组件的接口。这是装饰模式的核心思想。

- **要点总结**  
    通过采用组合而非继承的手法， Decorator模式实现了在运行时 动态扩展对象功能的能力，而且可以根据需要扩展多个功能。避免 了使用继承带来的“灵活性差”和“多子类衍生问题”。
    
    Decorator类在接口上表现为is-a Component的继承关系，即 Decorator类继承了Component类所具有的接口。但在实现上又 表现为has-a Component的组合关系，即Decorator类又使用了 另外一个Component类。
    
    Decorator模式的目的并非解决“多子类衍生的多继承”问题， Decorator模式应用的要点在于解决“主体类在多个方向上的扩展 功能”——是为“装饰”的含义。



### 5、桥模式（Bridge Pattern）
桥模式（Bridge Pattern）是一种结构型设计模式，它将一个对象的抽象部分与其实现部分分离，使它们可以独立地变化。这种模式通过将对象的功能和实现分开，以实现松耦合，从而提高系统的可维护性和扩展性。

桥模式的核心思想是使用组合而不是继承来分离抽象和实现。它在设计中使用两个层次结构，一个抽象层次结构和一个实现层次结构。抽象层次结构包括一个抽象类，它定义了抽象部分的接口，而实现层次结构包括一个或多个实现类，它们提供了接口的具体实现。

**以下是桥模式的关键要点：**    

- 抽象类或接口（Abstraction）：这是抽象部分的定义，它包含一个对实现对象的引用，并定义了一组抽象方法，这些方法委托给实现对象。抽象类可以包含一些特定于抽象部分的方法。

- 具体类（Concrete Abstraction）：这是抽象类的具体实现，它继承自抽象类并实现了抽象方法，以便委托给实现对象。

- 实现接口（Implementor）：这是实现部分的接口，它定义了实现对象的方法。

- 具体实现类（Concrete Implementor）：这是实现接口的具体实现，它提供了实现对象的具体功能。

```C++
#include <iostream>

// 实现接口
class Implementor {
public:
    virtual void operationImpl() = 0;
};

// 具体实现类 A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor A" << std::endl;
    }
};

// 具体实现类 B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        std::cout << "Concrete Implementor B" << std::endl;
    }
};

// 抽象类
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual void operation() = 0;
};

// 具体抽象类 1
class ConcreteAbstraction1 : public Abstraction {
public:
    ConcreteAbstraction1(Implementor* impl) : Abstraction(impl) {}

    void operation() override {
        std::cout << "Concrete Abstraction 1 - ";
        implementor->operationImpl();
    }
};

// 具体抽象类 2
class ConcreteAbstraction2 : public Abstraction {
public:
    ConcreteAbstraction2(Implementor* impl) : Abstraction(impl) {}

    void operation() override {
        std::cout << "Concrete Abstraction 2 - ";
        implementor->operationImpl();
    }
};

int main() {
    Implementor* implA = new ConcreteImplementorA();
    Implementor* implB = new ConcreteImplementorB();

    Abstraction* abs1 = new ConcreteAbstraction1(implA);
    Abstraction* abs2 = new ConcreteAbstraction2(implB);

    abs1->operation();
    abs2->operation();

    delete implA;
    delete implB;
    delete abs1;
    delete abs2;

    return 0;
}
// 在这个示例中，我们有一个实现接口 Implementor，其中包含了 operationImpl() 方法。然后，我们创建了两个具体的实现类 ConcreteImplementorA 和 ConcreteImplementorB，它们分别提供了实现的不同功能。

// 接着，我们定义了抽象类 Abstraction，它包含一个对实现对象的引用，并定义了一个抽象方法 operation()，该方法委托给实现对象的 operationImpl() 方法。我们创建了两个具体的抽象类 ConcreteAbstraction1 和 ConcreteAbstraction2，它们分别与不同的实现对象关联。

// 在 main 函数中，我们创建了实现对象和抽象对象，并演示了如何使用桥模式来分离抽象和实现，从而能够动态地选择不同的实现。这种分离允许我们扩展系统的功能，同时保持高度的灵活性。
```


### 6、工厂方法模式（Factory Method Pattern）
工厂方法模式（Factory Method Pattern）是一种创建型设计模式，它提供了一种创建对象的接口，但将对象的实际创建过程委托给子类。这样可以使一个类的实例化延迟到其子类，从而允许子类决定创建的对象类型。

工厂方法模式通常涉及两个层次结构：一个是抽象产品（Abstract Product）层，其中定义了产品的接口；另一个是具体产品（Concrete Product）层，其中实现了具体的产品。

    定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method使得一个类的实例化延迟（目的：解耦，手段：虚函数）到子类.


**以下是工厂方法模式的关键要点：**  

- 抽象产品（Abstract Product）：这是产品的抽象接口，定义了产品的通用方法。

- 具体产品（Concrete Product）：这是实现抽象产品接口的具体类，它表示真正的产品。

- 抽象工厂（Abstract Factory）：这是创建产品的抽象接口，通常包括一个创建产品的方法（工厂方法）。

- 具体工厂（Concrete Factory）：这是实现抽象工厂接口的具体类，它负责创建具体产品的实例。

```C++
#include <iostream>

// 抽象产品
class Product {
public:
    virtual void use() = 0;
};

// 具体产品 A
class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using Concrete Product A" << std::endl;
    }
};

// 具体产品 B
class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using Concrete Product B" << std::endl;
    }
};

// 抽象工厂
class Factory {
public:
    virtual Product* createProduct() = 0;
};

// 具体工厂 A
class ConcreteFactoryA : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

// 具体工厂 B
class ConcreteFactoryB : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};

int main() {
    Factory* factoryA = new ConcreteFactoryA();
    Product* productA = factoryA->createProduct();
    productA->use();

    Factory* factoryB = new ConcreteFactoryB();
    Product* productB = factoryB->createProduct();
    productB->use();

    delete factoryA;
    delete productA;
    delete factoryB;
    delete productB;

    return 0;
}
// 在这个示例中，我们有抽象产品 Product，其中定义了一个 use() 方法。然后，我们创建了两个具体产品 ConcreteProductA 和 ConcreteProductB，它们分别实现了 Product 接口。

// 接着，我们定义了抽象工厂 Factory，其中包括一个纯虚的 createProduct() 方法，该方法由具体工厂实现以创建具体产品的实例。

// 我们创建了两个具体工厂 ConcreteFactoryA 和 ConcreteFactoryB，它们分别实现了 createProduct() 方法来创建不同的产品。

// 在 main 函数中，我们演示了如何使用工厂方法模式来创建产品。根据所选的工厂，我们可以动态地创建不同类型的产品，而无需直接实例化具体产品类。这种模式有助于实现对象的创建与使用的解耦。
```
  



### 7、抽象工厂模式（Abstract Factory Pattern）

抽象工厂模式（Abstract Factory Pattern）是一种创建型设计模式，它提供了一个接口，用于创建相关或依赖对象的家族，而无需指定它们的具体类。抽象工厂允许你创建一组对象，这些对象之间具有相互关联的特性，并且与具体实现无关。

抽象工厂模式通常包括两个层次结构：一个是抽象产品（Abstract Product）层，定义了产品的接口；另一个是抽象工厂（Abstract Factory）层，定义了用于创建产品家族的接口。


**以下是抽象工厂模式的关键要点：**

- 抽象产品（Abstract Product）：这是产品的抽象接口，定义了产品家族的通用方法。

- 具体产品（Concrete Product）：这是实现抽象产品接口的具体类，它表示真正的产品。

- 抽象工厂（Abstract Factory）：这是创建产品家族的抽象接口，通常包括一组创建产品的方法。

- 具体工厂（Concrete Factory）：这是实现抽象工厂接口的具体类，它负责创建产品家族的具体实例。

```c++
#include <iostream>

// 抽象产品 A
class AbstractProductA {
public:
    virtual void useA() = 0;
};

// 具体产品 A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void useA() override {
        std::cout << "Using Concrete Product A1" << std::endl;
    }
};

// 具体产品 A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void useA() override {
        std::cout << "Using Concrete Product A2" << std::endl;
    }
};

// 抽象产品 B
class AbstractProductB {
public:
    virtual void useB() = 0;
};

// 具体产品 B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void useB() override {
        std::cout << "Using Concrete Product B1" << std::endl;
    }
};

// 具体产品 B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void useB() override {
        std::cout << "Using Concrete Product B2" << std::endl;
    }
};

// 抽象工厂
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// 具体工厂 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

// 具体工厂 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();

    productA1->useA();
    productB1->useB();

    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();

    productA2->useA();
    productB2->useB();

    delete factory1;
    delete productA1;
    delete productB1;

    delete factory2;
    delete productA2;
    delete productB2;

    return 0;
}
// 在这个示例中，我们有两个抽象产品 AbstractProductA 和 AbstractProductB，它们定义了产品家族的接口。然后，我们创建了四个具体产品类，分别是 ConcreteProductA1、ConcreteProductA2、ConcreteProductB1 和 ConcreteProductB2，它们实现了抽象产品的接口。

// 接着，我们定义了抽象工厂 AbstractFactory，其中包括一组创建产品的方法。我们创建了两个具体工厂类 ConcreteFactory1 和 ConcreteFactory2，它们分别实现了抽象工厂接口的方法以创建不同类型的产品。

// 在 main 函数中，我们演示了如何使用抽象工厂模式来创建产品家族。根据所选的工厂，我们可以动态地创建不同类型的产品，而无需直接实例化具体产品类。这种模式有助于实现对象的创建与使用的解耦，并且支持创建一组相关的对象。
```

### 8、构建器模式（Builder Pattern）

构建器模式（Builder Pattern）是一种创建型设计模式，它用于创建一个复杂对象，同时允许你设置其各个部分的属性和内容。构建器模式的核心思想是将一个对象的构建过程（稳定）与创建不同的表示（变化）分离，以便可以创建不同表示的对象。

    “对象创建”模式——绕开new，来避免对象创建（new）过程中所导致的紧耦合（依赖具体类），从而支持对象创建的稳定。它是接口抽象之后的第一步工作。

构建器模式通常包括以下关键组件：

1. 产品类（Product）：表示要构建的复杂对象，它通常包含多个部分或属性。

2. 抽象构建器类（Builder）：定义了构建产品各个部分的抽象方法，以及一个获取最终产品的方法。

3. 具体构建器类（Concrete Builder）：实现了抽象构建器类，负责构建产品的各个部分，并提供方法来设置这些部分的属性。

4. 指挥者类（Director）：负责协调构建者以构建产品。它不直接创建产品，而是通过构建器来完成。
Z
5. 客户端（Client）：使用指挥者来创建产品的类。客户端通常不需要知道产品的具体构建细节。  


以下是一个简单的C++示例，演示了构建器模式的实现：

```C++
#include <iostream>
#include <string>

// 产品类
class Product {
public:
    void setPartA(const std::string& partA) {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) {
        partB_ = partB;
    }

    void setPartC(const std::string& partC) {
        partC_ = partC;
    }

    void show() {
        std::cout << "Part A: " << partA_ << std::endl;
        std::cout << "Part B: " << partB_ << std::endl;
        std::cout << "Part C: " << partC_ << std::endl;
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};

// 抽象构建器类
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product getResult() = 0;
};

// 具体构建器类
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() {
        product_ = new Product();
    }

    void buildPartA() override {
        product_->setPartA("Part A");
    }

    void buildPartB() override {
        product_->setPartB("Part B");
    }

    void buildPartC() override {
        product_->setPartC("Part C");
    }

    Product getResult() override {
        return *product_;
    }

private:
    Product* product_;
};

// 指挥者类
class Director {
public:
    Product construct() {
        builder_->buildPartA();
        builder_->buildPartB();
        builder_->buildPartC();
        return builder_->getResult();
    }

    void setBuilder(Builder* builder) {
        builder_ = builder;
    }

private:
    Builder* builder_;
};

int main() {
    ConcreteBuilder builder;
    Director director;
    director.setBuilder(&builder);

    Product product = director.construct();
    product.show();

    return 0;
}

//在这个示例中，我们有以下关键要点：

// Product 是要构建的复杂对象，它包含了多个部分（Part A、Part B 和 Part C）的属性。

// Builder 是抽象构建器类，定义了构建产品各个部分的抽象方法以及获取最终产品的方法。

// ConcreteBuilder 是具体构建器类，实现了抽象构建器类的方法，并负责构建产品的各个部分。

// Director 是指挥者类，负责协调构建器来构建产品。客户端通过指挥者来创建产品，而不需要直接与构建器交互。

// 在 main 函数中，我们创建了一个具体构建器 ConcreteBuilder 和一个指挥者 Director。通过指挥者，我们构建了一个产品，并通过 show() 方法展示了产品的各个部分。

// 构建器模式的优点是能够构建复杂的对象，并且可以根据需要定制对象的部分属性。这有助于将构建细节与
```




### 9、单例模式（Singleton Pattern）

单例模式（Singleton Pattern）是一种创建型设计模式，用于确保一个类只有一个实例，并提供一种全局访问点来访问该实例。这对于需要在整个应用程序中共享某个资源的情况非常有用，例如配置信息、日志记录器、数据库连接等。

单例模式的关键思想是通过私有化构造函数，禁止外部直接创建对象实例，然后提供一个静态方法或者静态成员变量，用于获取或创建唯一的实例。
```C++
#include <iostream>

class Singleton {
public:
    // 获取单例实例的静态方法
    static Singleton& getInstance() {
        static Singleton instance; // 使用局部静态变量确保仅在首次调用时创建实例
        return instance;
    }

    // 示例方法
    void showMessage() {
        std::cout << "Hello from Singleton!" << std::endl;
    }

    // 防止拷贝构造和赋值操作
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // 私有构造函数，禁止外部创建实例
    Singleton() {}

    // 私有析构函数，禁止外部销毁实例
    ~Singleton() {}
};

int main() {
    Singleton& instance1 = Singleton::getInstance();
    instance1.showMessage();

    Singleton& instance2 = Singleton::getInstance();
    instance2.showMessage();

    // 两个实例应该是同一个对象，因此它们的地址相同
    if (&instance1 == &instance2) {
        std::cout << "Both instances are the same." << std::endl;
    } else {
        std::cout << "Instances are different." << std::endl;
    }

    return 0;
}
// 在这个示例中，我们定义了一个 Singleton 类，其中包括以下关键要点：

// 私有的构造函数和析构函数，以防止外部创建和销毁实例。
// 静态方法 getInstance()，用于获取单例实例。在这个方法中，我们使用了局部静态变量来确保只有在首次调用时创建实例，以避免多线程问题。
// 示例方法 showMessage()，用于演示单例的功能。
// 删除拷贝构造函数和赋值操作符，以防止通过拷贝方式创建多个实例。
// 在 main 函数中，我们通过 Singleton::getInstance() 获取单例实例，并演示了两个实例是否相同的比较。根据单例模式的定义，两个实例应该是相同的，因此它们的地址相同。

// 单例模式适用于需要确保全局唯一性的情况，但请注意，过度使用单例模式可能会导致全局状态的问题，因此应该谨慎使用。
```
#### 单例模式存在的一些问题
例如以下代码：
```C++
#include <iostream>
using namespace std;

class Singleton {
// 构造函数声明私有，否则外部也可以构建
private:
    Singleton();
    Singleton(const Singleton &other);
public:
    static Singleton *getInstance();
    static Singleton *m_instance;
};

// 线程非安全版本
Singleton *Singleton::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}
```
在多线程中：线程A和线程B先后执行if (m_instance == nullptr)，但是此时线程A未创建完毕，线程B判空，线程B依然执行创建工作。结果为创建了2个实例，线程不安全。
- 版本2：
```C++ 
// 线程安全版本，但是锁的代价较高
Singleton *Singleton::getInstance() {
    Lock lock;
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}
```
存在的问题是：线程A创建时，直接加锁，线程B无法访问，直到线程A创建完毕，成功创建实例，线程B访问时，指针不为空，确保只有一个实例。问题是，对m_instance的操作是读操作，而非写操作，于是加锁导致了大量的性能下降，在高并发（例如web服务器）的情况下，会导致时间开销过大。       
- 版本3：
```C++
// 双检查锁，但是内存读取reorder不安全
Singleton *Singleton::getInstance() {
    if (m_instance == nullptr) {
        Lock lock;
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
    }
    return m_instance;
}
```
分析：双检查锁，在读取m_instance时不加锁，保证线程A和线程B都可以读取。而假设A读取为空后，便直接加锁，从而进行实例的创建工作。线程B如果在锁前判断非空，则直接返回实例，如果在锁后判断非空，则依旧不重复创建，返回实例，保证了正确性。

为什么锁后还要进行一次检查？保证正确性。如果去掉，则线程A和线程B同时进入条件中，线程A加锁创建完毕，线程B没有发现此时指针不为空，继续创建实例导致重复。

为什么锁前还要进行一次检查？避免都是读操作带来的时间开销，退化为上一个版本。

为什么内存读写reorder不安全？首先引入时间片的概念：同一个CPU永远不可能真正地同时运行多个任务。在只考虑一个CPU的情况下，这些进程“看起来像”同时运行的，实则是轮番穿插地运行。

复习一下创建对象的三步：分配内存、创建对象、返回指针。但是这只是代码层面的步骤，实际上，在编译成为指令之后，编译器有自己的想法（例如编译器优化），而指令就会发生reorder的情况，将创建对象的三步变成为：分配内存、返回指针、创建对象。而返回指针之后，指针不为空，但实际上之后内存没有构造过程；对于线程B而言，得到了不为空的指针，却返回了错误的结果，所以即便是加锁，代码依然有问题风险。
- 版本4：
```C++
// C++11，使用原子操作
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton *Singleton::getInstance() {
    // tmp不会被reorder
    Singleton *tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire); // 获取内存fence

    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release); // 释放内存fence
            m_instance.store(std::memory_order_relaxed);
        }
    }
    return tmp;
}
```
分析：2005年微软首先给出了volatile关键字，而C++也在C++11引入了解决方案，其他语言也有不同的实现。

绕过new，即绕过常规构造器，而确保一种独特的机制（只创建一个）构造对象

**总结**    

实例构造器可以声明为protected允许子类派生

Singleton一般不支持拷贝构造函数和Clone接口，有可能导致多个对象的实例，与模式初衷相违背

注意双检查锁

### 10、享元模式（Flyweight Pattern )
享元模式（Flyweight Pattern）是一种结构型设计模式，旨在最小化对象的内存使用或计算成本，同时分享尽可能多的相似对象。它适用于具有大量相似对象的情况，以减少内存占用和提高性能。

享元模式的核心思想是将对象分为两个部分：内部状态（Intrinsic State）和外部状态（Extrinsic State）。

软件系统中采用纯粹的对象方案，大量细粒度的对象会带来很高的运行时代价，内存需求待优化；例如线程池，也是一种共享机制的优化

```c++
#include <iostream>
#include <unordered_map>

// 享元接口
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) = 0;
};

// 具体享元
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState; // 内部状态

public:
    ConcreteFlyweight(const std::string& intrinsic) : intrinsicState(intrinsic) {}

    void operation(const std::string& extrinsicState) override {
        std::cout << "Intrinsic State: " << intrinsicState << ", Extrinsic State: " << extrinsicState << std::endl;
    }
};

// 享元工厂
class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight*> flyweights; // 享元对象池

public:
    Flyweight* getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }
};

int main() {
    FlyweightFactory factory;
    Flyweight* fw1 = factory.getFlyweight("A");
    Flyweight* fw2 = factory.getFlyweight("B");
    Flyweight* fw3 = factory.getFlyweight("A"); // 重复使用相同的享元对象

    fw1->operation("X");
    fw2->operation("Y");
    fw3->operation("Z");

    delete fw1;
    delete fw2;
    delete fw3;

    return 0;
}
// 在这个示例中，我们有以下关键要点：

// Flyweight 是享元接口，定义了一个 operation() 方法，该方法接受外部状态作为参数。

// ConcreteFlyweight 是具体享元类，包含内部状态 intrinsicState，并实现了 operation() 方法以打印内部和外部状态。

// FlyweightFactory 是享元工厂，负责管理和提供享元对象。它使用一个哈希表（unordered_map）来存储已创建的享元对象，确保相同的内部状态只有一个对象。

// 在 main 函数中，我们创建了一个享元工厂，并获取了三个享元对象：A、B 和另一个A。尽管有两个外部状态不同的请求使用了相同的享元对象（A），但它们共享相同的内部状态。这可以减少内存占用。
```

享元模式的关键是在需要共享对象时使用享元工厂，确保尽可能多地共享相似对象，从而降低内存和性能开销。这对于大量相似对象的情况非常有用，如文本编辑器中的字符或游戏中的粒子。


### 11、外观模式（Facade Pattern）---(门面模式)

外观模式（Facade Pattern）是一种结构型设计模式，旨在为一个复杂子系统提供一个简化的接口，从而使客户端更容易使用该子系统。外观模式充当了客户端与子系统之间的中介，隐藏了子系统的复杂性，提供了一个高层接口，使客户端更容易调用子系统的功能。

外观模式的关键思想是引入一个外观类（Facade Class），它包含了子系统的一组接口方法，并提供了一个统一的入口点，使客户端可以通过调用外观类的方法来访问子系统的功能，而不需要了解子系统的内部工作。


1. 以下是一个简单的C++示例，演示了外观模式的实现：
```C++
   #include <iostream>

// 子系统类 A
class SubsystemA {
public:
    void operationA() {
        std::cout << "Subsystem A operation" << std::endl;
    }
};

// 子系统类 B
class SubsystemB {
public:
    void operationB() {
        std::cout << "Subsystem B operation" << std::endl;
    }
};

// 子系统类 C
class SubsystemC {
public:
    void operationC() {
        std::cout << "Subsystem C operation" << std::endl;
    }
};

// 外观类
class Facade {
private:
    SubsystemA subsystemA;
    SubsystemB subsystemB;
    SubsystemC subsystemC;

public:
    Facade() {
        // 在外观类的构造函数中初始化子系统对象
    }

    void operation() {
        // 外观类将客户端请求委派给子系统
        subsystemA.operationA();
        subsystemB.operationB();
        subsystemC.operationC();
    }
};

int main() {
    // 客户端代码只需要与外观类交互
    Facade facade;
    facade.operation();

    return 0;
}

// 在这个示例中，我们有以下关键要点：

// SubsystemA、SubsystemB 和 SubsystemC 分别代表子系统的一部分，每个子系统具有自己的操作。

// Facade 是外观类，它组合了这些子系统，并提供了一个统一的接口 operation()，客户端只需要与外观类交互。

// 在 main 函数中，我们创建了一个外观对象 facade，并通过它来调用子系统的操作。客户端代码不需要了解子系统的复杂性，只需要调用外观类的方法即可。

// 外观模式有助于减少客户端与子系统之间的耦合，提高了代码的可维护性和可读性。
// 它还允许你将子系统的实现细节隐藏起来，从而降低了对子系统的直接访问。这在需要将复杂性封装起来的情况下非常有用。
// 外观模式也常用于库或框架中，以提供简化的接口供用户使用。

```


2. **总结**

从客户角度看，门面模式简化了一整个组件系统的接口，内部的变化不会影响到门面接口的变化
更注重从架构的层次去看整个系统，而不是单个的层次，更像一种架构设计模式
并不是一个集装箱，任意放入任意对象，而是耦合度比较大的一系列组件

### 12、代理模式（Proxy Pattern )  ---“接口隔离”模式—————解决耦合度太高的问题

代理模式（Proxy Pattern）是一种结构型设计模式，它提供了一个代理对象来控制对另一个对象的访问。代理通常充当客户端和实际目标对象之间的中介，以添加额外的控制和管理。

代理模式有多种类型，包括静态代理和动态代理。在静态代理中，代理类和目标类都在编译时已知，而在动态代理中，代理类在运行时生成。

**适用场景**

对于对象的操作出现不方便的情况，尤其是分布式系统中


代理模式通常用于以下情况：

1. 远程代理：代理对象在不同地址空间中，用于访问远程对象。这是远程过程调用（RPC）的一种常见实现方式。

1. 虚拟代理：代理对象用于延迟创建和初始化开销大的对象，直到真正需要访问这些对象时。例如，加载大型图像或文档时可以使用虚拟代理。

1. 保护代理：代理对象控制对真实对象的访问权限，可以用于实现权限控制、缓存、日志记录等功能。

1. 缓存代理：代理对象缓存对真实对象的请求结果，以提高性能。

代理模式的关键是在代理对象中实现与被代理对象相同的接口，以便客户端可以无差异地访问代理对象和真实对象。
以下是一个简单的C++示例，演示了代理模式的实现：
```C++
#include <iostream>

// 抽象主题接口
class Subject {
public:
    virtual void request() = 0;
};

// 具体主题类
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject: Handling request" << std::endl;
    }
};

// 代理类
class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    Proxy() : realSubject(nullptr) {}

    void request() override {
        // 在需要时创建真实对象
        if (realSubject == nullptr) {
            realSubject = new RealSubject();
        }
        realSubject->request();
    }
};

int main() {
    Proxy proxy;

    // 客户端代码通过代理访问真实对象
    proxy.request();

    return 0;
}
```
在这个示例中，我们有以下关键要点：

Subject 是抽象主题接口，定义了一个 request() 方法。

RealSubject 是具体主题类，实现了 Subject 接口，并处理真正的请求。

Proxy 是代理类，也实现了 Subject 接口，它包含一个指向 RealSubject 对象的指针。在 request() 方法中，代理对象会在需要时创建真实对象，并将请求委派给真实对象。

在 main 函数中，我们创建了一个代理对象 proxy，并通过它来访问真实对象。客户端代码只需要与代理对象交互，而无需直接与真实对象交互。

代理模式有助于控制对真实对象的访问，可以在代理对象中添加额外的功能，如权限控制、缓存、延迟加载等。它提供了一种更灵活的方式来管理对象之间的关系。

**总结**    
从客户角度看，使用代理和没有使用代理的方式，接口基本没有区别，看起来简单，实际使用较为复杂，部分使用工具完成代理的实现，在分布式系统中最常且大量使用


### 13、适配器模式（Adapter Pattern）-----接口隔离”模式——解决耦合度太高的问题
适配器模式（Adapter Pattern）是一种结构型设计模式，用于将一个类的接口转换成另一个客户端期望的接口。适配器模式允许不兼容的接口能够一起工作，通常用于以下情况：


1. 当你想使用一个已经存在的类，但它的接口与你的需要不匹配时。
2. 当你想创建一个可以复用的类，与一些不相关或不可预见的类协同工作时。

适配器模式有两种主要类型：类适配器和对象适配器。以下是它们的简要说明：

1. 类适配器：通过多重继承来实现适配器。在C++中，这通常通过一个适配器类继承目标类并实现源接口来完成。

2. 对象适配器：通过将源对象嵌入到适配器中来实现适配器。在C++中，这通常通过组合目标类和源对象来完成。

下面是一个C++示例，演示了类适配器的实现：
```C++
#include <iostream>

// 目标接口
class Target {
public:
    virtual void request() = 0;
};

// 源类（需要适配的类）
class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee's specificRequest()" << std::endl;
    }
};

// 类适配器
class Adapter : public Target, private Adaptee {
public:
    void request() override {
        specificRequest();
    }
};

int main() {
    Target* adapter = new Adapter();
    adapter->request();

    delete adapter;

    return 0;
}
```
在这个示例中，我们有以下关键要点：

- Target 是目标接口，定义了一个 request() 纯虚函数。

- Adaptee 是源类，它具有一个名为 specificRequest() 的特定方法。

- Adapter 是适配器类，它继承了 Target 接口，并通过多重继承私有继承了 Adaptee 类。在 request() 方法中，适配器调用了 specificRequest() 方法来适应目标接口。

在 main 函数中，我们创建了一个适配器对象，并通过目标接口调用了 request() 方法。适配器类的存在使得目标接口可以使用 specificRequest() 方法，即使它们的接口不兼容。

适配器模式是一种有用的设计模式，可以将不兼容的接口整合在一起，使得既有的类能够协同工作，同时不影响它们的原始代码。


**总结**    
希望复用一些现有的类，但现有接口与需要复用的环境不一致,实际上适配器有对象适配器和类适配器，但是对象适配器采用组合的方式，更加灵活，满足低耦合，**不推荐使用类适配器,注意和装饰模式的区别**

### 14、中介者模式（Mediator Pattern） -----接口隔离”模式——解决耦合度太高的问题
中介者模式（Mediator Pattern）是一种行为型设计模式，旨在降低对象之间的直接耦合关系。在中介者模式中，一个中介者对象封装了一系列对象之间的交互，使得这些对象不再显式地相互引用，而是通过中介者来进行通信。这有助于减少对象之间的依赖关系，提高系统的灵活性和可维护性。

中介者模式适用于以下情况：

1. 当一个系统中的对象之间的通信方式变得复杂，导致对象之间紧密耦合时。
1. 当需要一个独立的对象来处理对象之间的交互，以避免对象之间的直接通信。
1. 当希望系统具有更好的可扩展性，以便将新对象添加到系统中而无需更改现有对象之间的通信方式。

**使用中介者，来封装各个对象之间的相互引用（封装变化）；将编译时依赖转变为运行时依赖**

以下是一个简单的C++示例，演示了中介者模式的实现：
```C++
#include <iostream>
#include <string>
#include <vector>

// 抽象中介者类
class Mediator {
public:
    virtual void sendMessage(const std::string& message, Colleague* colleague) = 0;
};

// 具体中介者类
class ConcreteMediator : public Mediator {
private:
    std::vector<Colleague*> colleagues;

public:
    void addColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }

    void sendMessage(const std::string& message, Colleague* sender) override {
        for (Colleague* colleague : colleagues) {
            if (colleague != sender) {
                colleague->receiveMessage(message);
            }
        }
    }
};

// 抽象同事类
class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* mediator) : mediator(mediator) {}

    virtual void send(const std::string& message) = 0;
    virtual void receiveMessage(const std::string& message) = 0;
};

// 具体同事类
class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(Mediator* mediator) : Colleague(mediator) {}

    void send(const std::string& message) {
        std::cout << "Sending message: " << message << std::endl;
        mediator->sendMessage(message, this);
    }

    void receiveMessage(const std::string& message) {
        std::cout << "Received message: " << message << std::endl;
    }
};

int main() {
    ConcreteMediator mediator;

    ConcreteColleague colleague1(&mediator);
    ConcreteColleague colleague2(&mediator);

    mediator.addColleague(&colleague1);
    mediator.addColleague(&colleague2);

    colleague1.send("Hello, colleague2!");
    colleague2.send("Hi, colleague1!");

    return 0;
}
```
在这个示例中，我们有以下关键要点：

- Mediator 是抽象中介者类，定义了一个 sendMessage() 方法，用于同事对象之间的通信。

- ConcreteMediator 是具体中介者类，它维护了一个同事对象列表，可以添加同事对象，并在收到消息时将消息广播给其他同事对象。

- Colleague 是抽象同事类，包含一个指向中介者的指针，定义了 send() 和 receiveMessage() 方法。

- ConcreteColleague 是具体同事类，它实现了抽象同事类的方法，通过中介者来发送和接收消息。

在 main 函数中，我们创建了一个中介者对象 mediator 和两个同事对象 colleague1 和 colleague2，然后将它们添加到中介者中。同事对象可以通过中介者来发送和接收消息，而不需要直接与其他同事对象通信。

中介者模式有助于减少对象之间的直接依赖关系，提高系统的可维护性和可扩展性。它适用于对象之间的通信复杂且紧密耦合的情况，通过引入中介者对象，可以将通信逻辑集中管理，降低系统的复杂性。


**总结**    
将多个对象间的关联关系解耦，利用中介者集中管理，将其转变为多个对象和一个中介者关联,可以对中介者进行分解处理与门面模式区别，门面模式是解耦系统间（单向）的关联关系，而中介者是解耦各个对象之间（双向）的关联关系






### 14、中介者模式（Mediator Pattern） -----接口隔离”模式——解决耦合度太高的问题




- [1] [李建忠 c++ 设计模式课程] ()
- [2] [Karepbq43231](https://juejin.cn/column/7185195060198604860)
- [3] [毅大师](https://zhuanlan.zhihu.com/p/563209541)