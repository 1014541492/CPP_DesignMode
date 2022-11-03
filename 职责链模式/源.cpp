/*
* 行为型模式(Behavioral Pattern)是对在不同的对象之间划分责任和算法的抽象化。
*行为型模式不仅仅关注类和对象的结构，而且重点关注它们之间的相互作用。
* 通过行为型模式，可以更加清晰地划分类与对象的职责，并研究系统在运行时实例对象之间的交互。
在系统运行时，对象并不是孤立的，它们可以通过相互通信与协作完成某些复杂功能，一个对象在运行时也将影响到其他对象的运行。 
*行为型模式分为类行为型模式和对象行为型模式两种：
类行为型模式：类的行为型模式使用继承关系在几个类之间分配行为，类行为型模式主要通过多态等方式来分配父类与子类的职责。
对象行为型模式：对象的行为型模式则使用对象的聚合关联关系来分配行为，对象行为型模式主要是通过对象关联等方式来分配两个或多个类的职责。
根据“合成复用原则”，系统中要尽量使用关联关系来取代继承关系，因此大部分行为型设计模式都属于对象行为型设计模式。
*/

/*
* 职责链模式：避免请求发送者与接收者耦合在一起，让多个对象都有可能接收请求，将这些对象连接成一条链，并且沿着这条链传递请求，直到有对象处理它为止。职责链模式是一种对象行为型模式。
* 应用：1.有多个对象可以处理同一个请求，具体哪个对象处理该请求待运行时刻再确定，客户端只需将请求提交到链上，而无须关心请求的处理对象是谁以及它是如何处理的。
2.在不明确指定接收者的情况下，向多个对象中的一个提交一个请求。
3.可动态指定一组对象处理请求，客户端可以动态创建职责链来处理请求，还可以改变链中处理者之间的先后次序。
*优点：1.在给对象分派职责时，职责链可以给我们更多的灵活性，可以通过在运行时对该链进行动态的增加或修改来增加或改变处理一个请求的职责。
2.在系统中增加一个新的具体请求处理者时无须修改原有系统的代码，只需要在客户端重新建链即可，从这一点来看是符合“开闭原则”的。
*缺点：1.由于一个请求没有明确的接收者，那么就不能保证它一定会被处理，该请求可能一直到链的末端都得不到处理；一个请求也可能因职责链没有被正确配置而得不到处理。
2.对于比较长的职责链，请求的处理可能涉及到多个处理对象，系统性能将受到一定影响，而且在进行代码调试时不太方便。
3.如果建链不当，可能会造成循环调用，将导致系统陷入死循环。
*/

#include<iostream>
using namespace std;
class Handler//抽象处理者 它定义了一个处理请求的接口，一般设计为抽象类，由于不同的具体处理者处理请求的方式不同，因此在其中定义了抽象请求处理方法。
{//因为每一个处理者的下家还是一个处理者，因此在抽象处理者中定义了一个抽象处理者类型的对象（如结构图中的s），作为其对下家的引用。通过该引用，处理者可以连成一条链。
public:
	Handler() { p_next = NULL; }
	virtual ~Handler(){}
	void SetNextHandler(Handler* s) { p_next = s; }//设置下一个处理者
	virtual void HandlerRequest(int days) = 0;//处理请求
protected: 
	Handler* p_next;// 后继者
};

class Director :public Handler//具体处理者角色 
{//它是抽象处理者的子类，可以处理用户请求，在具体处理者类中实现了抽象处理者中定义的抽象请求处理方法，
//在处理请求之前需要进行判断，看是否有相应的处理权限，如果可以处理请求就处理它，否则将请求转发给后继者；在具体处理者中可以访问链中下一个对象，以便请求的转发。
public:
	virtual void HandlerRequest(int days)
	{
		if (days <= 1) { cout << "我是主管，有权批准一天假，同意了！" << endl; }
		else { p_next->HandlerRequest(days); }
	}
};
class Manager :public Handler
{
public:
	virtual void HandlerRequest(int days)
	{
		if (days <= 3) { cout << "我是经理，有权批准三以下的假，同意了！" << endl; }
		else { p_next->HandlerRequest(days); }
	}
};
class Boss :public Handler
{
public:
	virtual void HandlerRequest(int days)
	{
		if (days <= 7) { cout << "我是老板，最多让你请7天假，同意了" << endl; }
		else { cout << "你请的假事假太长了，不同意！" << endl; }
	}
};

int main()
{
	Handler* director = new Director();
	Handler* manager = new Manager;
	Handler* boss = new Boss;
	director->SetNextHandler(manager);
	manager->SetNextHandler(boss);

	while(1)
	{
		int day;
		cin >> day;
		director->HandlerRequest(day);
	}
	
}