/*
* ģʽ����������ϵͳ�е�ĳЩ�����п��ܴ��ڶ��ֲ�ͬ���͵�Ԫ�أ����Ҳ�ͬ�ĵ�����ʹ����ЩԪ��ʱҲ����������Щ�����߳�Ϊ�����ߡ�
* ���壺��ʾһ��������ĳ����ṹ�и�Ԫ�صĲ�������ʹ���ǿ����ڲ��ı��Ԫ�ص����ǰ���¶�����������ЩԪ�ص��²�����
* Ӧ�ó�����
1.������ģʽ���������ݽṹ����ȶ���ϵͳ
2.�������ݽṹ�����������ݽṹ֮�ϵĲ���֮�����Ͻ��ѿ���ʹ�ò������Ͽ���������ɵ��ݻ���
3.������ģʽ��Ŀ����Ҫ�Ѵ�������ݽṹ������������������ϵͳ�бȽ��ȶ������ݽṹ����������仯���㷨�Ļ���ʹ�÷�����ģʽ���ǱȽϺ��ʵģ���Ϊ������ģʽʹ���㷨���������ӱ�ø����ס���֮��Ȼ��
*������ģʽ�ж���ṹ�洢�˲�ͬ���͵�Ԫ�ض������ṩ��ͬ�����߷��ʡ�
������ģʽ����������νṹ��һ���Ƿ����߲�νṹ���ṩ�˳�������ߺ;�������ߣ�һ����Ԫ�ز�νṹ���ṩ�˳���Ԫ�غ;���Ԫ�ء�
��ͬ�ķ����߿����Բ�ͬ�ķ�ʽ���ʲ�ͬ��Ԫ�أ���ͬ��Ԫ�ؿ��Խ��ܲ�ͬ�������Բ�ͬ�ķ�ʽ���ʡ�
*�ŵ㣺���µĲ��������ף���Ϊ�����µĲ�������ζ������һ���µķ����ߡ�������ģʽ���йص���Ϊ���е�һ�������߶����С�
ȱ�㣺ʹ�����µ�Ԫ���������ѡ��ڷ�����ģʽ�У�ÿ����һ���µ�Ԫ�ض���ζ��Ҫ�ڳ�������߽�ɫ������һ���µĳ������������ÿһ�������������������Ӧ�ľ��������Υ��������ԭ�򡱵�Ҫ��
*/

#include<iostream>
#include<vector>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor//���������  �����˷���Ԫ�ض���ķ�����ͨ��Ϊÿһ�����͵�Ԫ�ض����ṩһ�����ʷ���
{
public:
	virtual void VisitConcreteElementA(ConcreteElementA *pElementA) = 0;
	virtual void VisitConcreteElementB(ConcreteElementB *pElementB) = 0;
};

class ConcreteVisitor1 :public Visitor//��������� ���ڶ���Բ�ͬ����Ԫ�ض���Ĳ���
{//���������ʵ����ÿ���ɳ�������������Ĳ�����ÿһ���������ڷ��ʶ���ṹ��һ��Ԫ�����͵�Ԫ�ء�
public:
	void VisitConcreteElementA(ConcreteElementA* pElementA)
	{
		cout << "������1����Ԫ��A" << endl;
	}
	void VisitConcreteElementB(ConcreteElementB* pElementB)
	{
		cout << "������1����Ԫ��B" << endl;
	}
};
class ConcreteVisitor2 :public Visitor
{
public:
	void VisitConcreteElementA(ConcreteElementA* pElementA)
	{
		cout << "������2����Ԫ��A" << endl;
	}
	void VisitConcreteElementB(ConcreteElementB* pElementB)
	{
		cout << "������2����Ԫ��B" << endl;
	}
};

class Element//����Ԫ���� ����accept()���������ڽ��ܷ����ߵķ���
{//����Ԫ��һ���ǳ������ӿڣ�����һ��accept()�������÷�����һ�������������Ϊ������
public:
	virtual void Accept(Visitor* pVisitor) = 0;
};

class ConcreteElementA :public Element //����Ԫ���� ͨ������Visitor���visit()����ʵ�ֶ�Ԫ�صķ���
{
public:
	void Accept(Visitor* pVisitor)
	{
		pVisitor->VisitConcreteElementA(this);//ͨ������visitor����� visit()����ʵ�ֶ�Ԫ�ض���ķ���
	}
};
class ConcreteElementB :public Element
{
public:
	void Accept(Visitor* pVisitor)
	{
		pVisitor->VisitConcreteElementB(this);
	}
};

class ObjectStructure//ObjectStructure��(����ṹ��)����ö������Ԫ�أ������ṩһ���߲�Ľӿ�����������߷�������Ԫ��
{//����ṹ��һ��Ԫ�صļ��ϣ������ڴ��Ԫ�ض��󣬲����ṩ�˱������ڲ�Ԫ�صķ�����
public:
	void Attach(Element* pElement)
	{
		elements.push_back(pElement);
	}
	void Detach(Element* pElement)
	{
		vector<Element*>::iterator it = find(elements.begin(), elements.end(), pElement);
		if (it != elements.end())
		{
			elements.erase(it);
		}
	}
	void Accept(Visitor* pVisitor)//// Ϊÿһ��element����visitor�����ж�Ӧ�Ĳ���
	{
		for(vector<Element*>::const_iterator it=elements.begin();it!=elements.end();++it)//const_iterator�����ͣ�������ֻ�����ڶ�ȡ�����ڵ�Ԫ�أ������ܸı���ֵ
		{
			(*it)->Accept(pVisitor);
		}
	}
protected:
	vector<Element*>elements;
};

int main()
{
	ObjectStructure* p_object = new ObjectStructure; //ʵ��������ṹ�����ڴ��Ԫ�ض����ṩ�������ڲ�Ԫ�صķ���
	
	//ʵ��������Ԫ�� ���������õ�Ԫ�ط������ṹ��
	ConcreteElementA* pElementA = new ConcreteElementA;
	ConcreteElementB* pElementB = new ConcreteElementB;
	p_object->Attach(pElementA);
	p_object->Attach(pElementB);

	ConcreteVisitor1* visitor1 = new ConcreteVisitor1;//ʵ����������
	ConcreteVisitor2* visitor2 = new ConcreteVisitor2;

	p_object->Accept(visitor1);
	p_object->Accept(visitor2);
}