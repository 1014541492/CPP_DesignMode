/*
* װ��ģʽ��:��̬�ظ�һ����������һЩ�����ְ�𣬾����ӹ�����˵��װ��������������ʵ�ָ�Ϊ��
װ���������ڲ��ı������Ļ����ϸ��������Ӷ��������Ϊ��
*�ŵ� ��
��1��װ��ģʽ��̳й�ϵ��Ŀ�Ķ�����չ����Ĺ��ܣ�����װ����ģʽ�����ṩ�ȼ̳и��������ԣ�
��2������ͨ��һ�ֶ�̬�ķ�ʽ��չһ������Ĺ��ܣ�ͨ�������ļ�����������ʱѡ��ͬ��װ�������Ӷ�ʵ�ֲ�ͬ����Ϊ��
��3�����Ͽ���ԭ�򣬾��幹����;���װ������Զ����仯���û����Ը�����Ҫ�����µľ��幹����;���װ���ࡣ
ȱ�㣺
��1������ϵͳ�ĸ��Ӷȡ�ʹ��װ��ģʽ����ϵͳ���ʱ������ܶ�С������ЩС�����������������֮���໥���ӵķ�ʽ������ͬ�����������ǵ��������ֵ������ͬ��ͬʱ�����ܶ����װ���ࡣ
��2��װ��ģʽ�ȼ̳и������ڳ����Ų��������ѡ�
*Ӧ�ã�
��1���ڲ�Ӱ���������������£��Զ�̬��͸���ķ�ʽ�������������ְ��
��2����Ҫ��̬�ظ�һ���������ӹ��ܣ���Щ����Ҳ���Ա�������
*/

//���������ν���ڱ���֮ǰ��һ������������½���ƶ�������ɻ����˺������½���ƶ�������˵��������ɷɻ�ʱ��������½���ƶ������Է��衣
#include<iostream>
#include<string>
using namespace std;

class Transformer//���󹹼��� ���ν��
{//���󹹼������˶���ӿڣ����Ը���Щ����̬����ְ�𡣳��󹹼��Ǿ��幹���ͳ���װ���๲ͬ���࣬�������˾��幹����ʵ�ֵ�ҵ�񷽷���
public:
	virtual ~Transformer(){}
	virtual void move() = 0;
};

class Car :public Transformer//���幹����
{//���幹�������˾���Ĺ�������ʵ�����ڳ��󹹼��������ķ�����װ�������Ը������Ӷ����ְ��
public:
	Car() { cout << "Be car" << endl; }
	void move() { cout << "Move on land" << endl; }
};

class Changer :public Transformer//����װ����
{//����װ�����ǳ��󹹼�������࣬���ڸ����幹������ְ�𣬵����幹������������ʵ�֡�
public:
	Changer(Transformer* t):m_transformer(t){}
	virtual ~Changer() { delete m_transformer; }
private:
	Transformer* m_transformer;
};

class Robot :public Changer //����װ����
{//����װ�����ǳ���װ��������࣬�����򹹼������µ�ְ��ÿһ������װ�����඼������һЩ�µ���Ϊ�������Ե����ڳ���װ�������ж���ķ����������������µķ����Ա�����������Ϊ��
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