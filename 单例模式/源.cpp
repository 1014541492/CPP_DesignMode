/*
* 模式动机：如何保证一个类只有一个实例并且这个实例易于被访问呢？定义一个全局变量可以确保对象随时都可以被访问，但不能防止我们实例化多个对象。
一个更好的解决办法是让类自身负责保存它的唯一实例。这个类可以保证没有其他实例被创建，并且它可以提供一个访问该实例的方法。这就是单例模式的模式动机。
*模式分析：单例模式的目的是保证一个类仅有一个实例，并提供一个访问它的全局访问点。单例模式包含的角色只有一个，就是单例类Singleton。单例类拥有一个私有构造函数，确保用户无法通过new关键字直接实例化它。
除此之外，该模式中包含一个静态私有成员变量与静态公有的工厂方法，该工厂方法负责检验实例的存在性并实例化自己，然后存储在静态成员变量中，以确保只有一个实例被创建。

*在单例模式的实现过程中，需要注意如下三点：
单例类的构造函数为私有；
提供一个自身的静态私有成员变量；
提供一个公有的静态工厂方法。

*优点：1.提供了对唯一实例的受控访问。因为单例类封装了它的唯一实例，所以它可以严格控制客户怎样以及何时访问它，并为设计及开发团队提供了共享的机制。
2.由于在系统内存中只存在一个对象，因此可以节约系统资源，对于一些需要频繁创建和销毁的对象，单例模式无疑可以提高系统的性能。
3.允许可变数目的实例。我们可以基于单例模式进行扩展，使用与单例控制相似的方法来获得指定个数的对象实例。
缺点：1.由于单例模式中没有抽象层，因此单例类的扩展有很大的困难。
2.单例类的职责过重，在一定程度上违背了“单一职责原则”。因为单例类既充当了工厂角色，提供了工厂方法，同时又充当了产品角色，包含一些业务方法，将产品的创建和产品的本身的功能融合到一起。
3.滥用单例将带来一些负面问题，如为了节省资源将数据库连接池对象设计为单例类，可能会导致共享连接池对象的程序过多而出现连接池溢出。



* 单例模式：特点是只提供唯一一个类的实例,具有全局变量的特点，在任何位置都可以通过接口获取到那个唯一实例;
* 1.保证一个类仅有一个实例；
2.并提供一个访问它的全局访问点；
3.该实例被所有程序模块所共享。
*应用场景：设备管理器，系统中可能有多个设备，但是只有一个设备管理器，用于管理设备驱动;
数据池，用来缓存数据的数据结构，需要在一处写，多处读取或者多处写，多处读取; Windows资源管理器
*实现方式：懒汉：不到万不得已就不会去实例化类，也就是说在第一次用到类实例的时候才会去实例化（懒汉本身是线程不安全的）
           饿汉：饿了肯定要饥不择食。所以在单例类定义的时候就进行实例化。（本身就是线程安全的）
如何选择：懒汉：在访问量较小时，采用懒汉实现。这是以时间换空间。
　　      饿汉：由于要进行线程同步，所以在访问量比较大，或者可能访问的线程比较多时，采用饿汉实现，可以实现更好的性能。这是以空间换时间。
*懒汉式 : 指代码运行后,实例并不存在,只有当需要时,才去创建实例(适用于单线程)
 饿汉式 : 指代码一运行,实例已经存在,当时需要时,直接去调用即可(适用于多线程)
*/


/*
* 
* 有时候我们在面对通用代码时候，经常会尝试着创建多个示例函数来对一个函数多次赋值，这样会损耗很多的内存空间，这对于代码来说是不利的。而单例模式可以很好的解决这个问题。
* 
* 1.1饿汉模式
 饿汉模式 是指单例实例在类装载时就构建，并被立即执行初始化:
public class Test {
        private Test() {
        }
        public static Test instance = new Test();// 直接对Test构造函数进行实例化
        public Test getInstance() {
                return instance;
        }
}

优点：
1.线程安全
2.在类加载的同时已经创建好一个静态对象，调用时反应速度快
缺点：
资源效率不高，可能getInstance()永远不会执行到，但执行该类的其他静态方法或者加载了该类（class.forName)，那么这个实例仍然初始化 。如果类是多态的, 那静态成员变量初始化顺序还是没保证，下面我们将详细解释这个问题.
例如：有两个单例模式的类 ASingleton 和 BSingleton, 某天你想在 BSingleton 的构造函数中使用 ASingleton 实例, 这就出问题了. 因为 BSingleton m_pInstance 静态对象可能先 ASingleton 一步调用初始化构造函数, 
结果 ASingleton::getInstance() 返回的就是一个未初始化的内存区域, 程序还没跑就直接崩掉.
* 
* 
* 
* 1.2懒汉模式
懒汉式是指：单例实例在第一次被使用时构建，但延迟初始化：
class Test {
        private Test() {
        }
        public static Test instance = null;
        public static Test getInstance() {
                if (instance == null) {
              //多个线程判断instance都为null时，在执行new操作时多线程会出现重复情况
                        instance = new Test();
                }
                return instance;
        }
}
优点：
避免了饿汉式的那种在没有用到的情况下创建事例，资源利用率高，不执行getInstance()就不会被实例，可以执行该类的其他静态方法。
缺点：
懒汉式在单个线程中没有问题，但多个线程同时访问的时候就可能同时创建多个实例，而且这多个实例不是同一个对象，虽然后面创建的实例会覆盖先创建的实例，但是还是会存在拿到不同对象的情况。
解决这个问题的办法就是加锁synchonized，第一次加载时不够快，多线程使用不必要的同步开销大。
* 
* 
* 1.3双重模式
class Test {
        private Test() {
        }
        public static Test instance = null;

        public static Test getInstance() {
                if (instance == null) {
                        synchronized (Test.class) {
                                if (instance == null) {
                                        instance = new Test();
                                }
                        }
                }
                return instance;
        }
}
优点
资源利用率高，不执行getInstance()不被实例，可以执行该类其他静态方法
缺点
第一次加载时反应不够快
* 
* 
* 
* 
* 1.4 静态内部类
class Test {
        private Test() {
        }

        private static class SingletonHelp {
                static Test instance = new Test();
        }

        public static Test getInstance() {
                return SingletonHelp.instance;
        }
}
优点
资源利用率高，不执行getInstance()不被实例，可以执行该类其他静态方法
缺点
第一次加载时反应不够快
* 
* 1.5 总结：
一般采用饿汉式，若对资源十分在意可以采用静态内部类，不建议采用懒汉式及双重检测 。
* 
* 
*/

//实例：选择静态内部类+模板类的组合方法来有效的对多线程程序进行单例模式设计

#include<iostream>
#include <cassert>
using namespace std;

class Singleton
{
private:
    Singleton() = default; //default 编译器会为其自动生成默认的函数定义体，从而获得更高的代码执行效率，也可免除程序员手动定义该函数的工作量。
    ~Singleton() = default;
public:
    static Singleton& Instance()
    {
        static Singleton instance; // 静态实例化：
        return instance;
    }
    Singleton(const Singleton&) = delete; //禁用成员函数的使用。这是通过附加= delete来完成的; 说明符到该函数声明的结尾。
    Singleton(Singleton&&) = delete;//明确删除函数好处：删除特殊成员函数提供了一种更简洁的方法来防止编译器生成我们不想要的特殊成员函数
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};

int main()
{
    auto& a = Singleton::Instance(); //实例化
    auto& b = Singleton::Instance();
    assert(&a == &b); //assert的作用是现计算表达式 expression ，如果其值为假（即为0），那么它先向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行。

    return 0;
}





//实际模式 七大原则

/*


1.单一职责原则(Single Responsibility Principle)

目的：降低代码复杂度、系统解耦合、提高可读性

含义：对于一个类，只有一个引起该类变化的原因；该类的职责是唯一的，且这个职责是唯一引起其他类变化的原因。

解决：将不同的职责封装到不同的类或者模块中。 当有新的需求将现有的职责分为颗粒度更小的职责的时候，应该及时对现有代码进行重构。
当系统逻辑足够简单，方法足够少，子类够少或后续关联够少时，也可以不必严格遵循你SRP原则，避免过度设计、颗粒化过于严重。

实例：电线类Wire为居民供电，电压为220v；但是新的需求增加，电线也输送高压电，电压为200kv，原有电线类可以增加方法实现扩充，这就违背了单一职责原则。可以提供基类，创建两个派生类，居民供电线、高压输电线。





2.里氏代换原则（Liskov Substitution Principle）

目的：避免系统继承体系被破坏

含义：所有引用基类的地方必须能透明地使用其子类的对象。

解决：子类可以实现父类的抽象方法，但是不能覆盖父类的非抽象方法；子类中可以增加自己特有的方法；当子类覆盖或实现父类的方法时，方法的前置条件（即方法的形参）要比父类方法的输入参数更宽松；
当子类的方法实现父类的抽象方法时，方法的后置条件（即方法的返回值）要比父类更严格。如果子类不能完整地实现父类的方法，或者父类的一些方法在子类中已经发生畸变，则建议断开继承关系，采用依赖，聚合，组合等关系代替继承。

实例：已经定义鸟类具有两个翅膀飞的方法；新加入鸵鸟，不会飞，如果覆盖父类的方法，在两个翅膀飞的方法中什么也不做，就违背里氏替换原则，导致所有鸟都不会飞。应该创建并列的两种鸟基类，会飞与不会飞的。
前置条件更宽松、后置条件更严格，比如父类返回Map，子类返回HashMap；父类接受HashMap形参，子类接受Map。






3.依赖倒转原则（Dependence Inversion Principle）

目的：避免需求变化导致过多的维护工作

含义：高层模块不应该依赖低层模块，二者都应该依赖其抽象；抽象不应该依赖细节；细节应该依赖抽象。

解决：面向接口编程，使用接口或者抽象类制定好规范和契约，而不去涉及任何具体的操作，把展现细节的任务交给他们的实现类去完成。

实例：母亲类Mother有讲故事方法TellStory，依赖一个Book类输入，并使用了Book类的getContent方法以便讲故事。那么下次需要母亲讲报纸上的故事、手机上的故事时，原有接口无能为力。
这时，抽象一个包含getContent方法的IReader基类，Book、Newspaper、Cellphone各自实现。母亲的TellStory方法接受一个IReader实例，并调用getContent方法即可。





4.接口隔离原则（Interface Segregation Principle）

目的：避免接口过于臃肿

含义：客户端不应该依赖它不需要的接口，一个类对另一个类的依赖应该建立在最小的接口上。

解决：适度细化接口，将臃肿的接口拆分为独立的几个接口。

实例：考试接口，包含考语数外、理化生、政史地等方法。学生类，实现考试接口，参加考试。文科生类、理科生类派生自学生类，实现考试接口时，就都需要实现一些自己不需要的方法（因为文科生不考理化生、理科生不考政史地）。
这时，需要对考试接口进行细化，分为基础科考试接口、文科考试接口和理科考试接口；学生类实现基础科考试接口；文科生、理科生另外各自实现文科考试接口、理科考试接口。





5.迪米特法则（Demeter Principle）

目的：降低类与类之间的耦合

含义：每一个软件单位对其他的单位都只有最少的知识，而且局限于那些与本单位密切相关的软件单位。

解决：不发生依赖、关联、组合、聚合等耦合关系的陌生类不要作为局部变量的形式出现在类的内部。

实例：校长管理老师，老师管理学生。校长需要全体点名时，首先对老师点名，但是不必通过老师获取学生的信息并点名，而应该让老师对各自管理学生的点名，否则校长和学生之间就发生了原本不必要的耦合，
这样当学生类发生变化时，既要修改老师类，也要修改校长类。





6.合成复用原则（Composite Reuse Principle）

目的：防止类的体系庞大

含义：当要扩展类的功能时，优先考虑使用合成/聚合，而不是继承。

解决：当类与类之间的关系是"Is-A"时，用继承；当类与类之间的关系是"Has-A"时，用组合。

实例：如桥接模式，抽象和实现可以独立的变化，扩展功能时，增加实现类即可；比如装饰模式，只需要一个类，即可为一类类扩展新功能。对于显示图形需求，用图形Shape类，和显示Paint类实现。
每个Shape类有一个Paint类指针负责图形绘制显示。Paint类派生RedPaint类和BluePaint类，传递给Shape类，实现图形不同颜色绘制，这样图形绘制逻辑和图形绘制实现可独立变化。某天增加需求，所有的绘制需要加边框，
可增加PaintDecorator类，派生自Paint基类，每一个PaintDecorator类有一个Paint对象指针，增加虚函数AddedPaint，重写Paint的绘制方法，增加AddedPaint方法的调用。增加BorderPaintDecorator类，派生自PaintDecorator类，
重写AddedPaint方法，增加添加绘制边框代码。这样新增加一个类可以对原始所有画笔类的功能进行扩充。





7.开闭原则（Open Close Principle）

目的：提高扩展性、便于维护

含义：对扩展开放，对修改封闭。即系统进行扩展是被鼓励的，对现有系统代码进行修改是不被支持的。也就是说，当软件有新的需求变化的时候，只需要通过对软件框架进行扩展来适应新的需求，而不是对框架内部的代码进行修改。

解决：设计模式前面6大原则以及23种设计模式遵循的好，开闭原则自然遵守的好。对需求的变更保持前瞻性和预见性，就可以使抽象具有更广泛适用性，设计出的软件架构就能相对稳定。
软件需求中易变的细节，通过从抽象派生出实现类来扩展。

*/