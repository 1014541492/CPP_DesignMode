#pragma once
#include"FlyWeight.h"
#include<vector>
using namespace std;
class FlyWeightFactory //FlyweightFactory����Ԫ�����ࣩ
{//������������Ԫ��������Ҫȷ������ع�����Ԫ���󣻵��û�����һ��������Ԫ����ʱ����Ԫ���������ṩһ���Ѵ�����ʵ������������ʵ�������ڵ�����£����´���һ��ʵ����
public:
	FlyWeightFactory();
	~FlyWeightFactory();
	FlyWeight* GetFlyWeight(int key); //��������������������Ĳ���������Ԫ���е���Ԫ����
private: //������Ԫ�����ڴ洢���������Ԫ����
	vector<FlyWeight*> m_flyweights;////�ܶ�ʱ��Ϊ������Ч�ʣ�ʹ��hash��֮��Ľṹ������򵥵�ʹ��vector
};