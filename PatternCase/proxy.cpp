//proxy.cpp
//����ģʽ��Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ�����

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