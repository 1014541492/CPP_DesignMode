/*
* 模式动机：在面向对象系统中，使用原型模式来复制一个对象的自身，从而克隆出多个与原型对象一模一样的对象。
在软件系统中，有些对象的创建过程较为复杂，而且有时候需要频繁创建，原型模式通过给出一个原型对象来指明所要创建的对象的类型，然后用复制这个原型对象的办法创建出更多同类型的对象，这就是原型模式的意图所在。
* 原型模式是一种对象创建型模式，用原型实例指定创建对象的种类，并且通过复制这些原型创建新的对象。原型模式允许一个对象再创建另外一个可定制的对象，无须知道任何创建的细节。 
* 原型模式的基本工作原理是通过将一个原型对象传给那个要发动创建的对象，这个要发动创建的对象通过请求原型对象拷贝原型自己来实现创建过程。
* 原型模式分类：原型模式克隆对象时，根据其成员对象是否也在克隆，原型模式可以分为两种形式，深克隆和浅克隆。 
* 浅克隆复制对象的字段值：对于基本数据类型，则复制值；对于复合数据类型，仅复制该字段值，如数组变量则复制地址，对于对象变量则复制对象的reference
* 深克隆与浅克隆的区别在于对复合数据类型的复制。若对象中的某个字段为复合类型，在克隆对象的时候，需要为该字段重新创建一个对象。
* 优点：1.当创建新的对象实例较为复杂时，使用原型模式可以简化对象的创建过程，通过一个已有实例可以提高新实例的创建效率。
2.扩展性较好，由于在原型模式中提供了抽象原型类，在客户端可以针对抽象原型类进行编程，而将具体原型类写在配置文件中，增加或减少产品类对原有系统都没有任何影响。 
3.原型模式提供了简化的创建结构，工厂方法模式常常需要有一个与产品类等级结构相同的工厂等级结构，而原型模式就不需要这样，原型模式中产品的复制是通过封装在原型类中的克隆方法实现的，无须专门的工厂类来创建产品。
4.可以使用深克隆的方式保存对象的状态，使用原型模式将对象复制一份并将其状态保存起来，以便在需要的时候使用（如恢复到某一历史状态），可辅助实现撤销操作。
缺点：1.需要为每一个类配备一个克隆方法，而且这个克隆方法需要对类的功能进行通盘考虑，这对全新的类来说不是很难，但对已有的类进行改造时，不一定是件容易的事，必须修改其源代码，违背了“开闭原则”。
2.在实现深克隆时需要编写较为复杂的代码，而且当对象之间存在多重的嵌套引用时，为了实现深克隆，每一层对象对应的类都必须支持深克隆，实现起来可能会比较麻烦。
*适用环境：1.创建新对象成本较大，如创建对象的构造函数非常的复杂，在执行这个构造函数时会消耗较多的CPU或内存资源，
同时，这个构造函数中的一些信息又没有什么变化，新的对象可以通过原型模式对已有对象进行复制来获得，如果是相似对象，则可以对其属性稍作修改。
2.如果系统要保存对象的状态，而对象的状态变化很小，或者对象本身占内存不大的时候，也可以使用原型模式配合备忘录模式来应用。相反，如果对象的状态变化很大，或者对象占用的内存很大，那么采用状态模式会比原型模式更好。
3.需要避免创建一个与产品类层次平行的工厂类层次时，并且类的实例对象只能有几个不同状态组合中的一种时，建立相应数目的原型并克隆它们可能比每次用合适的状态手工实例化该类更方便一些。
4.比如在画图工具里，要画圆只需要拖动工具条的画圆工具到绘图区即可，而不需要从头开始一点一点的画一个圆，而且如果需要不同大小和颜色的圆，只需要复制几个圆，然后再修改他们的大小和颜色即可。
*/

#include<iostream>
#include<string>
using namespace std;

//父类
class Resume //抽象原型类是定义具有克隆自己的方法的接口
{
protected:
	char* name;
public:
	Resume() {}
	virtual ~Resume() {}
	virtual Resume* Clone() { return NULL; }
	virtual void Set(char* n) {}
	virtual void Show() {}
};

class ResumeA : public Resume
{
public:
	ResumeA(const char* str);  //构造函数
	ResumeA(const ResumeA& r); //拷贝构造函数
	~ResumeA();                //析构函数
	ResumeA* Clone();          //克隆，关键所在
	void Show();               //显示内容
};
ResumeA::ResumeA(const char* str)
{
	if (str == NULL) {
		name = new char[1];
		name[0] = '\0';
	}
	else {
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
}
ResumeA::~ResumeA() { delete[] name; }
ResumeA::ResumeA(const ResumeA& r) {
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
}
ResumeA* ResumeA::Clone() {
	return new ResumeA(*this);
}
void ResumeA::Show() {
	cout << "ResumeA name : " << name << endl;
}

class ResumeB : public Resume
{
public:
	ResumeB(const char* str);  //构造函数
	ResumeB(const ResumeB& r); //拷贝构造函数
	~ResumeB();                //析构函数
	ResumeB* Clone();          //克隆，关键所在
	void Show();               //显示内容
};
ResumeB::ResumeB(const char* str)
{
	if (str == NULL) {
		name = new char[1];
		name[0] = '\0';
	}
	else {
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
}
ResumeB::~ResumeB() { delete[] name; }
ResumeB::ResumeB(const ResumeB& r) {
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
}
ResumeB* ResumeB::Clone() {
	return new ResumeB(*this);
}
void ResumeB::Show() {
	cout << "ResumeB name : " << name << endl;
}

int main()
{
	Resume* r1 = new ResumeA("A");
	Resume* r2 = new ResumeB("B");
	Resume* r3 = r1->Clone();
	Resume* r4 = r2->Clone();
	r1->Show(); r2->Show();
	//删除r1,r2
	delete r1; delete r2;
	r1 = r2 = NULL;
	//深拷贝所以对r3,r4无影响
	r3->Show(); r4->Show();
	delete r3; delete r4;
	r3 = r4 = NULL;
}