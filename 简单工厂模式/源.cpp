/*问题：创建对象过多，需要new操作符过多
* 不需要关系对象的创建过程，注重对象的实际操作
* 分离对象的创建和操作两部分，方便后期的维护。
* 优点：高内聚低耦合原则，逻辑部分和功能部分分割开
* 缺点：产品的创建由一个工厂创建，具体产品与工厂类之间耦合度高，严重影响了系统的灵活性和扩展性。一旦增加新产品，就需要修改工厂逻辑，不利于系统的扩展与维护
* 简单工厂模式：专门定义一个类来负责创建其他类的实例，被创建的实例通常具有共同的父类。
* 简单工厂模式，是一种实例化对象的方式，只要输入需要实例化对象的名字（参数），就可以通过工厂对象的相应工厂函数来制造你需要的对象。
*/


#include<iostream>
using namespace std;

typedef enum tv_type //枚举类型 放常数
{
	Hair,
	Hisense,
}type;

class TV//抽象产品类 TV类 为所有实例提供接口
{
public:
	virtual void show() = 0;//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。我们希望传入什么对象，那么就调用什么对象的函数
	virtual ~TV() {}//声明析构函数为虚函数，防止内存泄漏
};

class HairTV : public TV //具体产品类 （只关心操作部分）
{
public:
	void show() { cout << "Hair movie" << endl; }
};
class HisenseTV :public TV
{
public:
	void show() { cout << "Hisense movie" << endl; }
};

class TVFactory //工厂类 （创建部分，不关心）实现内部逻辑
{
public:
	TV* CreateTV(type str) //根据参数不同 返回不同的实例
	{
		switch (str) //对象的具体类创建过程 在工厂中实现
		{
		case Hair:
			return new HairTV();
		case Hisense:
			return new HisenseTV();
		default:
			return NULL;
		}
	}
};

int main() //创建模式共性：隐藏是实例是如何被创建的
{
	TVFactory* myTVFactory = new TVFactory();//创造模式共性：对象创建模式通过实例化委托给另一个对象；类创建模式通过继承改变实例化的类
	TV* hair = myTVFactory->CreateTV(Hair); // 创建模式共性：不用知道对象的具体类是什么
	if (hair != NULL) { hair->show(); } //多态使用条件：父类指针或引用指向子类对象
	TV* hisense = myTVFactory->CreateTV(Hisense);
	if (hisense != NULL) { hisense->show(); }

	delete hair, hisense;
	hair = hisense = 0;
	return 0;
}