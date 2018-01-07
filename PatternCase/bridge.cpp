//bridge.cpp
//桥接模式：将抽象部分与它的实现部分分离，使它们都可以独立地变化

#include "gtest/gtest.h"

class Implementor
{
public:
	Implementor() {}
	virtual ~Implementor() {}
	virtual int Operation() = 0;
};

class ConcreteImplementor1 : public Implementor
{
public:
	ConcreteImplementor1() {}
	virtual ~ConcreteImplementor1() {}
	virtual int Operation()
	{
		return 1;
	}
};

class ConcreteImplementor2 : public Implementor
{
public:
	ConcreteImplementor2() {}
	virtual ~ConcreteImplementor2() {}
	virtual int Operation()
	{
		return 2;
	}
};


class Abstraction
{
public:
	Abstraction() {}
	virtual ~Abstraction() {}
	virtual int Operation() = 0;
	void SetImplementor(Implementor* imp)
	{
		this->imp = imp;
	}

protected:
	Implementor* imp;
};

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction() {}
	virtual ~RefinedAbstraction() {}

	int Operation()
	{
		return imp->Operation();
	}
};



TEST(Bridge,bridge)
{
	Abstraction* ab = new RefinedAbstraction();

	Implementor* imp1 = new ConcreteImplementor1();
	ab->SetImplementor(imp1);
	EXPECT_EQ(1,ab->Operation());
	delete imp1;


	Implementor* imp2 = new ConcreteImplementor2();
	ab->SetImplementor(imp2);
	EXPECT_EQ(2,ab->Operation());
	delete imp2;

	delete ab;

}