//facade.cpp
//���ģʽ��Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һ�µĽ���

#include "gtest/gtest.h"

class SubSystem1
{
public:
	SubSystem1() {}
	~SubSystem1() {}
	int Method1()
	{
		return 1;
	}
};

class SubSystem2
{
public:
	SubSystem2() {}
	~SubSystem2() {}
	int Method2()
	{
		return 2;
	}
};

class Facade
{
public:
	Facade() {}
	~Facade() {}
	int MethodA()
	{
		return sub1.Method1()+sub2.Method2();
	}

private:
	SubSystem1 sub1;
	SubSystem2 sub2;

};

TEST(FACADE,facade)
{
	Facade* facade = new Facade();

	EXPECT_EQ(3,facade->MethodA());

	delete facade;
}