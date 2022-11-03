/*
* 命令模式动机：可以将请求发送者和接收者完全解耦，发送者与接收者之间没有直接引用关系，发送请求的对象只需要知道如何发送请求，而不必知道如何完成请求。
* 命令模式(Command Pattern)：将一个请求封装为一个对象，从而让我们可用不同的请求对客户进行参数化；对请求排队或者记录请求日志，以及支持可撤销的操作。命令模式是一种对象行为型模式
* 命令模式的核心在于引入了命令类，通过命令类来降低发送者和接收者的耦合度，请求发送者只需指定一个命令对象，再通过命令对象来调用请求接收者的处理方法
* 模式分析：1.命令模式的本质是对请求进行封装，一个请求对应于一个命令，将发出请求的职责和执行请求的职责分割开。
2.每一个请求都对应一个操作：发送者发出请求，要求执行一个操作；接收者收到请求，并执行操作。
3.命令模式允许请求者和接收者相互独立，使得请求者不必知道接收者的接口，更不必知道请求是怎么被接收，以及操作是否被执行、何时被执行，以及是怎么被执行的。
4.命令模式使请求本身成为一个对象，这个对象和其他对象一样可以被存储和传递。 
5.命令模式的关键在于引入了抽象命令类，请求发送者针对抽象命令类编程，只有实现了抽象命令类的具体命令才与请求接收者相关联。
*优点：
1.降低系统的耦合度。由于请求者与接收者之间不存在直接引用，因此请求者与接收者之间实现完全解耦，相同的请求者可以对应不同的接收者，同样，相同的接收者也可以供不同的请求者使用，两者之间具有良好的独立性。
2.新的命令可以很容易地加入到系统中。由于增加新的具体命令类不会影响到其他类，因此增加新的具体命令类很容易，无须修改原有系统源代码，甚至客户类代码，满足“开闭原则”的要求。
3.为请求的撤销(Undo)和恢复(Redo)操作提供了一种设计和实现方案。
4.可以比较容易地设计一个命令队列或宏命令(组合命令)。
缺点：使用命令模式可能会导致某些系统有过多的具体命令类。因为针对每一个对请求接收者的调用操作都需要设计一个具体命令类，因此在某些系统中可能需要提供大量的具体命令类，这将影响命令模式的使用
*适用：1.系统需要将请求调用者和请求接收者解耦，使得调用者和接收者不直接交互。请求调用者无须知道接收者的存在，也无须知道接收者是谁，接收者也无须关心何时被调用。
2.系统需要在不同的时间指定请求、将请求排队和执行请求。一个命令对象和请求的初始调用者可以有不同的生命期，
换言之，最初的请求发出者可能已经不在了，而命令对象本身仍然是活动的，可以通过该命令对象去调用请求接收者，而无须关心请求调用者的存在性，可以通过请求日志文件等机制来具体实现。
3.系统需要支持命令的撤销(Undo)操作和恢复(Redo)操作。
4.系统需要将一组操作组合在一起形成宏命令。
*/
//区别：责任链模式和命令模式用于处理请求发送者和接收者之间的不同连接方式。
//责任链按照顺序将请求动态传递给一系列的潜在接收者， 直至其中一名接收者对请求进行处理。命令模式则是在发送者和请求者之间建立单向连接。
//作为命令模式的作用，非常明显，它可以通过某些行为来参数化对象。从而避免了继承导致的调用与接收的紧耦合。
//命令模式则是分离了这两者，修改时只需要添加接收者并创建新的实例化具体命令类即可实现整套代码的调用。

#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

class Reciver// 接受者，作为最底层的调用 //接收者执行与请求相关的操作，它具体实现对请求的业务处理。
{
public:
	void BakeMutton() { cout << "烤羊肉" << endl; }
	void BakeChiken() { cout << "烤鸡翅" << endl; }
};

class Command //抽象命令类一般是一个抽象类或接口，在其中声明了用于执行请求的execute()等方法，通过这些方法可以调用请求接收者的相关操作。
{
public:
	Command(Reciver*r):rec(r){}
	virtual void excute() = 0;
protected:
	Reciver* rec;
};

class ConcreteCommandA :public Command//具体命令类是抽象命令类的子类
{//实现了在抽象命令类中声明的方法，它对应具体的接收者对象，将接收者对象的动作绑定其中。在实现execute()方法时，将调用接收者对象的相关操作(Action)。
public:
	ConcreteCommandA(Reciver *p):Command(p){}
	void excute()
	{
		cout << "ConcreteCommandA excuting......" << endl;
		rec->BakeMutton();
	}
};
class ConcreteCommandB :public Command
{
public:
	ConcreteCommandB(Reciver*p):Command(p){}
	void excute()
	{
		cout << "ConcreteCommandB excuting......" << endl;
		rec->BakeChiken();
	}
};

class Invoke// 调用者，作为最上层，用于管理具体类的操作，从而对接收者增删
{//即请求发送者，它通过命令对象来执行请求。一个调用者并不需要在设计时确定其接收者，因此它只与抽象命令类之间存在关联关系。
//在程序运行时可以将一个具体命令对象注入其中，再调用具体命令对象的execute()方法，从而实现间接调用请求接收者的相关操作。
private:
	vector<Command*>m;
public:
	void add(Command* p)
	{
		m.push_back(p);
	}
	void remove(Command* p)
	{
		m.erase(find(m.begin(), m.end(), p));
	}
	void clear()
	{
		m.clear();
	}
	void Notify()
	{
		for (vector<Command*>::iterator it = m.begin(); it != m.end(); ++it)
		{
			(*it)->excute();
		}
	}
};

int main()
{
	Reciver* reciver = new Reciver();
	Command* a = new ConcreteCommandA(reciver);
	Command* b = new ConcreteCommandB(reciver);
	Invoke* invoke = new Invoke();

	invoke->add(a);
	invoke->add(a);
	invoke->add(b);
	invoke->Notify();

	invoke->remove(a);
	invoke->remove(b);
	invoke->Notify();
}