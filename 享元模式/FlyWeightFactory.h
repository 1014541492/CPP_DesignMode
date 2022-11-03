#pragma once
#include"FlyWeight.h"
#include<vector>
using namespace std;
class FlyWeightFactory //FlyweightFactory（享元工厂类）
{//创建并管理享元对象。它需要确保合理地共享享元对象；当用户请求一个具体享元对象时，享元工厂对象提供一个已创建的实例，如果请求的实例不存在的情况下，就新创建一个实例。
public:
	FlyWeightFactory();
	~FlyWeightFactory();
	FlyWeight* GetFlyWeight(int key); //工厂方法，根据所传入的参数返回享元池中的享元对象
private: //定义享元池用于存储多个具体享元对象
	vector<FlyWeight*> m_flyweights;////很多时候为了增加效率，使用hash表之类的结构，这里简单的使用vector
};