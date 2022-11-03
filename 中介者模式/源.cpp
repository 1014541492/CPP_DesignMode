/*
* 模式动机：如果在一个系统中对象之间的联系呈现为网状结构。对象之间存在大量的多对多联系，将导致系统非常复杂，这些对象既会影响别的对象，也会被别的对象所影响，这些对象称为同事对象，
它们之间通过彼此的相互作用实现系统的行为。在网状结构中，几乎每个对象都需要与其他对象发生相互作用，而这种相互作用表现为一个对象与另外一个对象的直接耦合，这将导致一个过度耦合的系统。
新对象的引入将带来大量的修改工作。
如果在一个系统中对象之间存在多对多的相互关系，我们可以将对象之间的一些交互行为从各个对象中分离出来，并集中封装在一个中介者对象中，并由该中介者进行统一协调，
这样对象之间多对多的复杂关系就转化为相对简单的一对多关系。可以将系统的网状结构变成以中介者为中心的星形结构，如图所示。在这个星形结构中，同事对象不再直接与另一个对象联系，
它通过中介者对象与另一个对象发生相互作用。中介者模式是“迪米特法则”的一个典型应用。
*/
/*
* 迪米特法则（Demeter Principle）
目的：降低类与类之间的耦合
含义：每一个软件单位对其他的单位都只有最少的知识，而且局限于那些与本单位密切相关的软件单位。
解决：不发生依赖、关联、组合、聚合等耦合关系的陌生类不要作为局部变量的形式出现在类的内部。
实例：校长管理老师，老师管理学生。校长需要全体点名时，首先对老师点名，但是不必通过老师获取学生的信息并点名，而应该让老师对各自管理学生的点名，否则校长和学生之间就发生了原本不必要的耦合，
这样当学生类发生变化时，既要修改老师类，也要修改校长类。
*/
/*
* 中介者模式定义：用一个中介对象来封装一系列的对象交互，中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。它是一种对象行为型模式。
*模式分析：模式的核心在于中介者类的引入，它承担两方面职责：
1.中转作用（结构性）：通过中介者提供的中转作用，各个同事对象就不再需要显式引用其他同事，当需要和其他同事进行通信时，可通过中介者来实现间接调用。该中转作用属于中介者在结构上的支持。
2.协调作用（行为性）：中介者可以更进一步的对同事之间的关系进行封装，同事可以一致的和中介者进行交互，而不需要指明中介者需要具体怎么做，中介者根据封装在自身内部的协调逻辑，
对同事的请求进行进一步处理，将同事成员之间的关系行为进行分离和封装。该协调作用属于中介者在行为上的支持。
*适用环境：1.系统中对象之间存在复杂的引用关系，系统结构混乱且难以理解。
2.一个对象由于引用了其他很多对象并且直接和这些对象通信，导致难以复用该对象。
3.想通过一个中间类来封装多个类中的行为，而又不想生成太多的子类。可以通过引入中介者类来实现，在中介者中定义对象交互的公共行为，如果需要改变行为则可以增加新的具体中介者类。
*模式优点：可以减少子类生成，中介者将原本分布于多个对象间的行为集中在一起，改变这些行为只需生成新的中介者子类即可，这使各个同事类可被重用，无须对同事类进行扩展。
模式缺点：在具体中介者类中包含了大量同事之间的交互细节，可能会导致具体中介者类非常复杂，使得系统难以维护。
*/

/*
* 区别：中介者模式和命令模式类似，都有着一层中间层来作为沟通的渠道，只是中介者模式使用了Mediator来实现实现更新函数changed。而在命令模式中使用Invoke作为最上层，用于管理具体类的操作，
从而对接收者增删。简而言之，命令模式在发送者和请求者之间建立单向连接，使请求者可以调用发送者的不同方法。中介者清除了发送者和请求者之间的直接连接， 强制它们通过一个中介对象进行间接沟通。

*中介者模式让你能在单个中介者对象中封装多个对象间的复杂关系网。 类所拥有的依赖关系越少， 就越易于修改、 扩展或复用。

*中介者模式用于处理多个类高耦合的场景，类似于星型拓扑结构，在该结构中抽象出一个中介者，并配备同事类，实现不同的业务逻辑。命令模式的思路：中介者-同事-业务实现类。
* 抽象中介者定义统一的接口，用于各同事角色之间通信，具体中介者用于协调各同事角色最终的协作，必须依赖各个同事，同事角色不能与其他同事类有依赖，如果需要的话，必须通过中介者才能完成。
*/

#include<iostream>
using namespace std;

class Colleague;

class Mediator //定义一个中介者接口，包含对象改变所需调用函数。
{//Mediator: 抽象中介者，它定义一个接口，该接口用于与各同事对象之间进行通信。
public:
	virtual ~Mediator(){}
	virtual void changed(Colleague*) = 0;
};

class Colleague //定义"同事"类接口，初始化需要一个中介者对象，并通过该类更新另外一个"同事"
{//它定义各个同事类公有的方法，并声明了一些抽象方法来供子类实现，同时它维持了一个对抽象中介者类的引用，其子类可以通过该引用来与中介者通信。
public:
	Colleague(Mediator* mediator)
	{
		this->mediator = mediator;
	}
	virtual void changed()
	{
		mediator->changed(this);
	}
private:
	Mediator* mediator;
};

class ConcreteColleague1 :public Colleague
{//具体同事类，它是抽象同事类的子类；每一个同事对象在需要和其他同事对象通信时，先与中介者通信，通过中介者来间接完成与其他同事类的通信；在具体同事类中实现了在抽象同事类中声明的抽象方法。
public:
	ConcreteColleague1(Mediator *mediator):Colleague(mediator){}
	void update(){ cout << "update ConcreteColleague1 from ConcreteColleague2" << endl; }
};
class ConcreteColleague2 :public Colleague
{
public:
	ConcreteColleague2(Mediator *mediator):Colleague(mediator){}
	void update(){ cout << "update ConcreteColleague2 from ConcreteColleague1" << endl; }
};

class ConcreteMediator :public Mediator //具体的中介者类，实现更新函数changed。
{//具体中介者，它是抽象中介者的子类，通过协调各个同事对象来实现协作行为，它维持了对各个同事对象的引用。
private:
	ConcreteColleague1* colleague1;
	ConcreteColleague2* colleague2;
public:
	void setColleague1(ConcreteColleague1* colleague) { colleague1 = colleague; }
	void setColleague2(ConcreteColleague2* colleague) { colleague2 = colleague; }
	virtual void changed(Colleague* colleague)
	{
		if (colleague == colleague1)
		{
			colleague2->update();
		}
		else if (colleague = colleague2)
		{
			colleague1->update();
		}
	}
};

int main()
{
	ConcreteMediator concreteMediator;
	ConcreteColleague1 colleague1(&concreteMediator);
	ConcreteColleague2 colleague2(&concreteMediator);
	concreteMediator.setColleague1(&colleague1);
	concreteMediator.setColleague2(&colleague2);

	colleague1.changed();//"同事1"通过中介者更新"同事2"
	colleague2.changed();//"同事2"通过中介者更新"同事1"
}