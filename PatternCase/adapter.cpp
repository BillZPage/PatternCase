//adapter.cpp
//适配器模式：将抽象部分与它的实现部分分离，使它们都可以独立地变化

#include "gtest/gtest.h"

class Target
{
public:
	Target() {}
	virtual ~Target() {}
	virtual int Request() = 0;
};

class Adaptee
{
public:
	Adaptee() 
	{
		value = 1;
	}

	~Adaptee() {}
	int value;
};

class Adapter : public Target
{
public:
	Adapter() 
	{
		adp = new Adaptee();
	}

	~Adapter() 
	{
		delete adp;
	}

	virtual int Request()
	{
		return adp->value;
	}

private:
	Adaptee* adp;
};


TEST(Adapter,adapter)
{
	Target* target = new Adapter();
	EXPECT_EQ(1,target->Request());
	delete target;	
}