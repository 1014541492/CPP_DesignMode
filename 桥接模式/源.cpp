/*
* �Ž�ģʽ�������󲿷�������ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����ر仯����һ�ֶ���ṹģʽ��
��������ʵ�ַ��룬ʹ���ǿ��Զ����仯�������ù�����ϵ����ϻ�ۺϹ�ϵ������̳й�ϵ��ʵ�֣��Ӷ������˳����ʵ���������ɱ�ά�ȵ���϶ȡ�
�������Žӣ� ������һ���ģ�����Ͷ���������һ�������ӡ�
�磺��״-�����࣬��ɫ-�����࣬�����������һ����һ����������ϵ����״ӵ������ɫ ���������˹�ϵ��
* 
* Ӧ�ã���һ�����ڲ��߱����ֻ���ֱ仯ά��ʱ��ʹ���Ž�ģʽ���Խ�����Щ�仯��ά�ȣ�ʹ�߲����ܹ��ȶ����Ž�ģʽͨ�����������³�����
1.��һ����������������仯��ά�ȣ���������ά�ȶ���Ҫ������չʱ��
2.��һ��ϵͳ��ϣ��ʹ�ü̳л���Ϊ���μ̳е���ϵͳ��ĸ�����������ʱ��
3.��һ��ϵͳ��Ҫ�ڹ����ĳ��󻯽�ɫ�;��廯��ɫ֮�����Ӹ���������ʱ

* �ŵ㣺
��1����������༰��ʵ�ֲ��֡��Ž�ģʽʹ�á������Ĺ�����ϵ�������˳����ʵ��֮�� ���еİ󶨹�ϵ��ʹ�ó����ʵ�ֿ������Ÿ��Ե�ά�����仯��
��2���Ž�ģʽ�Ǳȶ�̳з������õĽ��������
��3���Ž�ģʽ�����ϵͳ�Ŀ���չ�ԣ��������仯ά����������չһ��ά�ȣ�������Ҫ�޸�ԭ�е�ϵͳ��
��4��ʵ��ϸ�ڶԿͻ�͸�������Զ��û�����ʵ��ϸ�ڡ��û���ʹ��ʱ����Ҫ��ϵʵ�֣��ڳ����ͨ���ۺϹ�����ϵ��ɷ�װ�������ϡ�

ȱ�㣺
��1���Ž�ģʽ�����������ϵͳ�����������Ѷȡ��ۺϹ�ϵ�����ڳ���㣬Ҫ�󿪷�����Գ������������̡�
��2���Ž�ģʽҪ����ȷʶ���ϵͳ�����������仯��ά�ȣ����ʹ�÷�Χ����һ���ľ����ԡ�
* 
*/


//ʵ�������ֻ�֧����ʽ΢�š�֧����APP����ÿ��APP֧�����ָ�����֤��ʽ�����롢ָ�ơ����������Ž�ģʽ��ʵ�ַ�ʽ���£�
//IPayMode����ʵ���࣬�����˻�������security()������������֤��ʽ���������ṩ��ʵ�֣���λ���Ž�ģʽ�ĳ���㡣

#include<iostream>
#include<string>
using namespace std;

class IPayMode //ʵ����ӿڣ�Ϊ���о���ʵ������ͨ�ýӿڡ����󲿷ֽ���ͨ�������������ķ�����ʵ�ֶ��󽻻�
{
public:
	virtual bool security(string uid) = 0;
};

class PayCypher : public IPayMode //����ʵ���ࣺ
{
public:
	bool security(string uid) override
	{
		cout << "Password to pay" << endl;
		return true;
	}
};
class PayFace :public IPayMode
{
public:
	bool security(string uid)override
	{
		cout << "Face to pay" << endl;
		return true;
	}
};
class PayFinger :public IPayMode
{
public:
	bool security(string uid)override
	{
		cout << "Finger to pay" << endl;
		return true;
	}
};

class Pay//������ ���ڶ��������Ľӿڣ����ж�����һ��Implementation��ʵ����ӿڣ��Ķ��󲢿���ά���ö������� Implementation���й�����ϵ��
{
public:
	Pay(IPayMode* mode) //�������е�mode��ʵ����ӿ�IPayMode���ڹ���
	{
		this->mode = mode;
	}
	virtual ~Pay() { delete mode; }
	virtual string transfer(string UID, string ID, long long amount) = 0;

	IPayMode* mode;
};

class WxPay :public Pay //��������ࣺ������Abstraction����Ľӿڣ�ͨ���������ǳ�������Ǿ����ࡣ�ṩ�����߼��ı��塣���丸��һ��������ͨ��ͨ��ʵ�ֽӿ��벻ͬ��ʵ�ֽ��н���
{                       //�ṩ�߲�����߼�����������ɵײ�ʵ�ʹ�����ʵ�ֶ���
public:
	WxPay(IPayMode* mode) :Pay(mode){}
	string transfer(string UID, string ID, long long amount)
	{
		cout << "VxPay " << "UID:" << UID << "ID:" << ID << "amount:" << amount << endl;
		bool security = mode->security(UID);
		if (!security)
		{
			cout << "WxPay Failed" << endl;
			return "0001";
		}
		else
		{
			cout << "WxPay Succeed" << endl;
			return"0000";
		}
	}
};
class ZfbPay :public Pay
{
public:
	ZfbPay(IPayMode* mode) :Pay(mode) {}
	string transfer(string UID, string ID, long long amount)
	{
		cout << "ZfbPay " << "UID:" << UID << "ID:" << ID << "amount:" << amount << endl;
		bool security = mode->security(UID);
		if (!security)
		{
			cout << "ZfbPay Failed" << endl;
			return "0001";
		}
		else
		{
			cout << "ZfbPay Succeed" << endl;
			return"0000";
		}
	}
};

int main() //�ͻ��� �������������󲿷ֺ��������ǣ�Client��Ҫ�����������һ��ʵ�ֶ�������������
{
	Pay* wx = new WxPay(new PayFace());
	wx->transfer("wx", "123456", 100);
	cout << endl;
	Pay* zfb = new ZfbPay(new PayCypher());
	zfb->transfer("zfb", "666", 200);
}



//override��д�ؼ��ʣ�����C++�п��Լ����Щ�麯��û�б���д������
//ע����������ĳ�Ա������ʹ��overrideʱ������������޴˺�����������еĺ����������麯�����������������ش�����Ϣ��

//��һְ��ԭ�򣺶���һ���ֻ࣬��һ���������仯��ԭ�򣻸����ְ����Ψһ�ģ������ְ����Ψһ����������仯��ԭ��
//Ŀ�ģ����ʹ��븴�Ӷȡ�ϵͳ����ϡ���߿ɶ���
//���������ͬ��ְ���װ����ͬ�������ģ���С� �����µ��������е�ְ���Ϊ�����ȸ�С��ְ���ʱ��Ӧ�ü�ʱ�����д�������ع���
//��ϵͳ�߼��㹻�򵥣������㹻�٣����๻�ٻ������������ʱ��Ҳ���Բ����ϸ���ѭ��SRPԭ�򣬱��������ơ��������������ء�