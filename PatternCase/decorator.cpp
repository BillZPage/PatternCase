//decorator.cpp
//装饰模式：动态地给一个对象添加一些额外的职责

#include "gtest/gtest.h"

class Component
{
public:
	Component() {}
	virtual ~Component() {}

	virtual int Operation() = 0;
};

class ConcreteComponent : public Component
{
public:
	ConcreteComponent() {}
	~ConcreteComponent() {}

	int Operation()
	{
		return 1;
	}

};

class Decorator : public Component
{
public:
	Decorator() {}
	virtual ~Decorator() {}

	int Operation()
	{
		if (component)
		{
			return component->Operation();
		}

		return -1;
	}

	void SetComponent(Component* comp)
	{
		component = comp;
	}

protected:
	Component* component;
};

class ConcreteDecoratorA : public Decorator
{
public:
	ConcreteDecoratorA() {}
	~ConcreteDecoratorA() {}
	int Operation()
	{
		int tmp = component->Operation();
		return AddBehavior(tmp);
	}

	int AddBehavior(int x)
	{
		return x+1;
	}
};

class ConcreteDecoratorB : public Decorator
{
public:
	ConcreteDecoratorB() {}
	~ConcreteDecoratorB() {}
	int Operation()
	{
		return AddBehavior(component->Operation());
	}

	int AddBehavior(int x)
	{
		return x+1;
	}
};

TEST(Decorator,decorator)
{
	ConcreteComponent* c = new ConcreteComponent();
	ConcreteDecoratorA* d1 = new ConcreteDecoratorA();
	ConcreteDecoratorB* d2 = new ConcreteDecoratorB();

	d1->SetComponent(c);
	d2->SetComponent(d1);
	EXPECT_EQ(3,d2->Operation());

	delete c;
	delete d1;
	delete d2;
}