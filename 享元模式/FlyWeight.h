#pragma once
class FlyWeight //Flyweight（抽象享元类）
{ //描述一个接口，通过这个接口flyweight可以接受并作用于外部状态。抽象享元类中定义了具体享元类公共的方法，
//这些方法可以向外界提供享元对象的内部数据（内部状态），同时也可以通过这些方法设置外部数据（外部状态）。
public:
	FlyWeight(){}
	virtual ~FlyWeight(){}//声明具体享元类共有的方法
	virtual void operation() = 0;
};

class ConcreteFlyWeight :public FlyWeight //ConcreteFlyweight（具体享元类）
{//具体享元类实现了抽象享元接口，其实例称为享元对象。具体享元对象必须是可以共享的。
public:
	ConcreteFlyWeight(){}
	~ConcreteFlyWeight(){}
	void operation();//具体享元类实现了在抽象享元类中声明的方法
};