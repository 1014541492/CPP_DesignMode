/*
* ģʽ������Ϊ��ʹ�����ʹ�ø������Ի��������������������Ҫ�ṩһ�����ơ����ҩ���Ļ��ƣ������ϵͳ���Իص������ǰ��״̬��
�����Ҫ�����û�ÿһ�β���ʱϵͳ��״̬��һ����������������԰Ѵ洢����ʷ״̬ȡ�����ɻص�֮ǰ��״̬��
���壺�ڲ��ƻ���װ��ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬�������������Ժ󽫶���ָ���ԭ�ȱ����״̬������һ�ֶ�����Ϊ��ģʽ
*����¼ģʽ�ĺ����Ǳ���¼���Լ����ڹ�����¼�ĸ�����������
* ���û���������һ��������ĳһ��ʱ�̵�ȫ��״̬�򲿷�״̬�������Ժ���Ҫʱ���ܹ��ָ�����ǰ��״̬��ʵ�ֳ���������
��ֹ�������ƻ�һ��������ʷ״̬�ķ�װ�ԣ����⽫������ʷ״̬��ʵ��ϸ�ڱ�¶��������
*�ŵ㣺1.���ṩ��һ��״̬�ָ���ʵ�ֻ��ƣ�ʹ���û����Է���ػص�һ���ض�����ʷ���裬���µ�״̬��Ч���ߴ�������ʱ������ʹ����ʱ�洢�����ı���¼��״̬��ԭ��
2.����¼ʵ���˶���Ϣ�ķ�װ��һ������¼������һ��ԭ��������״̬�ı�ʾ�����ᱻ�����������Ķ�������¼������ԭ������״̬�������б���ջ�ȼ������洢����¼�������ʵ�ֶ�γ���������
ȱ�㣺��Դ���Ĺ��������Ҫ�����ԭ������ĳ�Ա����̫�࣬�Ͳ��ɱ�����Ҫռ�ô����Ĵ洢�ռ䣬ÿ����һ�ζ����״̬����Ҫ����һ����ϵͳ��Դ��
*/

//ʵ������Ϸ���ȱ���
#include<iostream>
#include<vector>
using namespace std;

class Memento//����¼�� ����洢Originator������ڲ�״̬�������Է�ֹOrginator���������������ʱ���¼������¼�������ӿڣ�
	//�����ߣ�Caretaker)ֻ�ܿ�����¼��խ�ӿڣ���ֻ�ܽ�����¼���ݸ���������Originatorȴ���Կ�������¼�Ŀ�ӿڣ����������ʷ��ص���ǰ״̬����Ҫ���������ݡ�

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

class GameRole //(��Ϸ��ɫ) ��������
{//���𴴽�һ������¼��Memento�������Լ�¼��ǰʱ��������ڲ�״̬������ʹ�ñ���¼�ָ��ڲ�״̬�������˿��Ը�����Ҫ��������¼�洢�Լ�����Щ�ڲ�״̬��
private:
	int m_life;
	int m_attack;
	int m_defence;
public:
	GameRole():m_life(100),m_attack(100),m_defence(100){}
	Memento Save()//������ȣ�ֻ��Memento���󽻻������漰��caretaker
	{
		Memento memento(m_life, m_attack, m_defence);
		return memento;
	}
	void Load(Memento memento)//������ȣ�ֻ��Memento���󽻻������漰��caretaker
	{
		m_life = memento.m_life;
		m_attack = memento.m_attack;
		m_defence = memento.m_defence;
	}
	void show()
	{
		cout << "life:" << m_life << ",attack:" << m_attack << ",defence:" << m_defence << "��" << endl;
	}
	void Attack()
	{
		m_life = m_life - 10;
		m_attack = m_attack - 10;
		m_defence = m_defence - 10;
	}
};

class Caretaker ////����¼�Ĺ������࣬������ȵĵط�
{ // ���������¼Memento�����ܶ�Memento�����ݷ��ʻ��߲���
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
	caretaker.Save(role1.Save()); //�����ʼ�Ľ���

	role1.Attack();
	role1.show();

	role2 = role1;
	role2.show();

	role2.Load(caretaker.Load(0));
	role2.show();

}