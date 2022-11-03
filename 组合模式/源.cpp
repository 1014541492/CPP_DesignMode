/*
* ���ģʽ����϶�������γ����νṹ�Ա�ʾ������-���塱�Ľṹ��Ρ�
* ģʽӦ�ã���1����Ҫ��ʾһ�����������򲿷ֲ�Σ��ھ�������Ͳ��ֵĲ�νṹ�У�ͨ������ģʽ�ɺ��������벿�ֵĲ��졣
            ��2��ϣ�����Ե����������϶���Ĳ�ͬ, �ͻ��˽�ͳһ��ʹ����Ͻṹ�е����ж���.
*�ŵ㣺
��1�����ģʽ��������ض���ֲ�ĸ��Ӷ��󣬿��Է���ضԲ�νṹ���п��ƣ�
��2���ͻ��˵��ü򵥣��û����ع��Ĵ�����ǵ���������������Ͻṹ�����˿ͻ��˴��룻
��3��������Ҷ�Ӷ������������Ҷ�Ӷ����������������γɸ��ӵ����νṹ��
*ȱ�㣺
��1��ʹ����Ƹ��ӳ���
��2�������µĹ���ʱ���ܻ����һЩ���⣻
*/

/*
* ʹ�����ģʽʱ�����ݳ��󹹼���Ķ�����ʽ�����ǿɽ����ģʽ��Ϊ͸�����ģʽ�Ͱ�ȫ���ģʽ������ʽ
* ��1��͸�����ģʽ
���󹹼���ɫ���������������ڹ����Ա����ķ�����������ʾ����Component ������ add��remove ��process �������������ĺô���ȷ�����еĹ����඼����ͬ�Ľӿڡ�͸�����ģʽҲ�����ģʽ�ı�׼��ʽ��
͸�����ģʽ��ȱ���ǲ�����ȫ����ΪҶ�Ӷ�������������ڱ�������������ģ�Ҷ�Ӷ��󲻿�������һ����εĶ��󣬼������ܰ�����Ա����
���Ϊ���ṩ add()��remove() �ȷ�����û������ģ����ڱ���׶β�������������н׶����������Щ�������ܻ�������û���ṩ��Ӧ�Ĵ�������룩
��2����ȫ���ģʽ�У��ڳ��󹹼���ɫ��û�������κ����ڹ����Ա����ķ�����������������������֦�ڵ㣩����������ʵ����Щ������
��ȫ���ģʽ��ȱ���ǲ���͸������ΪҶ�ӹ����������������в�ͬ�ķ�������������������Щ���ڹ����Ա����ķ���û���ڳ��󹹼����ж��壬
��˿ͻ��˲�����ȫ��Գ����̣�����������ضԴ�Ҷ�ӹ���������������
*/


//ʵ����ˮ���̣�Plate������һЩˮ������ƻ�����㽶�����ӵȣ���ˮ�����ﻹ������Сˮ���̣�������Ҫ��ˮ�����б����ԡ�
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class MyElement //����Ĳ�����MyElement ��д��������ȫ��������ͬӵ�е���Ϊ(͸�����ģʽ)
{//���󹹼������ǽӿڻ�����࣬ΪҶ�ӹ����������������������ӿڣ��ڸý�ɫ�п��԰����������๲�е�������ʵ�֡�
    //�ڳ��󹹼��ж����˷��ʼ����������ӹ����ķ������������ӹ�����ɾ���ӹ�������ȡ�ӹ����ȡ�
public:
    MyElement(const string& name) :m_name(name) {}
    virtual ~MyElement() {}
    virtual void eat() = 0;
    virtual void add(MyElement*) = 0;
    virtual void remove(MyElement*) = 0;
    virtual const string& getName() { return m_name; }
protected:
    string m_name;
};

class Apple :public MyElement //Ҷ�ӽڵ����Ҷ�ӹ�����
    //�����ʵ��Ҷ�Ӷ������Ϊ�����ٰ����������ӽڵ����Ҷ�ӹ�������Ͻṹ�б�ʾҶ�ӽڵ����Ҷ�ӽڵ�û���ӽڵ㣬��ʵ�����ڳ��󹹼��ж������Ϊ��
{
public:
    Apple(const string& name) : MyElement(name) {}//����̳и����вι���
    virtual ~Apple(){}
    void eat() { cout << "eat apple!" << endl; }
    void add(MyElement* p){}     //Ҷ�ӽ�㲻��Ҫ����ɾ������������ֹ��������� Ҫд��
    void remove(MyElement* p){}
};
class Banana :public MyElement
{
public:
    Banana(const string& name) : MyElement(name) {}//����̳и����вι���
    virtual ~Banana() {}
    void eat() { cout << "eat banana!" << endl; }
    void add(MyElement* p) {}     //Ҷ�ӽ�㲻��Ҫ����ɾ������������ֹ��������� Ҫд��
    void remove(MyElement* p) {}
};
class Pear :public MyElement
{
public:
    Pear(const string& name) : MyElement(name) {}//����̳и����вι���
    virtual ~Pear() {}
    void eat() { cout << "eat pear!" << endl; }
    void add(MyElement* p) {}     //Ҷ�ӽ�㲻��Ҫ����ɾ������������ֹ��������� Ҫд��
    void remove(MyElement* p) {}
};

class Plate:public MyElement//��϶�������������
//������������Ͻṹ�б�ʾ�����ڵ���������ڵ�����ӽڵ㣬���ӽڵ������Ҷ�ӽڵ㣬Ҳ�����������ڵ㣬
//���ṩ��һ���������ڴ洢�ӽڵ㣬��ʵ�����ڳ��󹹼��ж������Ϊ��������Щ���ʼ������ӹ����ķ�����
{
public:
    Plate(const string&name):MyElement(name){}
    virtual ~Plate()
    {
        vector<MyElement*>::iterator it = m.begin();
        while (it!=m.end())
        {
            if (*it != NULL)
            {
                delete* it;
                *it = NULL;
            }
            m.erase(it);
            it = m.begin();
        }
    }
    void eat()
    {
        for (auto iter : m) { iter->eat(); } //��ȡ�����������е�ֵ��ʹ��auto iterʱ���������������ɸı�,ʹ��auto &iter,����iter���κ��޸Ľ�ֱ���޸������ڶ�Ӧ��ֵ��
    }
    void add(MyElement* p) { m.push_back(p); }
    void remove(MyElement* p)
    {
        for (vector<MyElement*>::iterator it = m.begin(); it != m.end(); ++it)
        {
            if ((*it)->getName() == p->getName())
            {
                if (*it != NULL)
                {
                    delete* it;
                    *it = NULL;
                }
                m.erase(it);
                break;
            }
            
        }
    }
private:
    vector<MyElement*> m;
};


int main()
{
    MyElement* obj1 = new Apple("a");
    MyElement* obj2 = new Banana("b");
    MyElement* plate1 = new Plate("c");
    plate1->add(obj1);
    plate1->add(obj2);
    MyElement* obj3 = new Pear("d");
    MyElement* plate2 = new Plate("e");
    plate2->add(obj3);
    plate1->add(plate2);
    plate1->eat();

    plate1->remove(obj1);
    plate1->eat();

    plate2->eat();

    delete plate1;
    plate1 = nullptr;

}

