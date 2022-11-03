/*
* 模式动机：完成一项任务，往往可以有多种不同的方式，每一种方式称为一个策略，我们可以根据环境或者条件的不同选择不同的策略来完成该项任务。
在软件开发中也常常遇到类似的情况，实现某一个功能有多个途径，此时可以使用一种设计模式来使得系统可以灵活地选择解决途径，也能够方便地增加新的解决途径。 
*定义：定义一系列算法，将每一个算法封装起来，并让它们可以相互替换。策略模式让算法独立于使用它的客户而变化。策略模式是一种对象行为型模式。
* 模式分析：策略模式是对算法的封装，它把算法的责任和算法本身分割开，委派给不同的对象管理。策略模式通常把一个系列的算法封装到一系列具体策略类里面，作为抽象策略类的子类。
环境类是需要使用算法的类。在一个系统中可以存在多个环境类，它们可能需要重用一些相同的算法。
策略模式仅仅封装算法，提供新算法插入到已有系统中，以及老算法从系统中“退休”的方便，策略模式并不决定在何时使用何种算法，算法的选择由客户端来决定。这在一定程度上提高了系统的灵活性，
但是客户端需要理解所有具体策略类之间的区别，以便选择合适的算法，这也是策略模式的缺点之一，一定程度上增加了客户端的使用难度。
*适用环境：1.一个系统需要动态地在几种算法中选择一种。
2.一个对象有很多的行为，如果不用恰当的模式，这些行为就只好使用多重条件选择语句来实现。此时，使用策略模式，把这些行为转移到相应的具体策略类里面，就可以避免使用难以维护的多重条件选择语句。
3.不希望客户端知道复杂的、与算法相关的数据结构，在具体策略类中封装算法与相关的数据结构，可以提高算法的保密性与安全性。
*优点：1.提供了一种可以替换继承关系的办法。如果不使用策略模式，那么使用算法的环境类就可能会有一些子类，每一个子类提供一种不同的算法。
但是，这样一来就违背“单一职责原则”，决定使用哪一种算法的逻辑和算法本身混合在一起，从而不可能独立演化；而且使用继承无法实现算法或行为在程序运行时的动态切换。
2.可以避免多重条件选择语句。多重条件选择语句不易维护，它把采取哪一种算法的逻辑与算法本身的实现逻辑混合在一起，将它们全部硬编码在一个庞大的多重条件选择语句中，比直接继承环境类的办法还要原始和落后。
缺点：1.客户端必须知道所有的策略类，并自行决定使用哪一个策略类。这就意味着客户端必须理解这些算法的区别，以便适时选择恰当的算法。换言之，策略模式只适用于客户端知道所有的算法或行为的情况。
2.将造成系统产生很多具体策略类，任何细小的变化都将导致系统要增加一个新的具体策略类。
*/

//#include<iostream>
//using namespace std;
//
//class FlyBehavior //飞行行为，用抽象类表示
//{
//public:
//	virtual ~FlyBehavior(){}
//	virtual void fly() = 0;
//};
//class QuackBehavior //叫声行为，用抽象类表示
//{
//public:
//	virtual ~QuackBehavior(){}
//	virtual void quack() = 0;
//};
//
//class Duck //鸭子基类，有display，performFly， performQuack，swim等方法。
//{
//public:
//	Duck(FlyBehavior*a,QuackBehavior*b):p_flyBehavior(a),p_quackBehavior(b){}
//	virtual ~Duck(){}
//	virtual void display(){}
//	void performFly()
//	{
//		p_flyBehavior->fly();
//	}
//	void performQuack()
//	{
//		p_quackBehavior->quack();
//	}
//	void swim()
//	{
//		cout << ("All ducks float, even decoys!") << endl;
//	}
//private:
//	FlyBehavior* p_flyBehavior;
//	QuackBehavior* p_quackBehavior;
//};
//
////实现飞行行为的方法类
//class FlyWithWings: public FlyBehavior{
//public:
//   void fly() {
//   std::cout << ("I'm flying!!") << std::endl;
//   }
//};
//class FlyNoWay: public FlyBehavior{
//public:
//   void fly() {
//   std::cout << ("I can't fly") << std::endl;
//   }
//};
////实现叫声行为的类
//class Quack: public QuackBehavior{
//public:
//   void quack() {
//   std::cout << ("Quack") << std::endl;
//   }
//};
//
//class MuteQuack: public QuackBehavior{
//public:
//   void quack() {
//   std::cout << ("<< Slience >>") << std::endl;
//   }
//};
//class Squeak: public QuackBehavior{
//public:
//   void quack() {
//   std::cout << "Squeak" << std::endl;
//   }
//};
//
////绿头鸭类
//class MallardDuck: public Duck{
//public:
//   MallardDuck(FlyBehavior * fly_behavior = new FlyWithWings(), QuackBehavior * quack_behavior = new Quack()) :Duck(fly_behavior,quack_behavior) {}
//   void display()
//   {
//	  std::cout << "I'm a real Mallard duck" << std::endl;
//   }
//};
//
//int main()
//{
//	Duck* mallard = new MallardDuck();
//	mallard->performFly();
//	mallard->performQuack();
//}




















#include<iostream>
using namespace std;
//抽象策略类
class Strategy { //抽象策略类为所支持的算法声明了抽象方法，是所有策略类的父类，它可以是抽象类或具体类，也可以是接口。环境类通过抽象策略类中声明的方法在运行时调用具体策略类中实现的算法。
public:
    virtual void AlgorithmInterface() = 0;
};
//具体策略类  StrategyA
class StrategyA : public Strategy { //具体策略类实现了在抽象策略类中声明的算法，运行时具体策略对象将覆盖环境类中定义的抽象策略对象，使用一种具体的算法实现某个业务处理。
public:
    void AlgorithmInterface() {
        //算法A
        cout << "算法A实现" << endl;
    }
};
//具体策略类  StrategyB
class StrategyB : public Strategy {
public:
    void AlgorithmInterface() {
        //算法B
        cout << "算法B实现" << endl;
    }
};

//环境类
class Context { //环境类是使用算法的角色，它在解决某个问题(即实现某个方法)时可以采用多种策略。在环境类中维持一个对抽象策略类的引用实例，用于定义所采用的策略。
public:
    Context(Strategy* pStrategy) :pStrategy(pStrategy) {}//初始化是传入具体的策略对象
    void ContextInterface() {
        pStrategy->AlgorithmInterface();//根据具体的策略对象，调用其算法方法
    }
private:
    Strategy* pStrategy;
};

int main() {
    Strategy* pstrategyA = new StrategyA();
    Strategy* pstrategyB = new StrategyB();

    Context* pcontextA = new Context(pstrategyA);
    Context* pcontextB = new Context(pstrategyB);

    pcontextA->ContextInterface();
    pcontextB->ContextInterface();

    if (pstrategyA)delete pstrategyA;
    if (pstrategyB)delete pstrategyB;

    if (pcontextA)delete pcontextA;
    if (pcontextB)delete pcontextB;

    return 0;
}



//策略与简单工厂结合
//我们知道已有的AB两种算法，但是我们又不确定运行时使用哪种算法，同时为了让客户端和业务逻辑代码隔离开，于是，我们可以将客户端的创建算法类的业务逻辑转移到Cotent类，并添加一个创建算法工厂的方法。

//#include<iostream>
//#include<string>
//using namespace std;
////抽象策略类
//class strategy {
//public:
//    virtual void algorithminterface() = 0;
//};
////具体策略类  strategya
//class strategya : public strategy {
//public:
//    void algorithminterface() {
//        //算法a
//        cout << "算法a实现" << endl;
//    }
//};
////具体策略类  strategyb
//class strategyb : public strategy {
//public:
//    void algorithminterface() {
//        //算法b
//        cout << "算法b实现" << endl;
//    }
//};
//
////环境类
//class context {
//public:
//    context(strategy* pstrategy) :pstrategy(pstrategy) {}//初始化是传入具体的策略对象
//    void contextinterface() {
//        pstrategy->algorithminterface();//根据具体的策略对象，调用其算法方法
//    }
//private:
//    strategy* pstrategy;
//};
//
//// 工厂类
//class factory
//{
//public:
//    strategy* createstrategy(string type)
//    {
//        if(type== "strategya")
//            return new strategya();
//        else if(type== "strategyb")
//            return new  strategyb();
//        else
//            return null;
//    }
//};
//
//int main() {
//
//    // 创建工厂类对象
//    factory* factory = new  factory();
//    strategy* mystrategy = factory->createstrategy("strategya");
//    if (factory != null)
//        factory->contextinterface();
//
//    tv* hisensetv = mytvfactory->createtv(strategyb);
//    if (factory != null)
//        factory->contextinterface();
//
//    delete  factory;
//    factory = null;
//
//
//    if (pstrategya)delete pstrategya;
//    if (pstrategyb)delete pstrategyb;
//
//    if (pcontexta)delete pcontexta;
//    if (pcontextb)delete pcontextb;
//
//    return 0;
//}