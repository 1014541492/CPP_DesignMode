#pragma once
class FlyWeight //Flyweight��������Ԫ�ࣩ
{ //����һ���ӿڣ�ͨ������ӿ�flyweight���Խ��ܲ��������ⲿ״̬��������Ԫ���ж����˾�����Ԫ�๫���ķ�����
//��Щ��������������ṩ��Ԫ������ڲ����ݣ��ڲ�״̬����ͬʱҲ����ͨ����Щ���������ⲿ���ݣ��ⲿ״̬����
public:
	FlyWeight(){}
	virtual ~FlyWeight(){}//����������Ԫ�๲�еķ���
	virtual void operation() = 0;
};

class ConcreteFlyWeight :public FlyWeight //ConcreteFlyweight��������Ԫ�ࣩ
{//������Ԫ��ʵ���˳�����Ԫ�ӿڣ���ʵ����Ϊ��Ԫ���󡣾�����Ԫ��������ǿ��Թ���ġ�
public:
	ConcreteFlyWeight(){}
	~ConcreteFlyWeight(){}
	void operation();//������Ԫ��ʵ�����ڳ�����Ԫ���������ķ���
};