/*
* ģʽ���������һ���������������ж��ֲ�ͬ�ķ�ʽ��ÿһ�ַ�ʽ��Ϊһ�����ԣ����ǿ��Ը��ݻ������������Ĳ�ͬѡ��ͬ�Ĳ�������ɸ�������
�����������Ҳ�����������Ƶ������ʵ��ĳһ�������ж��;������ʱ����ʹ��һ�����ģʽ��ʹ��ϵͳ��������ѡ����;����Ҳ�ܹ�����������µĽ��;���� 
*���壺����һϵ���㷨����ÿһ���㷨��װ�������������ǿ����໥�滻������ģʽ���㷨������ʹ�����Ŀͻ����仯������ģʽ��һ�ֶ�����Ϊ��ģʽ��
* ģʽ����������ģʽ�Ƕ��㷨�ķ�װ�������㷨�����κ��㷨����ָ��ί�ɸ���ͬ�Ķ����������ģʽͨ����һ��ϵ�е��㷨��װ��һϵ�о�����������棬��Ϊ�������������ࡣ
����������Ҫʹ���㷨���ࡣ��һ��ϵͳ�п��Դ��ڶ�������࣬���ǿ�����Ҫ����һЩ��ͬ���㷨��
����ģʽ������װ�㷨���ṩ���㷨���뵽����ϵͳ�У��Լ����㷨��ϵͳ�С����ݡ��ķ��㣬����ģʽ���������ں�ʱʹ�ú����㷨���㷨��ѡ���ɿͻ���������������һ���̶��������ϵͳ������ԣ�
���ǿͻ�����Ҫ������о��������֮��������Ա�ѡ����ʵ��㷨����Ҳ�ǲ���ģʽ��ȱ��֮һ��һ���̶��������˿ͻ��˵�ʹ���Ѷȡ�
*���û�����1.һ��ϵͳ��Ҫ��̬���ڼ����㷨��ѡ��һ�֡�
2.һ�������кܶ����Ϊ���������ǡ����ģʽ����Щ��Ϊ��ֻ��ʹ�ö�������ѡ�������ʵ�֡���ʱ��ʹ�ò���ģʽ������Щ��Ϊת�Ƶ���Ӧ�ľ�����������棬�Ϳ��Ա���ʹ������ά���Ķ�������ѡ����䡣
3.��ϣ���ͻ���֪�����ӵġ����㷨��ص����ݽṹ���ھ���������з�װ�㷨����ص����ݽṹ����������㷨�ı������밲ȫ�ԡ�
*�ŵ㣺1.�ṩ��һ�ֿ����滻�̳й�ϵ�İ취�������ʹ�ò���ģʽ����ôʹ���㷨�Ļ�����Ϳ��ܻ���һЩ���࣬ÿһ�������ṩһ�ֲ�ͬ���㷨��
���ǣ�����һ����Υ������һְ��ԭ�򡱣�����ʹ����һ���㷨���߼����㷨��������һ�𣬴Ӷ������ܶ����ݻ�������ʹ�ü̳��޷�ʵ���㷨����Ϊ�ڳ�������ʱ�Ķ�̬�л���
2.���Ա����������ѡ����䡣��������ѡ����䲻��ά�������Ѳ�ȡ��һ���㷨���߼����㷨�����ʵ���߼������һ�𣬽�����ȫ��Ӳ������һ���Ӵ�Ķ�������ѡ������У���ֱ�Ӽ̳л�����İ취��Ҫԭʼ�����
ȱ�㣺1.�ͻ��˱���֪�����еĲ����࣬�����о���ʹ����һ�������ࡣ�����ζ�ſͻ��˱��������Щ�㷨�������Ա���ʱѡ��ǡ�����㷨������֮������ģʽֻ�����ڿͻ���֪�����е��㷨����Ϊ�������
2.�����ϵͳ�����ܶ��������࣬�κ�ϸС�ı仯��������ϵͳҪ����һ���µľ�������ࡣ
*/

//#include<iostream>
//using namespace std;
//
//class FlyBehavior //������Ϊ���ó������ʾ
//{
//public:
//	virtual ~FlyBehavior(){}
//	virtual void fly() = 0;
//};
//class QuackBehavior //������Ϊ���ó������ʾ
//{
//public:
//	virtual ~QuackBehavior(){}
//	virtual void quack() = 0;
//};
//
//class Duck //Ѽ�ӻ��࣬��display��performFly�� performQuack��swim�ȷ�����
//{
//public:
//	Duck(FlyBehavior*a,QuackBehavior*b):p_flyBehavior(a),p_quackBehavior(b){}
//	virtual ~Duck(){}
//	virtual void display(){}
//	void performFly()
//	{
//		p_flyBehavior->fly();
//	}
//	void performQuack()
//	{
//		p_quackBehavior->quack();
//	}
//	void swim()
//	{
//		cout << ("All ducks float, even decoys!") << endl;
//	}
//private:
//	FlyBehavior* p_flyBehavior;
//	QuackBehavior* p_quackBehavior;
//};
//
////ʵ�ַ�����Ϊ�ķ�����
//class FlyWithWings: public FlyBehavior{
//public:
//   void fly() {
//   std::cout << ("I'm flying!!") << std::endl;
//   }
//};
//class FlyNoWay: public FlyBehavior{
//public:
//   void fly() {
//   std::cout << ("I can't fly") << std::endl;
//   }
//};
////ʵ�ֽ�����Ϊ����
//class Quack: public QuackBehavior{
//public:
//   void quack() {
//   std::cout << ("Quack") << std::endl;
//   }
//};
//
//class MuteQuack: public QuackBehavior{
//public:
//   void quack() {
//   std::cout << ("<< Slience >>") << std::endl;
//   }
//};
//class Squeak: public QuackBehavior{
//public:
//   void quack() {
//   std::cout << "Squeak" << std::endl;
//   }
//};
//
////��ͷѼ��
//class MallardDuck: public Duck{
//public:
//   MallardDuck(FlyBehavior * fly_behavior = new FlyWithWings(), QuackBehavior * quack_behavior = new Quack()) :Duck(fly_behavior,quack_behavior) {}
//   void display()
//   {
//	  std::cout << "I'm a real Mallard duck" << std::endl;
//   }
//};
//
//int main()
//{
//	Duck* mallard = new MallardDuck();
//	mallard->performFly();
//	mallard->performQuack();
//}




















#include<iostream>
using namespace std;
//���������
class Strategy { //���������Ϊ��֧�ֵ��㷨�����˳��󷽷��������в�����ĸ��࣬�������ǳ����������࣬Ҳ�����ǽӿڡ�������ͨ������������������ķ���������ʱ���þ����������ʵ�ֵ��㷨��
public:
    virtual void AlgorithmInterface() = 0;
};
//���������  StrategyA
class StrategyA : public Strategy { //���������ʵ�����ڳ�����������������㷨������ʱ������Զ��󽫸��ǻ������ж���ĳ�����Զ���ʹ��һ�־�����㷨ʵ��ĳ��ҵ����
public:
    void AlgorithmInterface() {
        //�㷨A
        cout << "�㷨Aʵ��" << endl;
    }
};
//���������  StrategyB
class StrategyB : public Strategy {
public:
    void AlgorithmInterface() {
        //�㷨B
        cout << "�㷨Bʵ��" << endl;
    }
};

//������
class Context { //��������ʹ���㷨�Ľ�ɫ�����ڽ��ĳ������(��ʵ��ĳ������)ʱ���Բ��ö��ֲ��ԡ��ڻ�������ά��һ���Գ�������������ʵ�������ڶ��������õĲ��ԡ�
public:
    Context(Strategy* pStrategy) :pStrategy(pStrategy) {}//��ʼ���Ǵ������Ĳ��Զ���
    void ContextInterface() {
        pStrategy->AlgorithmInterface();//���ݾ���Ĳ��Զ��󣬵������㷨����
    }
private:
    Strategy* pStrategy;
};

int main() {
    Strategy* pstrategyA = new StrategyA();
    Strategy* pstrategyB = new StrategyB();

    Context* pcontextA = new Context(pstrategyA);
    Context* pcontextB = new Context(pstrategyB);

    pcontextA->ContextInterface();
    pcontextB->ContextInterface();

    if (pstrategyA)delete pstrategyA;
    if (pstrategyB)delete pstrategyB;

    if (pcontextA)delete pcontextA;
    if (pcontextB)delete pcontextB;

    return 0;
}



//������򵥹������
//����֪�����е�AB�����㷨�����������ֲ�ȷ������ʱʹ�������㷨��ͬʱΪ���ÿͻ��˺�ҵ���߼�������뿪�����ǣ����ǿ��Խ��ͻ��˵Ĵ����㷨���ҵ���߼�ת�Ƶ�Cotent�࣬�����һ�������㷨�����ķ�����

//#include<iostream>
//#include<string>
//using namespace std;
////���������
//class strategy {
//public:
//    virtual void algorithminterface() = 0;
//};
////���������  strategya
//class strategya : public strategy {
//public:
//    void algorithminterface() {
//        //�㷨a
//        cout << "�㷨aʵ��" << endl;
//    }
//};
////���������  strategyb
//class strategyb : public strategy {
//public:
//    void algorithminterface() {
//        //�㷨b
//        cout << "�㷨bʵ��" << endl;
//    }
//};
//
////������
//class context {
//public:
//    context(strategy* pstrategy) :pstrategy(pstrategy) {}//��ʼ���Ǵ������Ĳ��Զ���
//    void contextinterface() {
//        pstrategy->algorithminterface();//���ݾ���Ĳ��Զ��󣬵������㷨����
//    }
//private:
//    strategy* pstrategy;
//};
//
//// ������
//class factory
//{
//public:
//    strategy* createstrategy(string type)
//    {
//        if(type== "strategya")
//            return new strategya();
//        else if(type== "strategyb")
//            return new  strategyb();
//        else
//            return null;
//    }
//};
//
//int main() {
//
//    // �������������
//    factory* factory = new  factory();
//    strategy* mystrategy = factory->createstrategy("strategya");
//    if (factory != null)
//        factory->contextinterface();
//
//    tv* hisensetv = mytvfactory->createtv(strategyb);
//    if (factory != null)
//        factory->contextinterface();
//
//    delete  factory;
//    factory = null;
//
//
//    if (pstrategya)delete pstrategya;
//    if (pstrategyb)delete pstrategyb;
//
//    if (pcontexta)delete pcontexta;
//    if (pcontextb)delete pcontextb;
//
//    return 0;
//}