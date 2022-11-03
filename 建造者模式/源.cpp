/*
* ���壺��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̾Ϳ��Դ�����ͬ�ı�ʾ��
* ������ģʽ��һ��һ������һ�����ӵĶ����������û�ֻͨ��ָ�����Ӷ�������ͺ����ݾͿ��Թ������ǣ��û�����Ҫ֪���ڲ��ľ��幹��ϸ�ڡ�
* ���Ӷ��󣺽�����ģʽ�У����Ӷ�����ָ��Щ���������Ա���ԵĶ�����Щ��Ա���Գ�Ϊ�������������������ʼ����������ˡ��ռ��ˡ����⡢���ݡ������Ȳ�����
* Ӧ�ã�����Ĵ������̶����ڴ����ö�����࣬�ڽ�����ģʽ��������ָ�����࣬���������̷�װ��ָ�������У������ڽ��������С�
* �ŵ㣺��1������Ʒ�������Ʒ�Ĵ������̽��ʹ��ͬ�Ĵ������̿��Դ�����ͬ�Ĳ�Ʒ����
��2�������µľ��彨������Ч�޸�ԭ�����Ĵ��룬ָ��������Գ����������̣�ϵͳ��չ���㡣
ȱ�㣺������ģʽ�������Ĳ�Ʒһ����н϶�Ĺ�ͬ�㣬��Ʒ����������ʺ�
*/
//���������������ʾ���룬�����˽�����̵ĳ��󣬵����µĶ���Ҫ�������ҽ��������ͬ�����Լ̳н�����ʵ���Լ��ľ����ʾ���ɡ�
//KFC �ײ�ʵ�����ײ���һ�����ӵĶ���һ���ײͰ�����ʳ�����ϵ���ɲ��֣����õ��ײ� ��ʳ�����ϵ����Ͳ�ͬ������Ա���Ը��ݹ˿͵�����һ�����������ײ͡�

#include<iostream>
#include<string>
using namespace std;

class Meal //��Ʒ�� ���Ӷ����������ԣ�
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

class Builder //�������� Ϊ����һ����ƷProduct����ĸ�������ָ������ӿ�
{//�ýӿ�һ���������ַ�����һ�෽�����ڴ������Ӷ���ĸ�����������һ�෽�����ڷ��ظ��Ӷ���
public:
	virtual void buildfood() = 0;
	virtual void builddrink() = 0;
	virtual Meal* getmeal() = 0;
	virtual ~Builder() {};
};

class A :public Builder //���彨���� ʵ���˳������߽ӿڣ�ʵ�ָ��������Ĺ����װ�䷽�������岢��ȷ���������ĸ��Ӷ���Ҳ�����ṩһ���������ش����õĸ��Ӳ�Ʒ����
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

class Director // ָ���� ������Ա��ָ���߸����Ÿ��Ӷ���Ľ������
{//ָ�������������֮����ڹ�����ϵ���ɵ��ý����߶���Ĳ�����װ�䷽������ɷ�չ����Ľ��졣�ͻ���һ��ֻ��Ҫ��ָ���߽�����
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
	Builder* mb = new B(); //ȷ���ײ����࣬��ѡȡ���� �����ײͽ����� mb��ʦ
	Director* waiter = new Director(); //�������Աָ����
	waiter->setBuilder(mb); //����Ա���� ָ��mb��ʦ
	waiter->construct();//����Աȡ�� mb��ʦ����B�ײ� ������
	Meal* meal = mb->getmeal();//�ͻ�����ײ�
	meal->getfood();
	meal->getdrink();

	delete mb; mb = nullptr;
	delete waiter; waiter = nullptr;
	delete meal; meal = nullptr;

	return 0;
}