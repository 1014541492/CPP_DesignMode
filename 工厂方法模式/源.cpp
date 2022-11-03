/*����ԭ��һ�����ʵ�����࣬ģ��ͺ���Ӧ�ö���չ����(���ṩ��)�����޸Ĺر�(��ʹ�÷�)���ó��󹹽���ܣ���ʵ����չϸ�ڡ�
 �������Ҫ�仯ʱ������ͨ����չ���ʵ�����Ϊ��ʵ�ֱ仯��������ͨ���޸����еĴ�����ʵ�ֱ仯��
* �򵥹���ģʽ Υ���˿���ԭ��
* ��������ģʽ���壺�ڹ���ģʽ�У��������ฺ���崴����Ʒ����Ĺ���ӿڣ����������ฺ�����ɾ���Ĳ�Ʒ����
Ŀ���ǽ���Ʒ��ʵ���������ӳٵ�������������ɣ�ͨ������������ȷ������Ӧ��ʵ������һ�������Ʒ�ࡣ
*���Ĺ����಻�ٸ����Ʒ�Ĵ����������������Ϊһ�����󹤳���ɫ����������幤���������ʵ�ֵĽӿڣ�
��һ�����󻯵ĺô���ʹ�ù�������ģʽ����ʹϵͳ�ڲ��޸ľ��幤����ɫ������������µĲ�Ʒ��
* Ӧ�ã����ǵ���Ʒ�ں��ڻ������չ������£�����ʹ�ù�������ģʽ����Ʒ�ṹ�ϸ��ӵ�����£�����ʹ�ù�������ģʽ��
* �ŵ㣺���ϡ�����ԭ��ϵͳ�����²�Ʒʱ�������޸ĳ��󹤳��ͳ����Ʒ�ṩ�Ľӿڣ������޸Ŀͻ��ˣ�Ҳ�����޸������ľ��幤���;����Ʒ����ֻҪ���һ�����幤���;����Ʒ���ɡ�
* ȱ�㣺������²�Ʒʱ����Ҫ��д�µľ����Ʒ�࣬����Ҫ�ṩ��֮��Ӧ�ľ��幤���࣬ϵͳ����ĸ������ɶ����ӣ�һ���̶���������ϵͳ�ĸ��Ӷȡ�
*/
#include<iostream>
using namespace std;
class TV//�����Ʒ�� ��Ʒ����Ĺ�ͬ�����ӿ�
{
public:
	virtual void show() = 0;
	virtual ~TV() {};
};
class HairTV :public TV//�����Ʒ�� �����Ʒʵ���˳����Ʒ�Ľӿڣ�ĳ�����͵ľ����Ʒ��ר�ŵľ��幤��������
{
public:
	void show() { cout << "Hair movie" << endl; }
};
class HisenseTV :public TV
{
public:
	void show() { cout << "Hisense movie" << endl; }
};

class TVFactory //���󹤳���
{
public:
	virtual TV* CreateTV() = 0;
	virtual ~TVFactory() {};
};

class HairTVFactory :public TVFactory//���幤���� ���幤���ǳ��󹤳�������࣬ʵ���˳��󹤳��ж���Ĺ��������������ɿͻ����ã�����һ�������Ʒ���ʵ����
{
public:
	TV* CreateTV() { return new HairTV(); }
};
class HisenseTVFactory :public TVFactory
{
public:
	TV* CreateTV() { return new HisenseTV(); }
};

int main()
{
	TVFactory* hair_fac = new HairTVFactory();
	TV* hair = hair_fac->CreateTV();
	hair->show();

	TVFactory* hisense_fac = new HisenseTVFactory();
	TV* hisense = hisense_fac->CreateTV();
	hisense->show();

	if (hair_fac != NULL) { delete hair_fac; hair_fac = NULL; }
	if (hair != NULL) { delete hair; hair = NULL; }
	if (hisense_fac != NULL) { delete hisense_fac; hisense_fac = NULL; }
	if (hisense != NULL) { delete hisense; hisense = NULL; }
}