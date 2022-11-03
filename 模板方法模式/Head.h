#pragma once
class Fundamental//抽象类定义了一系列基本操作，这些基本操作可以是具体的，也可以是抽象的，每一个基本操作对应算法的一个步骤，在其子类中可以重定义或实现这些步骤。
	//同时，抽象类还实现了一个模板方法，用于定义一个算法的框架，模板方法不仅可以调用在抽象类中实现的基本方法，也可以调用在抽象类的子类中实现的基本方法，还可以调用其他对象中的方法。
{
public:
	virtual void primitiveOperation1();
	virtual void primitiveOperation2();
	void templateMethod();
	virtual ~Fundamental();
};

class ConcreteClassA :public Fundamental //具体子类是抽象类的子类，用于实现在抽象类中声明的抽象基本操作以完成子类特定算法的步骤，也可以覆盖在父类中已经实现的具体基本操作。
{
public:
	void primitiveOperation1();
	void primitiveOperation2();
	virtual ~ConcreteClassA();
};

class ConcreteClassB :public Fundamental
{
public:
	void primitiveOperation1();
	void primitiveOperation2();
	virtual ~ConcreteClassB();
};