//proxy.cpp
//代理模式：为其它对象提供一种代理以控制对这个对象的方法。

#include "gtest/gtest.h"

class Subject
{
public:
	Subject() {}
	virtual ~Subject() {}

	virtual int Request() = 0;
};

class RealSubject
{
public:
	RealSubject() {}
	virtual ~RealSubject() {}

	int Request()
	{
		return 1;
	}
};

class Proxy : Subject
{
public:
	Proxy() {}
	~Proxy() {}

	int Request()
	{
		return subj.Request();
	}

private:
	RealSubject subj;
};

TEST(PROXY,proxy)
{
	Proxy* proxy = new Proxy();
	EXPECT_EQ(1,proxy->Request());
	delete proxy;
}