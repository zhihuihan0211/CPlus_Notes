# c++ 设计模式
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



### 1、模板方法模式（Template Method Pattern）  


- [1] [李建忠 c++ 设计模式课程] ()
- [2] [Karepbq43231](https://juejin.cn/column/7185195060198604860)
- [3] [毅大师](https://zhuanlan.zhihu.com/p/563209541)