/*
* 装饰模式：:动态地给一个对象增加一些额外的职责，就增加功能来说，装饰器比生成子类实现更为灵活。
装饰器可以在不改变对象本身的基础上给对象增加额外的新行为。
*优点 ：
（1）装饰模式与继承关系的目的都是扩展对象的功能，但是装饰器模式可以提供比继承更多的灵活性；
（2）可以通过一种动态的方式扩展一个对象的功能，通过配置文件可以在运行时选择不同的装饰器，从而实现不同的行为；
（3）符合开闭原则，具体构件类和具体装饰类可以独立变化，用户可以根据需要增加新的具体构件类和具体装饰类。
缺点：
（1）增加系统的复杂度。使用装饰模式进行系统设计时会产生很多小对象，这些小对象的区别在于它们之间相互连接的方式有所不同，而不是它们的类或属性值有所不同，同时产生很多具体装饰类。
（2）装饰模式比继承更加易于出错，排查问题困难。
*应用：
（1）在不影响其他对象的情况下，以动态、透明的方式给单个对象添加职责；
（2）需要动态地给一个对象增加功能，这些功能也可以被撤销；
*/

//案例：变形金刚在变形之前是一辆车，可以在陆地移动。当变成机器人后除了在陆地移动还可以说话，当变成飞机时，除了在陆地移动还可以飞翔。
#include<iostream>
#include<string>
using namespace std;

class Transformer//抽象构件类 变形金刚
{//抽象构件定义了对象接口，可以给这些对象动态增加职责。抽象构件是具体构件和抽象装饰类共同父类，它声明了具体构件中实现的业务方法。
public:
	virtual ~Transformer(){}
	virtual void move() = 0;
};

class Car :public Transformer//具体构件类
{//具体构件定义了具体的构件对象，实现了在抽象构件中声明的方法，装饰器可以给它增加额外的职责。
public:
	Car() { cout << "Be car" << endl; }
	void move() { cout << "Move on land" << endl; }
};

class Changer :public Transformer//抽象装饰类
{//抽象装饰类是抽象构件类的子类，用于给具体构件增加职责，当具体构件在其子类中实现。
public:
	Changer(Transformer* t):m_transformer(t){}
	virtual ~Changer() { delete m_transformer; }
private:
	Transformer* m_transformer;
};

class Robot :public Changer //具体装饰类
{//具体装饰器是抽象装饰类的子类，负责向构件增加新的职责，每一个具体装饰器类都定义了一些新的行为，它可以调用在抽象装饰器类中定义的方法，并可以增加新的方法以便扩充对象的行为。
public:
	Robot(Transformer* t) :Changer(t) { cout << "Turn into a robot" << endl; }
	void say() { cout << "say" << endl; }
	void move(){}
};
class Plane :public Changer
{
public:
	Plane(Transformer* t) :Changer(t) { cout << "Turn into a plane" << endl; }
	void fly() { cout << "fly" << endl; }
	void move(){}
};

int main()
{
	Transformer* gg = new Car();
	gg->move();

	Robot* robot = new Robot(gg);
	robot->move();
	robot->say();
}