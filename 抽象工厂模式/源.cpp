/*
* 抽象工厂模式是工厂方法模式的泛化版，工厂模式是一种特殊的抽象工厂模式，
在工厂模式中，每个具体工厂只能生产一种具体的产品，如海尔电视机厂只生产海尔电视机，而抽象工厂方法模式中，一个具体的工厂可以生产多个具体产品。
*应用：就是一个继承体系中，如果存在着多个等级结构（即存在着多个抽象类），并且分属各个等级结构中的实现类之间存在着一定的关联或者约束，就可以使用抽象工厂模式。
假如各个等级结构中的实现类之间不存在关联或约束，则使用多个独立的工厂来对产品进行创建，则更合适一点。
适合于产品之间相互关联、相互依赖且相互约束的地方；需要动态切换产品族的地方
*优点：1.抽象工厂模式将产品族的依赖与约束关系放到抽象工厂中，便于管理。
2.职责解耦，用户不需要关心一堆自己不关心的细节，由抽象工厂来负责组件的创建
3.切换产品族容易，只需要增加一个具体工厂实现，客户端选择另一个套餐就可以了
*缺点：缺点：1.抽象工厂模式类增加的速度很快，有一个产品族就需要增加一个具体工厂实现，比较繁琐
2.产品族难以扩展产品。当产品族中增加一个产品时，抽象工厂接口中需要增加一个函数，对应的所有具体工厂实现都需要修改，修改放大严重。
3.抽象工厂并未完全屏蔽创建细节，给出的都是组件。对于这种情况可以结合工厂模式或简单工厂模式一起使用。
*/
//如一个电器工厂可以生产多种类型的电器，如海尔工厂可以生产海尔电视机、海尔空调等，TCL工厂可以生产TCL电视、TCL空调等。
//相同品牌的电器构成一个产品族，而相同类型的电器构成了一个产品等级结构。

#include <iostream>
using namespace std;
class TV //抽象产品类
{
public:
	virtual void show() = 0;
	virtual ~TV(){};
};
class AC 
{
public:
	virtual void show() = 0;
	virtual ~AC(){};
};

class HairTV :public TV//具体产品类
{
public:
	void show() { cout << "Hair movie" << endl; }
};
class HisenseTV :public TV
{
public:
	void show() { cout << "Hisense movie" << endl; }
};
class HairAC :public AC
{
public:
	void show() { cout << "Hair air" << endl; }
};
class HisenseAC :public AC
{
public:
	void show() { cout << "Hisense air" << endl; }
};

class Factory//抽象工厂类 声明生成抽象产品的方法，在一个抽象工厂中可以定义一组方法，每一个方法对应一个产品等级结构。
{
public:
	virtual TV* CreateTV() = 0;
	virtual AC* CreateAC() = 0;
	virtual ~Factory() {};
};

class HairFactory :public Factory//具体工厂类 实现了抽象工厂声明的抽象产品的方法，生成一组具体产品
{
public:
	TV* CreateTV() { return new HairTV(); }
	AC* CreateAC() { return new HairAC(); }
};
class HisenseFactory :public Factory
{
public:
	TV* CreateTV() { return new HisenseTV(); }
	AC* CreateAC() { return new HisenseAC(); }
};

int main()
{
	Factory* hair_fac = new HairFactory();
	TV* hair_tv = hair_fac->CreateTV();
	AC* hair_ac = hair_fac->CreateAC();
	hair_tv->show();
	hair_ac->show();

	Factory* hisense_fac = new HisenseFactory();
	TV* hisense_tv = hisense_fac->CreateTV();
	AC* hisense_ac = hisense_fac->CreateAC();
	hisense_tv->show();
	hisense_ac->show();

	if (hair_fac != NULL) { delete hair_fac; hair_fac = NULL; }
	if (hair_tv != NULL) { delete hair_tv; hair_tv = NULL; }
	if (hair_ac != NULL) { delete hair_ac; hair_ac = NULL; }
	if (hisense_fac != NULL) { delete hisense_fac; hisense_fac = NULL; }
	if (hisense_tv != NULL) { delete hisense_tv; hisense_tv = NULL; }
	if (hisense_ac != NULL) { delete hisense_ac; hisense_ac = NULL; }
}

/*
* 总结：其实抽象工厂模式如果只有一个组件的话，其实是退化到了工厂方法模式，也就是没有了产品族的概念，只剩一个产品了，
因此简单工厂，工厂方法，抽象工厂这三者之间是有内在联系的，区别只是产品的复杂度。
抽象工厂的本质是选择产品族，因此大家可以根据这个特征来识别是否可以应用抽象工厂

简单工厂：唯一工厂类，一个产品抽象类，工厂类的创建方法依据入参判断并创建具体产品对象。
工厂方法：多个工厂类，一个产品抽象类，利用多态创建不同的产品对象，避免了大量的if-else判断。
抽象工厂：多个工厂类，多个产品抽象类，产品子类分组，同一个工厂实现类创建同组中的不同产品，减少了工厂子类的数量

*/