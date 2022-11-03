#include<iostream>
#include<string>
using namespace std;

void func(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void func(string& c, string& d)
{
	string temp;
	temp = c;
	c = d;
	d = temp;
	c = "yes";
}

int main()
{
	int a = 10, b = 20;
	func(a, b);
	cout << a << "    " << b << endl;

	string c = "hello";
	string d = "word";
	cout << c << "   " << d << endl;

}