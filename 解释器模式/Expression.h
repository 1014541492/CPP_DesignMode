#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream> //��������ת��
using namespace std;

class PlayContext //Context���˴�Ϊ����������
{//����������֮���һЩȫ����Ϣ��
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

class Expression //AbstractExpression���˴�Ϊ���ʽ��
{//������ʽ������һ������Ľ��Ͳ���������ӿ�Ϊ�����﷨�������еĽڵ�������
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

//TerminalExpression���ս�����ʽ��ʵ�����ķ��е��ս��������Ľ��Ͳ�����ʵ�ֳ�����ʽ����Ҫ��Ľӿڣ���Ҫ��һ��interpreter�����������ķ���ÿһ���ս������һ�������ս���ʽ��֮���Ӧ��
//NonterminalExpression�����ս�����ʽ����Ϊ�ķ��еķ��ս��ʵ�ֽ��Ͳ�����

//ConcreteExpression���˴�Ϊ������
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

//ConcreteExpression���˴�Ϊ������
class Scale :public Expression
{
public:
	void Excute(std::string key, std::string value)
	{
		std::string scale;
		switch (value[0])
		{
		case '1':
			scale = "����";
			break;
		case '2':
			scale = "����";
			break;
		case'3':
			scale = "����";
			break;
		}
		std::cout << scale << " ";
	}
};