#include"FlyWeightFactory.h"
FlyWeightFactory::FlyWeightFactory()
{
	FlyWeight* tmp = new ConcreteFlyWeight();
	m_flyweights.push_back(tmp);
}

FlyWeightFactory::~FlyWeightFactory()
{
	FlyWeight* tmp = m_flyweights.at(0);
	delete tmp;
	tmp = NULL;
}

FlyWeight* FlyWeightFactory::GetFlyWeight(int key)
{
	return m_flyweights.at(key);
}