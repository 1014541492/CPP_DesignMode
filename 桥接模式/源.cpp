/*
* 桥接模式：将抽象部分与它的实现部分分离，使它们都可以独立地变化。是一种对象结构模式。
将抽象与实现分离，使它们可以独立变化。它是用关联关系（组合或聚合关系）代替继承关系来实现，从而降低了抽象和实现这两个可变维度的耦合度。
如何理解桥接： 像桥梁一样的，对象和对象像桥梁一样的连接。
如：形状-抽象类，颜色-抽象类，如何让他们像一个桥一样，产生关系？形状拥有了颜色 这样产生了关系。
* 
* 应用：当一个类内部具备两种或多种变化维度时，使用桥接模式可以解耦这些变化的维度，使高层代码架构稳定。桥接模式通常适用于以下场景。
1.当一个类存在两个独立变化的维度，且这两个维度都需要进行扩展时。
2.当一个系统不希望使用继承或因为多层次继承导致系统类的个数急剧增加时。
3.当一个系统需要在构件的抽象化角色和具体化角色之间增加更多的灵活性时

* 优点：
（1）分离抽象类及其实现部分。桥接模式使用“对象间的关联关系”解耦了抽象和实现之间 固有的绑定关系，使得抽象和实现可以沿着各自的维度来变化。
（2）桥接模式是比多继承方案更好的解决方法。
（3）桥接模式提高了系统的可扩展性，在两个变化维度中任意扩展一个维度，都不需要修改原有的系统。
（4）实现细节对客户透明，可以对用户隐藏实现细节。用户在使用时不需要关系实现，在抽象层通过聚合关联关系完成封装与对象组合。

缺点：
（1）桥接模式的引入会增加系统的理解与设计难度。聚合关系建立在抽象层，要求开发者针对抽象进行设计与编程。
（2）桥接模式要求正确识别出系统的两个独立变化的维度，因此使用范围具有一定的局限性。
* 
*/


//实例：如手机支付方式微信、支付宝APP，而每种APP支持三种付款验证方式，密码、指纹、人脸，则桥接模式的实现方式如下：
//IPayMode类是实现类，定义了基本操作security()，用于设置验证方式，其子类提供了实现，它位于桥接模式的抽象层。

#include<iostream>
#include<string>
using namespace std;

class IPayMode //实现类接口：为所有具体实现声明通用接口。抽象部分仅能通过在这里声明的方法与实现对象交互
{
public:
	virtual bool security(string uid) = 0;
};

class PayCypher : public IPayMode //具体实现类：
{
public:
	bool security(string uid) override
	{
		cout << "Password to pay" << endl;
		return true;
	}
};
class PayFace :public IPayMode
{
public:
	bool security(string uid)override
	{
		cout << "Face to pay" << endl;
		return true;
	}
};
class PayFinger :public IPayMode
{
public:
	bool security(string uid)override
	{
		cout << "Finger to pay" << endl;
		return true;
	}
};

class Pay//抽象类 用于定义抽象类的接口，其中定义了一个Implementation（实现类接口）的对象并可以维护该对象，它与 Implementation具有关联关系。
{
public:
	Pay(IPayMode* mode) //抽象类中的mode与实现类接口IPayMode存在关联
	{
		this->mode = mode;
	}
	virtual ~Pay() { delete mode; }
	virtual string transfer(string UID, string ID, long long amount) = 0;

	IPayMode* mode;
};

class WxPay :public Pay //扩充抽象类：扩充由Abstraction定义的接口，通常它不再是抽象类而是具体类。提供控制逻辑的变体。与其父类一样，它们通过通用实现接口与不同的实现进行交互
{                       //提供高层控制逻辑，依赖于完成底层实际工作的实现对像
public:
	WxPay(IPayMode* mode) :Pay(mode){}
	string transfer(string UID, string ID, long long amount)
	{
		cout << "VxPay " << "UID:" << UID << "ID:" << ID << "amount:" << amount << endl;
		bool security = mode->security(UID);
		if (!security)
		{
			cout << "WxPay Failed" << endl;
			return "0001";
		}
		else
		{
			cout << "WxPay Succeed" << endl;
			return"0000";
		}
	}
};
class ZfbPay :public Pay
{
public:
	ZfbPay(IPayMode* mode) :Pay(mode) {}
	string transfer(string UID, string ID, long long amount)
	{
		cout << "ZfbPay " << "UID:" << UID << "ID:" << ID << "amount:" << amount << endl;
		bool security = mode->security(UID);
		if (!security)
		{
			cout << "ZfbPay Failed" << endl;
			return "0001";
		}
		else
		{
			cout << "ZfbPay Succeed" << endl;
			return"0000";
		}
	}
};

int main() //客户端 仅关心如何与抽象部分合作。但是，Client需要将抽象对象与一个实现对象连接起来。
{
	Pay* wx = new WxPay(new PayFace());
	wx->transfer("wx", "123456", 100);
	cout << endl;
	Pay* zfb = new ZfbPay(new PayCypher());
	zfb->transfer("zfb", "666", 200);
}



//override重写关键词，它在C++中可以检测哪些虚函数没有被重写并报错
//注：在派生类的成员函数中使用override时，如果基类中无此函数，或基类中的函数并不是虚函数，编译器会给出相关错误信息。

//单一职责原则：对于一个类，只有一个引起该类变化的原因；该类的职责是唯一的，且这个职责是唯一引起其他类变化的原因。
//目的：降低代码复杂度、系统解耦合、提高可读性
//解决：将不同的职责封装到不同的类或者模块中。 当有新的需求将现有的职责分为颗粒度更小的职责的时候，应该及时对现有代码进行重构，
//当系统逻辑足够简单，方法足够少，子类够少或后续关联够少时，也可以不必严格遵循你SRP原则，避免过度设计、颗粒化过于严重。