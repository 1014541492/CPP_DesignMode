/*
* 模式动机：在软件开发中，也存在大量类似电视机一样的类，它们可以存储多个成员对象（元素），这些类通常称为聚合类(Aggregate Classes)，对应的对象称为聚合对象。
聚合对象拥有两个职责：一是存储数据；二是遍历数据。从依赖性来看，前者是聚合对象的基本职责；而后者既是可变化的，又是可分离的。
因此，我们比照电视机遥控器的功能角色，将遍历数据的行为从聚合对象中分离出来，封装在一个被称之为“迭代器”的对象中，由迭代器来提供遍历聚合对象内部数据的行为，这将简化聚合对象的设计，更符合“单一职责原则”的要求。
同时还可以灵活地为聚合对象增加不同的遍历方法，还可以访问一个聚合对象中的元素但又不需要暴露它的内部结构。
*模式定义：迭代器模式(Iterator Pattern) ：提供一种方法来访问聚合对象，而不用暴露这个对象的内部表示，其别名为游标(Cursor)。迭代器模式是一种对象行为型模式。
在迭代器模式结构中包含聚合和迭代器两个层次结构，考虑到系统的灵活性和可扩展性，在迭代器模式中应用了工厂方法模式
*模式分析：在迭代器模式中，提供了一个外部的迭代器来对聚合对象进行访问和遍历，迭代器定义了一个访问该聚合元素的接口，并且可以跟踪当前遍历的元素，了解哪些元素已经遍历过而哪些没有。
迭代器的引入，将使得对一个复杂聚合对象的操作变得简单。在迭代器模式中应用了工厂方法模式，抽象迭代器对应于抽象产品角色，具体迭代器对应于具体产品角色，抽象聚合类对应于抽象工厂角色，具体聚合类对应于具体工厂角色。
需要注意的是抽象迭代器接口的设计非常重要，一方面需要充分满足各种遍历操作的要求，尽量为各种遍历方法都提供声明，另一方面又不能包含太多方法，接口中方法太多将给子类的实现带来麻烦。
因此，可以考虑使用抽象类来设计抽象迭代器，在抽象类中为每一个方法提供一个空的默认实现。如果需要在具体迭代器中为聚合对象增加全新的遍历操作，则必须修改抽象迭代器和具体迭代器的源代码，这将违反“开闭原则”，
因此在设计时要考虑全面，避免之后修改接口。具体迭代器类和具体聚合类之间存在双重关系，其中一个关系为关联关系，在具体迭代器中需要维持一个对具体聚合对象的引用，该关联关系的目的是访问存储在聚合对象中的数据，
以便迭代器能够对这些数据进行遍历操作。除了使用关联关系外，为了能够让迭代器可以访问到聚合对象中的数据，我们还可以将迭代器类设计为聚合类的内部类
*适用环境：1.访问一个聚合对象的内容而无须暴露它的内部表示。将聚合对象的访问与内部数据的存储分离，使得访问聚合对象时无须了解其内部实现细节。
2.需要为一个聚合对象提供多种遍历方式。
3.为遍历不同的聚合结构提供一个统一的接口，在该接口的实现类中为不同的聚合结构提供不同的遍历方式，而客户端可以一致性地操作该接口。
*优点：1.支持以不同的方式遍历一个聚合对象，在同一个聚合对象上可以定义多种遍历方式。在迭代器模式中只需要用一个不同的迭代器来替换原有迭代器即可改变遍历算法，我们也可以自己定义迭代器的子类以支持新的遍历方式。
2.迭代器简化了聚合类。由于引入了迭代器，在原有的聚合对象中不需要再自行提供数据遍历等方法，这样可以简化聚合类的设计。
在迭代器模式中，由于引入了抽象层，增加新的聚合类和迭代器类都很方便，无须修改原有代码，满足“开闭原则”的要求。
缺点：1.由于迭代器模式将存储数据和遍历数据的职责分离，增加新的聚合类需要对应增加新的迭代器类，类的个数成对增加，这在一定程度上增加了系统的复杂性。
2.抽象迭代器的设计难度较大，需要充分考虑到系统将来的扩展
*/

//在迭代器模式中主要分为两大主要部分：
//容器部分，内部可以存放一系列数据，并提供迭代器调用接口。
//迭代器部分，内部含有对容器部分的调用，并获得容器内部提供的方法。
//具体容器和具体迭代器两者是相互调用的，也就是说容器调用了迭代器，然后通过迭代器调用了容器内部自身的方法来实现封装。

#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Iterator //抽象迭代器类
{//定义了访问和遍历元素的接口，声明了相应方法，如：用于获取第一个元素的first()方法，用于访问下一个元素的next()方法，用于判断是否还有下一个元素的hasNext()方法，用于获取当前元素的currentItem()方法等，在具体迭代器中将实现这些方法。
public:
    Iterator() {};
    virtual ~Iterator() {};
    virtual string First() = 0;
    virtual string Next() = 0;
    virtual string GetCur() = 0;
    virtual bool IsEnd() = 0;
};

class Aggregate //抽象聚合类
{//用于存储和管理元素对象，声明一个createIterator()方法用于创建一个迭代器对象，充当抽象迭代器工厂角色。
public:
    Aggregate() {};
    virtual ~Aggregate() {};
    virtual int Count() = 0;
    virtual void Push(const string& strValue) = 0;
    virtual string Pop(const int index) = 0;
    virtual Iterator* CreateIterator() = 0;
};

class ConcreteIterator : public Iterator //具体迭代器类
{//实现了抽象迭代器接口，完成对聚合对象的遍历，同时在具体迭代器中通过游标来记录在聚合对象中所处的当前位置，在具体实现时，游标通常是一个表示位置的非负整数。
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

class ConcreteAggregate : public Aggregate //具体聚合类
{//实现了在抽象聚合类中声明的createIterator()方法，该方法返回一个与该具体聚合类对应的具体迭代器ConcreteIterator实例
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






