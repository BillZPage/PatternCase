//flyweight.cpp
//享元模式：运用共享技术有效地支持大量细粒度对象。

#include "gtest/gtest.h"
#include <map>

class Flyweight
{
public:
	Flyweight() {}
	virtual ~Flyweight() {}
	virtual int Operation() = 0;
};


class ConcreteFlyweight1 : public Flyweight
{
public:
	ConcreteFlyweight1() {}
	virtual ~ConcreteFlyweight1() {}

	int Operation()
	{
		return 1;
	}
};

class ConcreteFlyweight2 : public Flyweight
{
public:
	ConcreteFlyweight2() {}
	virtual ~ConcreteFlyweight2() {}

	int Operation()
	{
		return 2;
	}
};



class FlyweightFactory
{
public:
	FlyweightFactory()
	{
		flyweight['1'] = new ConcreteFlyweight1;
		flyweight['2'] = new ConcreteFlyweight2;
	}

	virtual ~FlyweightFactory() 
	{
		delete flyweight['1'];
		delete flyweight['2'];
	}

	Flyweight* GetFlyweight(char key)
	{
		return flyweight[key];
	}

private:
	std::map<char,Flyweight*> flyweight;
};

TEST(Flyweight,flyweight)
{
	FlyweightFactory* factory = new FlyweightFactory();

	Flyweight* f1 = factory->GetFlyweight('1');
	EXPECT_EQ(1,f1->Operation());

	Flyweight* f2 = factory->GetFlyweight('2');
	EXPECT_EQ(2,f2->Operation());

}