/*
* 模式动机：在软件系统中，有些对象也像水一样具有多种状态，这些状态在某些情况下能够相互转换，而且对象在不同的状态下也将具有不同的行为。
为了更好地对这些具有多种状态的对象进行设计，我们将学习用于描述对象状态及其转换的状态模式。
*定义：允许一个对象在其内部状态改变时改变它的行为，对象看起来似乎修改了它的类。其别名为状态对象(Objects for States)，状态模式是一种对象行为型模式。
*状态模式用于解决系统中复杂对象的状态转换以及不同状态下行为的封装问题。状态模式将一个对象的状态从该对象中分离出来，封装到专门的状态类中，使得对象状态可以灵活变化，
对于客户端而言，无须关心对象状态的转换以及对象所处的当前状态，无论对于何种状态的对象，客户端都可以一致处理。
*模式分析：环境类实际上是真正拥有状态的对象，我们只是将环境类中与状态有关的代码提取出来封装到专门的状态类中。在状态模式结构图中，环境类Context与抽象状态类State之间存在单向关联关系，
在Context中定义了一个State对象。在实际使用时，它们之间可能存在更为复杂的关系，State与Context之间可能也存在依赖或者关联关系。
在状态模式的使用过程中，一个对象的状态之间还可以进行相互转换，通常有两种实现状态转换的方式：
(1) 统一由环境类来负责状态之间的转换，此时，它充当了状态管理器(State Manager)角色，在它的业务方法中通过对某些属性值的判断实现状态转换，还可以提供一个专门的方法用于实现属性判断和状态转换
(2) 由具体状态类来负责状态之间的转换，可以在其业务方法中判断环境类的某些属性值为它设置新的状态对象，实现状态转换，也可以提供一个专门的方法来负责属性判断和状态转换。此时，两者之间就存在依赖或关联关系

状态类的产生是由于环境类存在多个状态，同时还满足两个条件：这些状态经常需要切换，在不同的状态下对象的行为不同。因此可以将不同状态下的行为单独提取出来封装在具体的状态类中，
使得环境类对象在其内部状态改变时可以改变它的行为，对象看起来似乎修改了它的类，而实际上是通过切换到不同的具体状态类实现的。
由于环境类可以设置为任一具体状态类，因此它针对抽象状态类进行编程，在程序运行时可以将任一具体状态类的对象设置到环境类中，从而使得环境类可以改变内部状态，并且改变行为。

*优点：1.封装了状态的转换规则，在状态模式中可以将状态的转换代码封装在环境类或者具体状态类中，可以对状态转换代码进行集中管理，而不是分散在一个个业务方法中。
2.将所有与某个状态有关的行为放到一个类中，只需要注入一个不同的状态对象即可使环境对象拥有不同的行为。
3.允许状态转换逻辑与状态对象合成一体，而不是提供一个巨大的条件语句块，状态模式可以让我们避免使用庞大的条件语句来将业务方法和状态转换代码交织在一起。
4.可以让多个环境对象共享一个状态对象，从而减少系统中对象的个数。
缺点：1.状态模式的使用必然会增加系统中类和对象的个数，导致系统运行开销增大。
2.状态模式的结构与实现都较为复杂，如果使用不当将导致程序结构和代码的混乱，增加系统设计的难度。
3.状态模式对“开闭原则”的支持并不太好，增加新的状态类需要修改那些负责状态转换的源代码，否则无法转换到新增状态；而且修改某个状态类的行为也需修改对应类的源代码。

*适用环境：1.对象的行为依赖于它的状态（如某些属性值），状态的改变将导致行为的变化。
2.在代码中包含大量与对象状态有关的条件语句，这些条件语句的出现，会导致代码的可维护性和灵活性变差，不能方便地增加和删除状态，并且导致客户类与类库之间的耦合增强。

*/
#include<iostream>
using namespace std;
class War;
class State //抽象状态类，它用于定义一个接口以封装与环境类的一个特定状态相关的行为，在抽象状态类中声明了各种不同状态对应的方法，而在其子类中实现类这些方法，
{//由于不同状态下对象的行为可能不同，因此在不同子类中方法的实现可能存在不同，相同的方法可以写在抽象状态类中。
public:
	virtual void Prophase() {} //前期
	virtual void Metaphase() {}//中期
	virtual void Anaphase() {}//后期
	virtual void End() {}//结束
	virtual void CurrentState(War* war) {} //当前状态
};

class War //环境类，又称为上下文类，它是拥有多种状态的对象。
{//由于环境类的状态存在多样性且在不同状态下对象的行为有所不同，因此将状态独立出去形成单独的状态类。在环境类中维护一个抽象状态类State的实例，这个实例定义当前状态，在具体实现时，它是一个State子类的对象。
private:
	State* m_state;
	int m_days;
public:
	War(State *state):m_state(state),m_days(0){}
	~War() { delete m_state; }
	int GetDays() { return m_days; }
	void SetDays(int days) { m_days = days; }
	void SetState(State* state) { delete m_state; m_state = state; }
	void GetState() { m_state->CurrentState(this); }
};

class EndState :public State //具体状态类，它是抽象状态类的子类，每一个子类实现一个与环境类的一个状态相关的行为，每一个具体状态类对应环境的一个具体状态，不同的具体状态类其行为有所不同。
{
public:
	void End(War* war)//结束阶段的具体行为
	{
		cout << "战争结束" << endl;
	}
	void CurrentState(War* war) { End(war); }
};
class AnaphaseState : public State
{
public:
	void Anaphase(War* war)//后期的具体行为
	{
		if(war->GetDays()<30)
			cout << "第" << war->GetDays() << "天：战争后期，双方拼死一搏" << endl;
		else
		{
			war->SetState(new EndState());
			war->GetState();
		}
	}
	void CurrentState(War* war) { Anaphase(war); }
};
class MetaphaseState : public State
{
public:
	void Metaphase(War* war) //中期的具体行为
	{
		if (war->GetDays() < 20)
			cout << "第" << war->GetDays() << "天：战争中期，进入相持阶段，双发各有损耗" << endl;
		else
		{
			war->SetState(new AnaphaseState());
			war->GetState();
		}
	}
	void CurrentState(War* war) { Metaphase(war); }
};
class ProphaseState : public State 
{
public:
	void Prophase(War* war)//前期的具体行为
	{
		if(war->GetDays()<10)
			cout << "第" << war->GetDays() << "天：战争初期，双方你来我往，互相试探对方" << endl;
		else
		{
			war->SetState(new MetaphaseState());
			war->GetState();
		}
	}
	void CurrentState(War* war) { Prophase(war); }
};

int main()
{
	War* war = new War(new ProphaseState());
	for (int i=1; i< 40; i++)
	{
		war->SetDays(i);
		war->GetState();
	}
	delete war;
}