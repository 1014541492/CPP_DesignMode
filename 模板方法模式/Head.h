#pragma once
class Fundamental//�����ඨ����һϵ�л�����������Щ�������������Ǿ���ģ�Ҳ�����ǳ���ģ�ÿһ������������Ӧ�㷨��һ�����裬���������п����ض����ʵ����Щ���衣
	//ͬʱ�������໹ʵ����һ��ģ�巽�������ڶ���һ���㷨�Ŀ�ܣ�ģ�巽���������Ե����ڳ�������ʵ�ֵĻ���������Ҳ���Ե����ڳ������������ʵ�ֵĻ��������������Ե������������еķ�����
{
public:
	virtual void primitiveOperation1();
	virtual void primitiveOperation2();
	void templateMethod();
	virtual ~Fundamental();
};

class ConcreteClassA :public Fundamental //���������ǳ���������࣬����ʵ���ڳ������������ĳ��������������������ض��㷨�Ĳ��裬Ҳ���Ը����ڸ������Ѿ�ʵ�ֵľ������������
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