#include<iostream>
#include<string>
#include"Head.h"
using namespace std;

void Fundamental::primitiveOperation1()
{
	cout << "Fundamental::primitiveOperation1()" << endl;
}

void Fundamental::primitiveOperation2()
{
	cout << "Fundamental::primitiveOperation2()" << endl;
}

void Fundamental::templateMethod()
{
	this->primitiveOperation1();
	this->primitiveOperation2();
}

Fundamental::~Fundamental()
{
	cout << "Fundamental::~Fundamental()" << endl;
}

void ConcreteClassA::primitiveOperation1()
{
	cout << "ConcreteClassA::primitiveOperation1()" << endl;
}

void ConcreteClassA::primitiveOperation2()
{
	cout << "ConcreteClassA::primitiveOperation2()" << endl;
}

ConcreteClassA::~ConcreteClassA()
{
	cout << "ConcreteClassA::~ConcreteClassA()" << endl;
}

void ConcreteClassB::primitiveOperation1()
{
	cout << "ConcreteClassB::primitiveOperation1()" << endl;
}

void ConcreteClassB::primitiveOperation2()
{
	cout << "ConcreteClassB::primitiveOperation2()" << endl;
}

ConcreteClassB::~ConcreteClassB()
{
	cout << "ConcreteClassB::~ConcreteClassB()" << endl;
}
