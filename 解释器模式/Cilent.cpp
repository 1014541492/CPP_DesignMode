/*
* 解释器模式（interpreter）：给定一个语言，定义它的文法的一种表示，并定义一个解释器，这个解释器使用该表示来解释语言中的句子。
* 需要解决的问题:如果一种特定类型的问题发生的频率足够高，那么可能就值得将该问题的各个实例表述为一个简单语言中的句子。这样就可以构建一个解释器，该解释器通过解释这些句子来解决该问题。
* 什么时候用解释器模式:通常当有一个语言需要解释执行，并且你可将该语言中的句子表示为一个抽象语法树时，可使用解释器模式。
* 优点：用了解释器模式，就意味着可以很容易地改变和扩展文法，因为该模式使用类来表示文法规则，你可使用继承来改变或扩展该文法。也比较容易实现文法，因为定义抽象语法树种各个节点的类的实现大体类似，这些类都易于直接边写。
缺点：解释器模式为文法中的每一条规则至少定义了一个类，因此包含许多规则的文法可能难以管理和维护。建议当文法非常复杂时，使用其他的技术如语法分析程序或编译器生成器来处理。
*/

//#include "Expression.h"
//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
////Client，客户端
//int main()
//{
//	PlayContext context;
//	cout << "上海滩：" << std::endl;
//
//	context.SetText("O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3");
//
//	Expression* expression;
//
//	while (context.GetText().length() > 0)
//	{
//		char c = context.GetText()[0];
//		switch (c)
//		{
//		case 'O':
//			expression = new Scale();
//			break;
//		case 'C':
//		case 'D':
//		case 'E':
//		case 'F':
//		case 'G':
//		case 'A':
//		case 'B':
//		case 'P':
//			expression = new Note();
//			break;
//		}
//		expression->Interpret(&context);
//		delete expression;
//	}
//
//	system("pause");
//}

#include <iostream>
#include <list>
#include<vector>
#include<string>
using namespace std;

class Context 
{
private:
	string m_strInput;
	string m_strOutput;
public:
	void setExpression(string str)
	{
		m_strInput = str;
	}
};

class Expression //抽象表达式：声明一个抽象的解释操作，这个接口为抽象语法树中所有的节点所共享。
{
public:
	virtual void Interpret(Context* context) = 0;
};

class TerminalExpression : public Expression
{//TerminalExpression（终结符表达式）实现与文法中的终结符相关联的解释操作。实现抽象表达式中所要求的接口，主要是一个interpreter（）方法。文法中每一个终结符都有一个具体终结表达式与之相对应。
public:
	void Interpret(Context* context)
	{
		cout << "TerminalExpression!" << std::endl;
	}
};

class NonterminalExpression : public Expression
{//NonterminalExpression（非终结符表达式）：为文法中的非终结符实现解释操作。
public:
	void Interpret(Context* context)
	{
		cout << "NonterminalExpression!" << std::endl;
	}
};

int main()
{
	// 解释器模式
	Context* pContext = new Context();
	pContext->setExpression("Expression......");
	Expression* pNon = new NonterminalExpression();
	Expression* p = new TerminalExpression();
	// 根据Expression中的内容判断采用那种表达式解析
	pNon->Interpret(pContext);
	p->Interpret(pContext);
	delete p;
	delete pNon;
	delete pContext;

	getchar();
	return 0;
}


