//adapter.cpp
//������ģʽ�������󲿷�������ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����ر仯

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