//prototype.cpp
//原型模式：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象

#include "gtest/gtest.h"

class Prototype
{
public:
	Prototype() {}
	virtual ~Prototype() {}
	virtual Prototype* Clone() = 0;
};

class ConcretePrototype1 : public Prototype
{
public:
	ConcretePrototype1() : value(1) 
	{}

	~ConcretePrototype1() {}

	Prototype* Clone()
	{
		return new ConcretePrototype1(*this);
	};

	int GetValue()
	{
		return value;
	}

private:
	int value;

};

TEST(Prototype,prototype)
{
	Prototype* p1 = new ConcretePrototype1();
	Prototype* p2 = p1->Clone();

	EXPECT_EQ(1,((ConcretePrototype1*)p2)->GetValue());

	delete p1;
	delete p2;
}