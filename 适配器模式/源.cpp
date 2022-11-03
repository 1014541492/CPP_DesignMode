/*
* 适配器模式：将一个接口转换为客户希望的另一个接口，适配器模式使接口不兼容的那些类可以一起工作
* 应用：系统需要使用现有的类，而这些类的接口不符合系统的需求；
* 优点：1.将目标类和适配器类解耦。通过引入一个适配器类来重用现有的适配者类，而无须修改原有的代码。
2.增加了类的透明性和复用性，将具体的实现封装在适配器类中，对于客户端类来说是透明的，而且提高了适配器的复用性。
3.灵活性和扩展性都非常好，符合开闭原则
缺点：1.一次最多只能适配一个适配器类，不能同时适配多个适配器。
2.适配器类不能为最终类。
3.目标抽象类只能为接口，不能为类，其使用有一定的局限性。
*/

//1 类适配器模式
// （1）类适配器模式结构：适配器类Adapter，实现了抽象目标类（Target）接口，并继承了适配者类（Adaptee）,
// 在适配器类 的request()方法中调用所继承的适配者类（Adaptee）的SpeaificRequest()方法，实现了适配的目的。
//*设计一个可以模拟各种动物的机器人，在机器人中定义了一系列方法，如机器人叫喊 cry()方法，机器人移动方法 move()，现在在不修改已有代码的情况下，使得机器人能够像狗一样，叫 wang()和跑 run()
#include<iostream>
#include<string>
using namespace std;

//class RobotTarget //目标抽象类：目标抽象类定义客户要用的特定领域的接口，可以是个抽象类或接口，也可以是个具体类
//{                 //机器人接口
//public:
//	virtual void cry() = 0;
//	virtual void move() = 0;
//	virtual ~RobotTarget() {};
//};
//
//class DogAdaptee  //适配者类 
//{                 //被适配的角色，它定义了一个已经存在的接口，这个接口需要适配。
//public:
//	virtual void wang() { cout << "wang wang" << endl; }
//	virtual void run() { cout << "run run" << endl; }
//}; 
//
//class DogAdapter : public DogAdaptee,public RobotTarget //适配器类 ：可以调用另一个接口，作为一个转换器，对适配者类和目标抽象类进行适配。
//{ //（1）类适配器中，适配器类通过实现Target接口并继承 Adaptee类，使得两者产生联系；
//	virtual void cry() { wang(); }
//	virtual void move() { run(); }
//};
//
//int main()
//{
//	RobotTarget* robot = new DogAdapter();
//	robot->cry();
//	robot->move();
//
//	delete robot; robot = nullptr;
//	return 0;
//}








//为了使客户端能够使用适配者类Adapte 的 spcificRequest()方法，需要提供一个适配器类Adapter,这个适配器类包装了一个适配者的实例，
//从而将客户端和适配者衔接起来，在适配器的request()方法中调用适配者的 spcificRequest()方法。适配器类和适配者类为关联关系。

//*英式插座与中式插座规格不同，如何在不修改英式插座的基础上转换为中式插座。
class China ////目标抽象类 中式插座
{
public:
	virtual ~China() {}
	virtual void Cplug() = 0;
};

class English //适配者类
{
public:
	virtual ~English(){}
	virtual void Eplug() { cout << "British Socket" << endl; }
};

class Adapter :public China //适配器类
{//（2）对象适配器类中，适配器类通过继承Target，并关联一个Adaptee对象使两者产生联系；
public:
	Adapter(English* p) :m(p) {}; //有参构造，将m赋初值p
	virtual ~Adapter() {}
	virtual void Cplug()
	{
		m->Eplug();
		cout << "adapter" << endl;
	}
private:
	English* m;
};

int main()
{
	English* e = new English;     //存在一个英式插座e
	China* c = new Adapter(e);    //创建一个中式插座c 用适配者继承了目标对象中式插座所以能实现中式充电器的插拔，在插拔实现函数中用英式插座调用英式电源的插拔，实现中英关联
	c->Cplug(); //中式插座 利用中式插拔实现了英式插拔 也就是实现了中式插座到英式插座的转换

	delete e;
	delete c;
}



//结构型模式(Structural Pattern)描述如何将类或者对象结合在一起形成更大的结构，就像搭积木，可以通过简单积木的组合形成复杂的、功能更为强大的结构。 
//结构型模式可以分为类结构型模式和对象结构型模式：
//1.类结构型模式关心类的组合，由多个类可以组合成一个更大的系统，在类结构型模式中一般只存在继承关系和实现关系。
//2.对象结构型模式关心类与对象的组合，通过关联关系使得在一个类中定义另一个类的实例对象，然后通过该对象调用其方法,
//*根据“合成复用原则”，在系统中尽量使用关联关系来替代继承关系，因此大部分结构型模式都是对象结构型模式。


//合成复用原则：当要扩展类的功能时，优先考虑使用合成/聚合，而不是继承。
//目的：防止类的体系庞大
//解决：当类与类之间的关系是"Is-A"时，用继承；当类与类之间的关系是"Has-A"时，用组合。

//is-a（英语：subsumption，包含架构）是一种继承关系，指的是类的父子继承关系。表达的是一种方式：这个东西是那个东西的一种。
//例如：长方体与正方体之间--正方体是长方体的一种。正方体继承了长方体的属性，长方体是父类，正方体是子类。
//has-a 是一种组合关系，是关联关系的一种（一个类中有另一个类型的实例），是整体和部分之间的关系（比如汽车和轮胎之间），并且代表的整体对象负责构建和销毁部分对象，代表部分的对象不能共享。