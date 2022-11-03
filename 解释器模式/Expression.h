#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream> //用于类型转换
using namespace std;

class PlayContext //Context，此处为演奏内容类
{//包含解释器之外的一些全局信息。
private:
	string text;
public:
	void SetText(string text)
	{
		this->text = text;
	}
	string GetText()
	{
		return this->text;
	}
};

class Expression //AbstractExpression，此处为表达式类
{//抽象表达式：声明一个抽象的解释操作，这个接口为抽象语法树中所有的节点所共享。
public:
	virtual void Excute(string key, string value) = 0;
	void Interpret(PlayContext* context)
	{
		string s1 = context->GetText();
		string buf;
		string s2;
		if (context->GetText().length() == 0) { return; }
		else
		{
			vector<string> vec;
			stringstream ss(context->GetText());
			while (ss >> buf)
				vec.push_back(buf);

			string playKey = vec[0];
			string playValue = vec[1];
			Excute(playKey, playValue);

			vec.erase(vec.begin(), vec.begin() + 2);
			for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
			{
				s2 += *it;
				if (it != vec.end() - 1)
					s2 += " ";
			}
			context->SetText(s2);
		}
	}
};

//TerminalExpression（终结符表达式）实现与文法中的终结符相关联的解释操作。实现抽象表达式中所要求的接口，主要是一个interpreter（）方法。文法中每一个终结符都有一个具体终结表达式与之相对应。
//NonterminalExpression（非终结符表达式）：为文法中的非终结符实现解释操作。

//ConcreteExpression，此处为音符类
class Note :public Expression
{
public:
	void Excute(std::string key, std::string value)
	{
		std::string note; 
		switch (key[0])
		{
		case 'C':
			note = "1";
			break;
		case 'D':
			note = "2";
			break;
		case 'E':
			note = "3";
			break;
		case 'F':
			note = "4";
			break;
		case 'G':
			note = "5";
			break;
		case 'A':
			note = "6";
			break;
		case 'B':
			note = "7";
			break;
		}
		std::cout << note << " ";
	}
};

//ConcreteExpression，此处为音阶类
class Scale :public Expression
{
public:
	void Excute(std::string key, std::string value)
	{
		std::string scale;
		switch (value[0])
		{
		case '1':
			scale = "低音";
			break;
		case '2':
			scale = "中音";
			break;
		case'3':
			scale = "高音";
			break;
		}
		std::cout << scale << " ";
	}
};