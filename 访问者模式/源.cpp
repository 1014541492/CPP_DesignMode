/*
* 模式动机：对于系统中的某些对象中可能存在多种不同类型的元素，而且不同的调用者使用这些元素时也有所区别，这些调用者称为访问者。
* 定义：表示一个作用于某对象结构中各元素的操作，它使我们可以在不改变各元素的类的前提下定义作用于这些元素的新操作。
* 应用场景：
1.访问者模式适用于数据结构相对稳定的系统
2.它把数据结构和作用于数据结构之上的操作之间的耦合解脱开，使得操作集合可以相对自由的演化。
3.访问者模式的目的是要把处理从数据结构分离出来。如果这样的系统有比较稳定的数据结构，又有已与变化的算法的话，使用访问者模式就是比较合适的，因为访问者模式使得算法操作的增加变得更容易。反之亦然。
*访问者模式中对象结构存储了不同类型的元素对象，以提供不同访问者访问。
访问者模式包括两个层次结构，一个是访问者层次结构，提供了抽象访问者和具体访问者，一个是元素层次结构，提供了抽象元素和具体元素。
相同的访问者可以以不同的方式访问不同的元素，相同的元素可以接受不同访问者以不同的方式访问。
*优点：加新的操作很容易，因为增加新的操作就意味着增加一个新的访问者。访问者模式将有关的行为集中到一个访问者对象中。
缺点：使增加新的元素类变得困难。在访问者模式中，每增加一个新的元素都意味着要在抽象访问者角色中增加一个新的抽象操作，并在每一个具体访问者中增加相应的具体操作，违背“开闭原则”的要求。
*/

#include<iostream>
#include<vector>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor//抽象访问者  声明了访问元素对象的方法，通常为每一种类型的元素对象都提供一个访问方法
{
public:
	virtual void VisitConcreteElementA(ConcreteElementA *pElementA) = 0;
	virtual void VisitConcreteElementB(ConcreteElementB *pElementB) = 0;
};

class ConcreteVisitor1 :public Visitor//具体访问者 用于定义对不同类型元素对象的操作
{//具体访问者实现了每个由抽象访问者声明的操作，每一个操作用于访问对象结构中一种元素类型的元素。
public:
	void VisitConcreteElementA(ConcreteElementA* pElementA)
	{
		cout << "访问者1访问元素A" << endl;
	}
	void VisitConcreteElementB(ConcreteElementB* pElementB)
	{
		cout << "访问者1访问元素B" << endl;
	}
};
class ConcreteVisitor2 :public Visitor
{
public:
	void VisitConcreteElementA(ConcreteElementA* pElementA)
	{
		cout << "访问者2访问元素A" << endl;
	}
	void VisitConcreteElementB(ConcreteElementB* pElementB)
	{
		cout << "访问者2访问元素B" << endl;
	}
};

class Element//抽象元素类 声明accept()方法，用于接受访问者的访问
{//抽象元素一般是抽象类或接口，定义一个accept()方法，该方法以一个抽象访问者作为参数。
public:
	virtual void Accept(Visitor* pVisitor) = 0;
};

class ConcreteElementA :public Element //具体元素类 通过调用Visitor类的visit()方法实现对元素的访问
{
public:
	void Accept(Visitor* pVisitor)
	{
		pVisitor->VisitConcreteElementA(this);//通过调用visitor对象的 visit()方法实现对元素对象的访问
	}
};
class ConcreteElementB :public Element
{
public:
	void Accept(Visitor* pVisitor)
	{
		pVisitor->VisitConcreteElementB(this);
	}
};

class ObjectStructure//ObjectStructure类(对象结构类)，能枚举它的元素，可以提供一个高层的接口以允许访问者访问它的元素
{//对象结构是一个元素的集合，它用于存放元素对象，并且提供了遍历其内部元素的方法。
public:
	void Attach(Element* pElement)
	{
		elements.push_back(pElement);
	}
	void Detach(Element* pElement)
	{
		vector<Element*>::iterator it = find(elements.begin(), elements.end(), pElement);
		if (it != elements.end())
		{
			elements.erase(it);
		}
	}
	void Accept(Visitor* pVisitor)//// 为每一个element设置visitor，进行对应的操作
	{
		for(vector<Element*>::const_iterator it=elements.begin();it!=elements.end();++it)//const_iterator的类型，该类型只能用于读取容器内的元素，但不能改变其值
		{
			(*it)->Accept(pVisitor);
		}
	}
protected:
	vector<Element*>elements;
};

int main()
{
	ObjectStructure* p_object = new ObjectStructure; //实例化对象结构，用于存放元素对象，提供遍历其内部元素的方法
	
	//实例化具体元素 并将创建好的元素放入对象结构中
	ConcreteElementA* pElementA = new ConcreteElementA;
	ConcreteElementB* pElementB = new ConcreteElementB;
	p_object->Attach(pElementA);
	p_object->Attach(pElementB);

	ConcreteVisitor1* visitor1 = new ConcreteVisitor1;//实例化访问者
	ConcreteVisitor2* visitor2 = new ConcreteVisitor2;

	p_object->Accept(visitor1);
	p_object->Accept(visitor2);
}