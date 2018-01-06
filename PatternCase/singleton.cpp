//singleton.cpp
//单例：保证一个类仅有一个实例，并提供一个访问它的全局访问点。

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
