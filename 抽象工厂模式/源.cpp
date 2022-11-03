/*
* ���󹤳�ģʽ�ǹ�������ģʽ�ķ����棬����ģʽ��һ������ĳ��󹤳�ģʽ��
�ڹ���ģʽ�У�ÿ�����幤��ֻ������һ�־���Ĳ�Ʒ���纣�����ӻ���ֻ�����������ӻ��������󹤳�����ģʽ�У�һ������Ĺ�������������������Ʒ��
*Ӧ�ã�����һ���̳���ϵ�У���������Ŷ���ȼ��ṹ���������Ŷ�������ࣩ�����ҷ��������ȼ��ṹ�е�ʵ����֮�������һ���Ĺ�������Լ�����Ϳ���ʹ�ó��󹤳�ģʽ��
��������ȼ��ṹ�е�ʵ����֮�䲻���ڹ�����Լ������ʹ�ö�������Ĺ������Բ�Ʒ���д������������һ�㡣
�ʺ��ڲ�Ʒ֮���໥�������໥�������໥Լ���ĵط�����Ҫ��̬�л���Ʒ��ĵط�
*�ŵ㣺1.���󹤳�ģʽ����Ʒ���������Լ����ϵ�ŵ����󹤳��У����ڹ���
2.ְ�����û�����Ҫ����һ���Լ������ĵ�ϸ�ڣ��ɳ��󹤳�����������Ĵ���
3.�л���Ʒ�����ף�ֻ��Ҫ����һ�����幤��ʵ�֣��ͻ���ѡ����һ���ײ;Ϳ�����
*ȱ�㣺ȱ�㣺1.���󹤳�ģʽ�����ӵ��ٶȺܿ죬��һ����Ʒ�����Ҫ����һ�����幤��ʵ�֣��ȽϷ���
2.��Ʒ��������չ��Ʒ������Ʒ��������һ����Ʒʱ�����󹤳��ӿ�����Ҫ����һ����������Ӧ�����о��幤��ʵ�ֶ���Ҫ�޸ģ��޸ķŴ����ء�
3.���󹤳���δ��ȫ���δ���ϸ�ڣ������Ķ����������������������Խ�Ϲ���ģʽ��򵥹���ģʽһ��ʹ�á�
*/
//��һ�������������������������͵ĵ������纣���������������������ӻ��������յ��ȣ�TCL������������TCL���ӡ�TCL�յ��ȡ�
//��ͬƷ�Ƶĵ�������һ����Ʒ�壬����ͬ���͵ĵ���������һ����Ʒ�ȼ��ṹ��

#include <iostream>
using namespace std;
class TV //�����Ʒ��
{
public:
	virtual void show() = 0;
	virtual ~TV(){};
};
class AC 
{
public:
	virtual void show() = 0;
	virtual ~AC(){};
};

class HairTV :public TV//�����Ʒ��
{
public:
	void show() { cout << "Hair movie" << endl; }
};
class HisenseTV :public TV
{
public:
	void show() { cout << "Hisense movie" << endl; }
};
class HairAC :public AC
{
public:
	void show() { cout << "Hair air" << endl; }
};
class HisenseAC :public AC
{
public:
	void show() { cout << "Hisense air" << endl; }
};

class Factory//���󹤳��� �������ɳ����Ʒ�ķ�������һ�����󹤳��п��Զ���һ�鷽����ÿһ��������Ӧһ����Ʒ�ȼ��ṹ��
{
public:
	virtual TV* CreateTV() = 0;
	virtual AC* CreateAC() = 0;
	virtual ~Factory() {};
};

class HairFactory :public Factory//���幤���� ʵ���˳��󹤳������ĳ����Ʒ�ķ���������һ������Ʒ
{
public:
	TV* CreateTV() { return new HairTV(); }
	AC* CreateAC() { return new HairAC(); }
};
class HisenseFactory :public Factory
{
public:
	TV* CreateTV() { return new HisenseTV(); }
	AC* CreateAC() { return new HisenseAC(); }
};

int main()
{
	Factory* hair_fac = new HairFactory();
	TV* hair_tv = hair_fac->CreateTV();
	AC* hair_ac = hair_fac->CreateAC();
	hair_tv->show();
	hair_ac->show();

	Factory* hisense_fac = new HisenseFactory();
	TV* hisense_tv = hisense_fac->CreateTV();
	AC* hisense_ac = hisense_fac->CreateAC();
	hisense_tv->show();
	hisense_ac->show();

	if (hair_fac != NULL) { delete hair_fac; hair_fac = NULL; }
	if (hair_tv != NULL) { delete hair_tv; hair_tv = NULL; }
	if (hair_ac != NULL) { delete hair_ac; hair_ac = NULL; }
	if (hisense_fac != NULL) { delete hisense_fac; hisense_fac = NULL; }
	if (hisense_tv != NULL) { delete hisense_tv; hisense_tv = NULL; }
	if (hisense_ac != NULL) { delete hisense_ac; hisense_ac = NULL; }
}

/*
* �ܽ᣺��ʵ���󹤳�ģʽ���ֻ��һ������Ļ�����ʵ���˻����˹�������ģʽ��Ҳ����û���˲�Ʒ��ĸ��ֻʣһ����Ʒ�ˣ�
��˼򵥹������������������󹤳�������֮������������ϵ�ģ�����ֻ�ǲ�Ʒ�ĸ��Ӷȡ�
���󹤳��ı�����ѡ���Ʒ�壬��˴�ҿ��Ը������������ʶ���Ƿ����Ӧ�ó��󹤳�

�򵥹�����Ψһ�����࣬һ����Ʒ�����࣬������Ĵ���������������жϲ����������Ʒ����
������������������࣬һ����Ʒ�����࣬���ö�̬������ͬ�Ĳ�Ʒ���󣬱����˴�����if-else�жϡ�
���󹤳�����������࣬�����Ʒ�����࣬��Ʒ������飬ͬһ������ʵ���ഴ��ͬ���еĲ�ͬ��Ʒ�������˹������������

*/