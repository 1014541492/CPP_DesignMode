/*开闭原则：一个软件实体如类，模块和函数应该对扩展开放(对提供方)，对修改关闭(对使用方)。用抽象构建框架，用实现扩展细节。
 当软件需要变化时，尽量通过扩展软件实体的行为来实现变化，而不是通过修改已有的代码来实现变化。
* 简单工厂模式 违法了开闭原则
* 工厂方法模式定义：在工厂模式中，工厂父类负责定义创建产品对象的公告接口，而工厂子类负责生成具体的产品对象。
目的是将产品的实例化操作延迟到工厂子类中完成，通过工厂子类来确定究竟应该实例化哪一个具体产品类。
*核心工厂类不再负责产品的创建，这样核心类成为一个抽象工厂角色，仅负责具体工厂子类必须实现的接口，
进一步抽象化的好处是使得工厂方法模式可以使系统在不修改具体工厂角色的情况下引进新的产品。
* 应用：考虑到产品在后期会进行扩展的情况下，可以使用工厂方法模式。产品结构较复杂的情况下，可以使用工厂方法模式；
* 优点：符合“开闭原则”系统加入新产品时，无须修改抽象工厂和抽象产品提供的接口，无须修改客户端，也无须修改其他的具体工厂和具体产品，而只要添加一个具体工厂和具体产品即可。
* 缺点：在添加新产品时，需要编写新的具体产品类，而且要提供与之对应的具体工厂类，系统中类的个数将成对增加，一定程度上增加了系统的复杂度。
*/
#include<iostream>
using namespace std;
class TV//抽象产品类 产品对象的共同父类或接口
{
public:
	virtual void show() = 0;
	virtual ~TV() {};
};
class HairTV :public TV//具体产品类 具体产品实现了抽象产品的接口，某种类型的具体产品由专门的具体工厂创建。
{
public:
	void show() { cout << "Hair movie" << endl; }
};
class HisenseTV :public TV
{
public:
	void show() { cout << "Hisense movie" << endl; }
};

class TVFactory //抽象工厂类
{
public:
	virtual TV* CreateTV() = 0;
	virtual ~TVFactory() {};
};

class HairTVFactory :public TVFactory//具体工厂类 具体工厂是抽象工厂类的子类，实现了抽象工厂中定义的工厂方法，并可由客户调用，返回一个具体产品类的实例。
{
public:
	TV* CreateTV() { return new HairTV(); }
};
class HisenseTVFactory :public TVFactory
{
public:
	TV* CreateTV() { return new HisenseTV(); }
};

int main()
{
	TVFactory* hair_fac = new HairTVFactory();
	TV* hair = hair_fac->CreateTV();
	hair->show();

	TVFactory* hisense_fac = new HisenseTVFactory();
	TV* hisense = hisense_fac->CreateTV();
	hisense->show();

	if (hair_fac != NULL) { delete hair_fac; hair_fac = NULL; }
	if (hair != NULL) { delete hair; hair = NULL; }
	if (hisense_fac != NULL) { delete hisense_fac; hisense_fac = NULL; }
	if (hisense != NULL) { delete hisense; hisense = NULL; }
}