/*
* ������ģʽ��interpreter��������һ�����ԣ����������ķ���һ�ֱ�ʾ��������һ�������������������ʹ�øñ�ʾ�����������еľ��ӡ�
* ��Ҫ���������:���һ���ض����͵����ⷢ����Ƶ���㹻�ߣ���ô���ܾ�ֵ�ý�������ĸ���ʵ������Ϊһ���������еľ��ӡ������Ϳ��Թ���һ�����������ý�����ͨ��������Щ��������������⡣
* ʲôʱ���ý�����ģʽ:ͨ������һ��������Ҫ����ִ�У�������ɽ��������еľ��ӱ�ʾΪһ�������﷨��ʱ����ʹ�ý�����ģʽ��
* �ŵ㣺���˽�����ģʽ������ζ�ſ��Ժ����׵ظı����չ�ķ�����Ϊ��ģʽʹ��������ʾ�ķ��������ʹ�ü̳����ı����չ���ķ���Ҳ�Ƚ�����ʵ���ķ�����Ϊ��������﷨���ָ����ڵ�����ʵ�ִ������ƣ���Щ�඼����ֱ�ӱ�д��
ȱ�㣺������ģʽΪ�ķ��е�ÿһ���������ٶ�����һ���࣬��˰�����������ķ��������Թ����ά�������鵱�ķ��ǳ�����ʱ��ʹ�������ļ������﷨��������������������������
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
////Client���ͻ���
//int main()
//{
//	PlayContext context;
//	cout << "�Ϻ�̲��" << std::endl;
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

class Expression //������ʽ������һ������Ľ��Ͳ���������ӿ�Ϊ�����﷨�������еĽڵ�������
{
public:
	virtual void Interpret(Context* context) = 0;
};

class TerminalExpression : public Expression
{//TerminalExpression���ս�����ʽ��ʵ�����ķ��е��ս��������Ľ��Ͳ�����ʵ�ֳ�����ʽ����Ҫ��Ľӿڣ���Ҫ��һ��interpreter�����������ķ���ÿһ���ս������һ�������ս���ʽ��֮���Ӧ��
public:
	void Interpret(Context* context)
	{
		cout << "TerminalExpression!" << std::endl;
	}
};

class NonterminalExpression : public Expression
{//NonterminalExpression�����ս�����ʽ����Ϊ�ķ��еķ��ս��ʵ�ֽ��Ͳ�����
public:
	void Interpret(Context* context)
	{
		cout << "NonterminalExpression!" << std::endl;
	}
};

int main()
{
	// ������ģʽ
	Context* pContext = new Context();
	pContext->setExpression("Expression......");
	Expression* pNon = new NonterminalExpression();
	Expression* p = new TerminalExpression();
	// ����Expression�е������жϲ������ֱ��ʽ����
	pNon->Interpret(pContext);
	p->Interpret(pContext);
	delete p;
	delete pNon;
	delete pContext;

	getchar();
	return 0;
}


