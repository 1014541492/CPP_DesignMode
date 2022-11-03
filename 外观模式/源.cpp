/*
* 外观模式：为子系统中的一组接口提供一个统一的入口，外部与一个子系统的通信可以通过一个统一的外观对象进行。
外观模式要求一个子系统的外部与其内部的通信通过一个统一的外观对象进行，外观类将客户端与子系统的内部复杂性分隔开，通过它们用户可以快速访问子系统，降低系统的复杂程度。
外观模式隐藏系统的复杂性，并向客户端提供了一个客户端可以访问系统的接口。这种类型的设计模式属于结构型模式，它向现有的系统添加一个接口，来隐藏系统的复杂性。
*模式优点：
（1）对客户屏蔽子系统组件，减少了客户处理对象的数目并使得子系统使用起来更加容易。
（2）实现了子系统与客户之间的松耦合关系，使得子系统的组件变化不会影响到调用它的客户类；
（3）降低了大型软件系统中的编译依赖性。一个子系统的修改对其他子系统没有任何影响；
模式缺点：
（1）不能很好地限制客户端使用子系统类，如果对客户访问子系统做太多的限制则减少了可变性和灵活性。
（2）在不引入抽象外观类的情况下，增加新的子系统可能需要修改外观类或客户端的源代码，违背“开闭原则”；
*应用：（1）当要为一个复杂子系统提供一个简单接口时可以使用外观模式；
（2）客户端与多个子系统之间存在很大的依赖性，引入外观模式将子类系统与客户以及其他子系统解耦。
*/

//实例：定义一个电器开关，打开电器开关时，电视机和空调打开；关闭电器开关时，电视机和空调打开关闭；
#include<iostream>
using namespace std;

class TV //子系统角色:子系统处理由外观类传过来的请求，子系统并不知道外观的存在，对于子系统而言，外观仅是另外一个客户端。
{
public:
    void tVOn() {
        cout << "turn on the television!" << endl;
    }
    void tVOff() {
        cout << "turn off the television!" << endl;
    }
};
class Conditioner 
{
public:
    void conditionerOn() {
        cout << "turn on the conditioner!" << endl;
    }
    void conditionerOff() {
        cout << "turn off the conditioner!" << endl;
    }
};

class Swich //外观角色：外观模式的核心，他被客户client角色调用，知道各个子系统的功能。同时根据客户角色已有的需求预订了几种功能组合。
    //将所有从客户端发来的请求委派到相应的子系统中，传递给相应的子系统对象处理。
{
public:
    Swich();
    ~Swich();
    void On()
    {
        tv->tVOn();
        conditioner->conditionerOn();
    }
    void Off()
    {
        tv->tVOff();
        conditioner->conditionerOff();
    }
private:
    TV* tv;
    Conditioner* conditioner;
};
Swich::Swich()
{
    tv = new TV();
    conditioner = new Conditioner();
}
Swich::~Swich()
{
    delete tv;
    delete conditioner;
}

int main()
{
    Swich* swich = new Swich();
    swich->On();
    swich->Off();
    delete swich;
}