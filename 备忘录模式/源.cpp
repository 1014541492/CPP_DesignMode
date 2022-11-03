/*
* 模式动机：为了使软件的使用更加人性化，对于误操作，我们需要提供一种类似“后悔药”的机制，让软件系统可以回到误操作前的状态，
因此需要保存用户每一次操作时系统的状态，一旦出现误操作，可以把存储的历史状态取出即可回到之前的状态。
定义：在不破坏封装的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，这样可以在以后将对象恢复到原先保存的状态。它是一种对象行为型模式
*备忘录模式的核心是备忘录类以及用于管理备忘录的负责人类的设计
* 适用环境：保存一个对象在某一个时刻的全部状态或部分状态，这样以后需要时它能够恢复到先前的状态，实现撤销操作。
防止外界对象破坏一个对象历史状态的封装性，避免将对象历史状态的实现细节暴露给外界对象。
*优点：1.它提供了一种状态恢复的实现机制，使得用户可以方便地回到一个特定的历史步骤，当新的状态无效或者存在问题时，可以使用暂时存储起来的备忘录将状态复原。
2.备忘录实现了对信息的封装，一个备忘录对象是一种原发器对象状态的表示，不会被其他代码所改动。备忘录保存了原发器的状态，采用列表、堆栈等集合来存储备忘录对象可以实现多次撤销操作。
缺点：资源消耗过大，如果需要保存的原发器类的成员变量太多，就不可避免需要占用大量的存储空间，每保存一次对象的状态都需要消耗一定的系统资源。
*/

//实例：游戏进度保存
#include<iostream>
#include<vector>
using namespace std;

class Memento//备忘录类 负责存储Originator对象的内部状态，并可以防止Orginator以外的其他对象访问备忘录，备忘录有两个接口：
	//管理者（Caretaker)只能看备忘录的窄接口，他只能将备忘录传递给其他对象。Originator却可以看到备忘录的宽接口，允许他访问返回到先前状态所需要的所有数据。

{
public:
	int m_life;
	int m_attack;
	int m_defence;
	Memento(int life, int attack, int defence) :m_life(life), m_attack(attack), m_defence(defence){}
	Memento& operator=(const Memento& memento)
	{
		m_life = memento.m_life;
		m_attack = memento.m_attack;
		m_defence = memento.m_defence;
		return *this;
	}
};

class GameRole //(游戏角色) 发起者类
{//负责创建一个备忘录（Memento），用以记录当前时刻自身的内部状态，并可使用备忘录恢复内部状态。发起人可以根据需要决定备忘录存储自己的哪些内部状态。
private:
	int m_life;
	int m_attack;
	int m_defence;
public:
	GameRole():m_life(100),m_attack(100),m_defence(100){}
	Memento Save()//保存进度，只与Memento对象交互，不涉及到caretaker
	{
		Memento memento(m_life, m_attack, m_defence);
		return memento;
	}
	void Load(Memento memento)//载入进度，只与Memento对象交互，不涉及到caretaker
	{
		m_life = memento.m_life;
		m_attack = memento.m_attack;
		m_defence = memento.m_defence;
	}
	void show()
	{
		cout << "life:" << m_life << ",attack:" << m_attack << ",defence:" << m_defence << "。" << endl;
	}
	void Attack()
	{
		m_life = m_life - 10;
		m_attack = m_attack - 10;
		m_defence = m_defence - 10;
	}
};

class Caretaker ////备忘录的管理者类，保存进度的地方
{ // 负责管理备忘录Memento，不能对Memento的内容访问或者操作
private:
	vector<Memento> m_menento;
public:
	void Save(Memento memento)
	{
		m_menento.push_back(memento);
	}
	Memento Load(int state)
	{
		return m_menento[state];
	}
};

int main()
{
	Caretaker caretaker;
	GameRole role1, role2;
	role1.show();
	caretaker.Save(role1.Save()); //保存最开始的进度

	role1.Attack();
	role1.show();

	role2 = role1;
	role2.show();

	role2.Load(caretaker.Load(0));
	role2.show();

}