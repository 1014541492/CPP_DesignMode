/*
* 组合模式：组合多个对象形成树形结构以表示“部分-整体”的结构层次。
* 模式应用：（1）需要表示一个对象的整体或部分层次，在具有整体和部分的层次结构中，通过整体模式可忽略整体与部分的差异。
            （2）希望忽略单个对象和组合对象的不同, 客户端将统一的使用组合结构中的所有对象.
*优点：
（1）组合模式可以清楚地定义分层的复杂对象，可以方便地对层次结构进行控制；
（2）客户端调用简单，用户不必关心处理的是单个对象还是整个组合结构，简化了客户端代码；
（3）定义了叶子对象和容器对象，叶子对象和容器对象可以形成复杂的树形结构；
*缺点：
（1）使得设计更加抽象；
（2）增加新的构件时可能会产生一些问题；
*/

/*
* 使用组合模式时，根据抽象构件类的定义形式，我们可将组合模式分为透明组合模式和安全组合模式两种形式
* （1）透明组合模式
抽象构件角色中声明了所有用于管理成员对象的方法，比如在示例中Component 声明了 add、remove 、process 方法，这样做的好处是确保所有的构件类都有相同的接口。透明组合模式也是组合模式的标准形式。
透明组合模式的缺点是不够安全，因为叶子对象和容器对象在本质上是有区别的，叶子对象不可能有下一个层次的对象，即不可能包含成员对象，
因此为其提供 add()、remove() 等方法是没有意义的，这在编译阶段不会出错，但在运行阶段如果调用这些方法可能会出错（如果没有提供相应的错误处理代码）
（2）安全组合模式中，在抽象构件角色中没有声明任何用于管理成员对象的方法，而是在容器构件（树枝节点）类中声明并实现这些方法。
安全组合模式的缺点是不够透明，因为叶子构件和容器构件具有不同的方法，且容器构件中那些用于管理成员对象的方法没有在抽象构件类中定义，
因此客户端不能完全针对抽象编程，必须有区别地对待叶子构件和容器构件。
*/


//实例：水果盘（Plate）中有一些水果，如苹果、香蕉、梨子等，大水果盘里还可以有小水果盘，现在需要对水果进行遍历吃。
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class MyElement //抽象的部件类MyElement 描写叙述将来全部部件共同拥有的行为(透明组合模式)
{//抽象构件可以是接口或抽象类，为叶子构件和容器构件对象声明接口，在该角色中可以包含所有子类共有的声明和实现。
    //在抽象构件中定义了访问及管理它的子构件的方法，如增加子构件、删除子构件、获取子构件等。
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

class Apple :public MyElement //叶子节点对象（叶子构件）
    //定义和实现叶子对象的行为，不再包含其他的子节点对象。叶子构件在组合结构中表示叶子节点对象，叶子节点没有子节点，它实现了在抽象构件中定义的行为。
{
public:
    Apple(const string& name) : MyElement(name) {}//子类继承父类有参构造
    virtual ~Apple(){}
    void eat() { cout << "eat apple!" << endl; }
    void add(MyElement* p){}     //叶子结点不需要增加删除操作，但防止误操作报错 要写上
    void remove(MyElement* p){}
};
class Banana :public MyElement
{
public:
    Banana(const string& name) : MyElement(name) {}//子类继承父类有参构造
    virtual ~Banana() {}
    void eat() { cout << "eat banana!" << endl; }
    void add(MyElement* p) {}     //叶子结点不需要增加删除操作，但防止误操作报错 要写上
    void remove(MyElement* p) {}
};
class Pear :public MyElement
{
public:
    Pear(const string& name) : MyElement(name) {}//子类继承父类有参构造
    virtual ~Pear() {}
    void eat() { cout << "eat pear!" << endl; }
    void add(MyElement* p) {}     //叶子结点不需要增加删除操作，但防止误操作报错 要写上
    void remove(MyElement* p) {}
};

class Plate:public MyElement//组合对象（容器构件）
//容器构件在组合结构中表示容器节点对象，容器节点包含子节点，其子节点可以是叶子节点，也可以是容器节点，
//它提供了一个集合用于存储子节点，它实现了在抽象构件中定义的行为，包含那些访问及管理子构件的方法。
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
        for (auto iter : m) { iter->eat(); } //获取到迭代容器中的值，使用auto iter时不会对容器对象造成改变,使用auto &iter,对于iter的任何修改将直接修改容器内对应的值。
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

