/*���⣺����������࣬��Ҫnew����������
* ����Ҫ��ϵ����Ĵ������̣�ע�ض����ʵ�ʲ���
* �������Ĵ����Ͳ��������֣�������ڵ�ά����
* �ŵ㣺���ھ۵����ԭ���߼����ֺ͹��ܲ��ַָ
* ȱ�㣺��Ʒ�Ĵ�����һ�����������������Ʒ�빤����֮����϶ȸߣ�����Ӱ����ϵͳ������Ժ���չ�ԡ�һ�������²�Ʒ������Ҫ�޸Ĺ����߼���������ϵͳ����չ��ά��
* �򵥹���ģʽ��ר�Ŷ���һ���������𴴽��������ʵ������������ʵ��ͨ�����й�ͬ�ĸ��ࡣ
* �򵥹���ģʽ����һ��ʵ��������ķ�ʽ��ֻҪ������Ҫʵ������������֣����������Ϳ���ͨ�������������Ӧ������������������Ҫ�Ķ���
*/


#include<iostream>
using namespace std;

typedef enum tv_type //ö������ �ų���
{
	Hair,
	Hisense,
}type;

class TV//�����Ʒ�� TV�� Ϊ����ʵ���ṩ�ӿ�
{
public:
	virtual void show() = 0;//����ǰ�����virtual�ؼ��֣�����麯������ô�������ڱ����ʱ��Ͳ���ȷ�����������ˡ�����ϣ������ʲô������ô�͵���ʲô����ĺ���
	virtual ~TV() {}//������������Ϊ�麯������ֹ�ڴ�й©
};

class HairTV : public TV //�����Ʒ�� ��ֻ���Ĳ������֣�
{
public:
	void show() { cout << "Hair movie" << endl; }
};
class HisenseTV :public TV
{
public:
	void show() { cout << "Hisense movie" << endl; }
};

class TVFactory //������ ���������֣������ģ�ʵ���ڲ��߼�
{
public:
	TV* CreateTV(type str) //���ݲ�����ͬ ���ز�ͬ��ʵ��
	{
		switch (str) //����ľ����ഴ������ �ڹ�����ʵ��
		{
		case Hair:
			return new HairTV();
		case Hisense:
			return new HisenseTV();
		default:
			return NULL;
		}
	}
};

int main() //����ģʽ���ԣ�������ʵ������α�������
{
	TVFactory* myTVFactory = new TVFactory();//����ģʽ���ԣ����󴴽�ģʽͨ��ʵ����ί�и���һ�������ഴ��ģʽͨ���̳иı�ʵ��������
	TV* hair = myTVFactory->CreateTV(Hair); // ����ģʽ���ԣ�����֪������ľ�������ʲô
	if (hair != NULL) { hair->show(); } //��̬ʹ������������ָ�������ָ���������
	TV* hisense = myTVFactory->CreateTV(Hisense);
	if (hisense != NULL) { hisense->show(); }

	delete hair, hisense;
	hair = hisense = 0;
	return 0;
}