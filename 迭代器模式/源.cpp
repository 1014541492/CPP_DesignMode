/*
* ģʽ����������������У�Ҳ���ڴ������Ƶ��ӻ�һ�����࣬���ǿ��Դ洢�����Ա����Ԫ�أ�����Щ��ͨ����Ϊ�ۺ���(Aggregate Classes)����Ӧ�Ķ����Ϊ�ۺ϶���
�ۺ϶���ӵ������ְ��һ�Ǵ洢���ݣ����Ǳ������ݡ���������������ǰ���Ǿۺ϶���Ļ���ְ�𣻶����߼��ǿɱ仯�ģ����ǿɷ���ġ�
��ˣ����Ǳ��յ��ӻ�ң�����Ĺ��ܽ�ɫ�����������ݵ���Ϊ�Ӿۺ϶����з����������װ��һ������֮Ϊ�����������Ķ����У��ɵ��������ṩ�����ۺ϶����ڲ����ݵ���Ϊ���⽫�򻯾ۺ϶������ƣ������ϡ���һְ��ԭ�򡱵�Ҫ��
ͬʱ����������Ϊ�ۺ϶������Ӳ�ͬ�ı��������������Է���һ���ۺ϶����е�Ԫ�ص��ֲ���Ҫ��¶�����ڲ��ṹ��
*ģʽ���壺������ģʽ(Iterator Pattern) ���ṩһ�ַ��������ʾۺ϶��󣬶����ñ�¶���������ڲ���ʾ�������Ϊ�α�(Cursor)��������ģʽ��һ�ֶ�����Ϊ��ģʽ��
�ڵ�����ģʽ�ṹ�а����ۺϺ͵�����������νṹ�����ǵ�ϵͳ������ԺͿ���չ�ԣ��ڵ�����ģʽ��Ӧ���˹�������ģʽ
*ģʽ�������ڵ�����ģʽ�У��ṩ��һ���ⲿ�ĵ��������Ծۺ϶�����з��ʺͱ�����������������һ�����ʸþۺ�Ԫ�صĽӿڣ����ҿ��Ը��ٵ�ǰ������Ԫ�أ��˽���ЩԪ���Ѿ�����������Щû�С�
�����������룬��ʹ�ö�һ�����Ӿۺ϶���Ĳ�����ü򵥡��ڵ�����ģʽ��Ӧ���˹�������ģʽ�������������Ӧ�ڳ����Ʒ��ɫ�������������Ӧ�ھ����Ʒ��ɫ������ۺ����Ӧ�ڳ��󹤳���ɫ������ۺ����Ӧ�ھ��幤����ɫ��
��Ҫע����ǳ���������ӿڵ���Ʒǳ���Ҫ��һ������Ҫ���������ֱ���������Ҫ�󣬾���Ϊ���ֱ����������ṩ��������һ�����ֲ��ܰ���̫�෽�����ӿ��з���̫�ཫ�������ʵ�ִ����鷳��
��ˣ����Կ���ʹ�ó���������Ƴ�����������ڳ�������Ϊÿһ�������ṩһ���յ�Ĭ��ʵ�֡������Ҫ�ھ����������Ϊ�ۺ϶�������ȫ�µı���������������޸ĳ���������;����������Դ���룬�⽫Υ��������ԭ�򡱣�
��������ʱҪ����ȫ�棬����֮���޸Ľӿڡ������������;���ۺ���֮�����˫�ع�ϵ������һ����ϵΪ������ϵ���ھ������������Ҫά��һ���Ծ���ۺ϶�������ã��ù�����ϵ��Ŀ���Ƿ��ʴ洢�ھۺ϶����е����ݣ�
�Ա�������ܹ�����Щ���ݽ��б�������������ʹ�ù�����ϵ�⣬Ϊ���ܹ��õ��������Է��ʵ��ۺ϶����е����ݣ����ǻ����Խ������������Ϊ�ۺ�����ڲ���
*���û�����1.����һ���ۺ϶�������ݶ����뱩¶�����ڲ���ʾ�����ۺ϶���ķ������ڲ����ݵĴ洢���룬ʹ�÷��ʾۺ϶���ʱ�����˽����ڲ�ʵ��ϸ�ڡ�
2.��ҪΪһ���ۺ϶����ṩ���ֱ�����ʽ��
3.Ϊ������ͬ�ľۺϽṹ�ṩһ��ͳһ�Ľӿڣ��ڸýӿڵ�ʵ������Ϊ��ͬ�ľۺϽṹ�ṩ��ͬ�ı�����ʽ�����ͻ��˿���һ���Եز����ýӿڡ�
*�ŵ㣺1.֧���Բ�ͬ�ķ�ʽ����һ���ۺ϶�����ͬһ���ۺ϶����Ͽ��Զ�����ֱ�����ʽ���ڵ�����ģʽ��ֻ��Ҫ��һ����ͬ�ĵ��������滻ԭ�е��������ɸı�����㷨������Ҳ�����Լ������������������֧���µı�����ʽ��
2.���������˾ۺ��ࡣ���������˵���������ԭ�еľۺ϶����в���Ҫ�������ṩ���ݱ����ȷ������������Լ򻯾ۺ������ơ�
�ڵ�����ģʽ�У����������˳���㣬�����µľۺ���͵������඼�ܷ��㣬�����޸�ԭ�д��룬���㡰����ԭ�򡱵�Ҫ��
ȱ�㣺1.���ڵ�����ģʽ���洢���ݺͱ������ݵ�ְ����룬�����µľۺ�����Ҫ��Ӧ�����µĵ������࣬��ĸ����ɶ����ӣ�����һ���̶���������ϵͳ�ĸ����ԡ�
2.���������������ѶȽϴ���Ҫ��ֿ��ǵ�ϵͳ��������չ
*/

//�ڵ�����ģʽ����Ҫ��Ϊ������Ҫ���֣�
//�������֣��ڲ����Դ��һϵ�����ݣ����ṩ���������ýӿڡ�
//���������֣��ڲ����ж��������ֵĵ��ã�����������ڲ��ṩ�ķ�����
//���������;���������������໥���õģ�Ҳ����˵���������˵�������Ȼ��ͨ�������������������ڲ�����ķ�����ʵ�ַ�װ��

#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Iterator //�����������
{//�����˷��ʺͱ���Ԫ�صĽӿڣ���������Ӧ�������磺���ڻ�ȡ��һ��Ԫ�ص�first()���������ڷ�����һ��Ԫ�ص�next()�����������ж��Ƿ�����һ��Ԫ�ص�hasNext()���������ڻ�ȡ��ǰԪ�ص�currentItem()�����ȣ��ھ���������н�ʵ����Щ������
public:
    Iterator() {};
    virtual ~Iterator() {};
    virtual string First() = 0;
    virtual string Next() = 0;
    virtual string GetCur() = 0;
    virtual bool IsEnd() = 0;
};

class Aggregate //����ۺ���
{//���ڴ洢�͹���Ԫ�ض�������һ��createIterator()�������ڴ���һ�����������󣬳䵱���������������ɫ��
public:
    Aggregate() {};
    virtual ~Aggregate() {};
    virtual int Count() = 0;
    virtual void Push(const string& strValue) = 0;
    virtual string Pop(const int index) = 0;
    virtual Iterator* CreateIterator() = 0;
};

class ConcreteIterator : public Iterator //�����������
{//ʵ���˳���������ӿڣ���ɶԾۺ϶���ı�����ͬʱ�ھ����������ͨ���α�����¼�ھۺ϶����������ĵ�ǰλ�ã��ھ���ʵ��ʱ���α�ͨ����һ����ʾλ�õķǸ�������
public:
    ConcreteIterator(Aggregate* pAggregate) : Iterator()
    {
        m_nCurrent = 0;
        m_Aggregate = pAggregate;
    }

    string First()
    {
        return m_Aggregate->Pop(0);
    }

    string Next()
    {
        string strRet;
        m_nCurrent++;

        if (m_nCurrent < m_Aggregate->Count())
        {
            strRet = m_Aggregate->Pop(m_nCurrent);
        }

        return strRet;
    }

    string GetCur()
    {
        return m_Aggregate->Pop(m_nCurrent);
    }

    bool IsEnd()
    {
        return ((m_nCurrent >= m_Aggregate->Count()) ? true : false);
    }

private:
    int m_nCurrent;
    Aggregate* m_Aggregate;
};

class ConcreteAggregate : public Aggregate //����ۺ���
{//ʵ�����ڳ���ۺ�����������createIterator()�������÷�������һ����þ���ۺ����Ӧ�ľ��������ConcreteIteratorʵ��
public:
    ConcreteAggregate() : m_pIterator(NULL)
    {
        m_vecItems.clear();
    }

    ~ConcreteAggregate()
    {
        if (m_pIterator != NULL)
        {
            delete m_pIterator;
            m_pIterator = NULL;
        }
    }

    Iterator* CreateIterator()
    {
        if (m_pIterator == NULL)
        {
            m_pIterator = new ConcreteIterator(this);
        }

        return m_pIterator;
    }

    int Count()
    {
        return m_vecItems.size();
    }

    void Push(const string& strValue)
    {
        m_vecItems.push_back(strValue);
    }

    string Pop(const int index)
    {
        string strRet;

        if (index < Count())
        {
            strRet = m_vecItems[index];
        }

        return strRet;
    }

private:
    Iterator* m_pIterator;
    vector<string> m_vecItems;
};

int main()
{
    ConcreteAggregate* pName = new ConcreteAggregate();
    if (pName == NULL)
        return -1;

    pName->Push("hello");
    pName->Push("world");
    pName->Push("cxue");

    Iterator* iter = NULL;
    iter = pName->CreateIterator();

    if (iter != NULL)
    {
        string strItem = iter->First();

        while (!iter->IsEnd())
        {
            
            cout << iter->GetCur() << " is ok" << endl;
            iter->Next();
        }
    }

    delete pName;

    return 0;
}






