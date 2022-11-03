/*
* 模式动机：订阅者类向出版者类订阅报纸，很明显不会只有一个订阅者对象订阅报纸，订阅者对象可以有很多；当出版者对象出版新报纸的时候，多个订阅者对象如何知道呢还有订阅者对象如何得到新报纸的内容呢？
进一步抽象描述这个问题：当一个对象的状态发生改变的时候，如何让依赖于它的所有对象得到通知，并进行相应的处理呢？
*观察者模式：定义对象间的一种一对多依赖关系，使得每当一个对象状态发生改变时，其相关依赖对象皆得到通知并被自动更新。观察者模式是一种对象行为型模式。
*它用于建立一种对象与对象之间的依赖关系，一个对象发生改变时将自动通知其他对象，其他对象将相应作出反应。在观察者模式中，发生改变的对象称为观察目标，而被通知的对象称为观察者，
一个观察目标可以对应多个观察者，而且这些观察者之间可以没有任何相互联系，可以根据需要增加和删除观察者，使得系统更易于扩展。
*模式分析：1.观察者模式描述了如何建立对象与对象之间的依赖关系，如何构造满足这种需求的系统。
2.这一模式中的关键对象是观察目标和观察者，一个目标可以有任意数目的与之相依赖的观察者，一旦目标的状态发生改变，所有的观察者都将得到通知。
3.作为对这个通知的响应，每个观察者都将监视观察目标的状态以使其状态与目标状态同步，这种交互也称为发布-订阅。
观察目标是通知的发布者，它发出通知时并不需要知道谁是它的观察者，可以有任意数目的观察者订阅它并接收通知。
*适用环境：1.一个抽象模型有两个方面，其中一个方面依赖于另一个方面，将这两个方面封装在独立的对象中使它们可以各自独立地改变和复用。
2.一个对象的改变将导致一个或多个其他对象也发生改变，而并不知道具体有多少对象将发生改变，也不知道这些对象是谁。
3.需要在系统中创建一个触发链，A对象的行为将影响B对象，B对象的行为将影响C对象……，可以使用观察者模式创建一种链式触发机制。
*优点：1.观察者模式可以实现表示层和数据逻辑层的分离，定义了稳定的消息更新传递机制，并抽象了更新接口，使得可以有各种各样不同的表示层充当具体观察者角色。
2.观察者模式在观察目标和观察者之间建立一个抽象的耦合。观察目标只需要维持一个抽象观察者的集合，无须了解其具体观察者。由于观察目标和观察者没有紧密地耦合在一起，因此它们可以属于不同的抽象化层次。
3.观察者模式支持广播通信，观察目标会向所有已注册的观察者对象发送通知，简化了一对多系统设计的难度。
4.观察者模式满足“开闭原则”的要求，增加新的具体观察者无须修改原有系统代码，在具体观察者与观察目标之间不存在关联关系的情况下，增加新的观察目标也很方便。
缺点：1.如果一个观察目标对象有很多直接和间接观察者，将所有的观察者都通知到会花费很多时间。
2.如果在观察者和观察目标之间存在循环依赖，观察目标会触发它们之间进行循环调用，可能导致系统崩溃。
3.观察者模式没有相应机制让观察者知道所观察的目标对象是怎么发生变化的，而仅仅只是知道观察目标发生了变化。
*/

#include<iostream>
#include<list>
using namespace std;

class Observer //观察者接口，包括事件响应函数
{//观察者将对观察目标的改变做出反应，观察者一般定义为接口，该接口声明了更新数据的方法update()，因此又称为抽象观察者。
public:
	virtual void update(int n) = 0;
};

class Subject //目标类，负责触发事件
{//它是指被观察的对象。在目标中定义了一个观察者集合，一个观察目标可以接受任意数量的观察者来观察，它提供一系列方法来增加和删除观察者对象，同时它定义了通知方法notify()。
	//目标类可以是接口，也可以是抽象类或具体类。
	virtual void Attach(Observer*) = 0;//附加观察者
	virtual void Detach(Observer*) = 0;//移除观察者
	virtual void Notify() = 0;//通知观察者
};

class ConcreteObserver1 :public Observer
{//具体观察者中维护一个指向具体目标对象的引用，它存储具体观察者的有关状态，这些状态需要和具体目标的状态保持一致；它实现了在抽象观察者中定义的update()方法。
	//通常在实现时，可以调用具体目标类的attach()方法将自己添加到目标类的集合中或通过detach()方法将自己从目标类的集合中删除。
public:
	ConcreteObserver1(Subject *p):m_subject(p){}
	void update(int n)
	{
		cout << "观察者1事件响应函数,接受参数:" << n << endl;
	}
private:
	Subject* m_subject;
};
class ConcreteObserver2 :public Observer
{
public:
	ConcreteObserver2(Subject *p):m_subject(p){}
	void update(int n)
	{
		cout << "观察者2事件响应函数,接受参数:" << n << endl;
	}
private:
	Subject* m_subject;
};

class ConcreteSubject :public Subject
{//具体目标是目标类的子类，通常它包含有经常发生改变的数据，当它的状态发生改变时，向它的各个观察者发出通知；同时它还实现了在目标类中定义的抽象业务逻辑方法（如果有的话）。
	//如果无须扩展目标类，则具体目标类可以省略。
private:
	list<Observer*> observerList;
	int m_state;
public:
	void Attach(Observer* observer)
	{
		observerList.push_back(observer);
	}
	void Detach(Observer* observer)
	{
		observerList.remove(observer);
	}
	void Notify()
	{
		for (list<Observer*>::iterator it = observerList.begin(); it != observerList.end(); ++it)
		{
			(*it)->update(m_state);
		}
	}
	void SetState(int state)
	{
		m_state = state;
	}
};

int main()
{
	ConcreteSubject* pSubject = new ConcreteSubject(); //目标实例化
	Observer* pObserver1 = new ConcreteObserver1(pSubject);//创建观察者
	Observer* pObserver2 = new ConcreteObserver2(pSubject);

	pSubject->SetState(1);//改变目标状态
	pSubject->Attach(pObserver1);
	pSubject->Attach(pObserver2);
	pSubject->Notify();

	pSubject->SetState(2);
	pSubject->Detach(pObserver1);
	pSubject->Notify();

}