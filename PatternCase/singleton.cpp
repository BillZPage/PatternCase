//singleton.cpp
//��������֤һ�������һ��ʵ�������ṩһ����������ȫ�ַ��ʵ㡣

#include <gtest/gtest.h>

class Singleton
{
public:
	~Singleton() {}
	
	static Singleton* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Singleton();
		}
		return instance;
	}

private:
	static Singleton* instance;
	Singleton() {}
};

Singleton* Singleton::instance = NULL;


TEST(Singleton,Singleton)
{
	Singleton* single1 = Singleton::GetInstance();
	Singleton* single2 = Singleton::GetInstance();

	EXPECT_EQ(single1,single2);

	delete single1;
}
