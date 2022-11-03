/*
* 定义：将一个复杂对象的构建与它的表示分离，使得同样的构建过程就可以创建不同的表示。
* 建造者模式是一步一步创建一个复杂的对象，它允许用户只通过指定复杂对象的类型和内容就可以构建它们，用户不需要知道内部的具体构建细节。
* 复杂对象：建造者模式中，复杂对象是指那些包含多个成员属性的对象，这些成员属性称为部件或零件，比如电子邮件包含发件人、收件人、主题、内容、附件等部件。
* 应用：对象的创建过程独立于创建该对象的类，在建造者模式中引入了指挥者类，将创建过程封装在指挥者类中，而不在建造者类中。
* 优点：（1）将产品本身与产品的创建过程解耦，使相同的创建过程可以创建不同的产品对象；
（2）增加新的具体建造者无效修改原有类库的代码，指挥者类针对抽象建造者类编程，系统扩展方便。
缺点：建造者模式所创建的产品一般具有较多的共同点，产品差异过大，则不适合
*/
//将建造过程与具体表示分离，做到了建造过程的抽象，当有新的对象要创建并且建造过程相同，可以继承建造类实现自己的具体表示即可。
//KFC 套餐实例，套餐是一个复杂的对象，一个套餐包含主食和饮料等组成部分，不用的套餐 主食和饮料的类型不同，服务员可以根据顾客的需求，一步步完成组成套餐。

#include<iostream>
#include<string>
using namespace std;

class Meal //产品类 复杂对象（两个属性）
{
private:
	string food="";
	string drink="";
public:
	void setfood(string a) { food = a; }
	void setdrink(string b) { drink = b; }
	string getfood() { return food; }
	string getdrink() { return drink; }
};

class Builder //抽象建造者 为创建一个产品Product对象的各个部件指定抽象接口
{//该接口一般声明两种方法，一类方法用于创建复杂对象的各个部件，另一类方法用于返回复杂对象。
public:
	virtual void buildfood() = 0;
	virtual void builddrink() = 0;
	virtual Meal* getmeal() = 0;
	virtual ~Builder() {};
};

class A :public Builder //具体建造者 实现了抽象建造者接口，实现各个部件的构造和装配方法，定义并明确它所创建的复杂对象，也可以提供一个方法返回创建好的复杂产品对象
{
private:
	Meal* meal;
public:
	A() { meal = new Meal(); }
	void buildfood()
	{
		meal->setfood("A_apple");
		cout << "A_apple" << endl;
	}
	void builddrink()
	{
		meal->setdrink("A_coke");
		cout << "A_coke" << endl;
	}
	Meal* getmeal() 
	{
		return meal;
	}
};
class B :public Builder
{
private:
	Meal* meal;
public:
	B() { meal = new Meal(); }
	void buildfood()
	{
		meal->setdrink("B_chiken");
		cout << "B_chiken" << endl;
	}
	void builddrink()
	{
		meal->setdrink("B_juice");
		cout << "B_juice" << endl;
	}
	Meal* getmeal()
	{
		return meal;
	}
};

class Director // 指挥者 （服务员）指挥者负责安排复杂对象的建造次序，
{//指挥者与抽象建造者之间存在关联关系，可调用建造者对象的部件与装配方法，完成发展对象的建造。客户端一般只需要与指挥者交互。
private:
	Builder* p_builder;
public:
	void setBuilder(Builder* a)
	{
		p_builder = a;
	}
	Meal* construct()
	{
		p_builder->buildfood();
		p_builder->builddrink();
		return p_builder->getmeal();
	}
};

int main()
{
	Builder* mb = new B(); //确定套餐种类，即选取哪种 具体套餐建造者 mb厨师
	Director* waiter = new Director(); //创造服务员指挥者
	waiter->setBuilder(mb); //服务员备餐 指定mb厨师
	waiter->construct();//服务员取餐 mb厨师建造B套餐 并返回
	Meal* meal = mb->getmeal();//客户获得套餐
	meal->getfood();
	meal->getdrink();

	delete mb; mb = nullptr;
	delete waiter; waiter = nullptr;
	delete meal; meal = nullptr;

	return 0;
}