//factory.cpp
//工厂模式

#include <string>
#include "gtest/gtest.h"

class Operation
{
public:
	Operation() : x(0),
				  y(0)
	{}

	virtual ~Operation() {}
	int x;
	int y;
	virtual int GetResult() = 0;
};

//加法
class OperationAdd : public Operation
{
public:
	OperationAdd() {}
	virtual ~OperationAdd() {}

	virtual int GetResult()
	{
		return x+y;
	}
};


//减法
class OperationSub : public Operation
{
public:
	OperationSub() {}
	virtual ~OperationSub() {}

	virtual int GetResult()
	{
		return x-y;
	}
};


//////////////////////////////////////////////////////////////////////////
//简单工厂
class SimpleFactory
{
public:
	SimpleFactory() {}
	~SimpleFactory() {}

	static Operation* CreateOperate(std::string op)
	{
		if (op == "+")
		{
			
			return new OperationAdd();
		}

		if (op == "-")
		{
			return new OperationSub();
		}

		return NULL;
	}

};

TEST(Factory,SimpleFactory)
{
	Operation* op;
	op = SimpleFactory::CreateOperate("+");
	op->x = 1;
	op->y = 2;
	EXPECT_EQ(3,op->GetResult());
	delete op;

	op = SimpleFactory::CreateOperate("-");
	op->x = 1;
	op->y = 2;
	EXPECT_EQ(-1,op->GetResult());
	delete op;
}


//////////////////////////////////////////////////////////////////////////
//工厂方法
class Factory
{
public:
	Factory() {}
	virtual ~Factory() {}
	
	virtual Operation* CreateOperation() = 0;
};

class FactoryAdd : public Factory
{
public:
	FactoryAdd() {}
	~FactoryAdd() {}
	
	Operation* CreateOperation()
	{
		return new OperationAdd();
	}
};

class FactorySub : public Factory
{
public:
	FactorySub() {}
	~FactorySub() {}

	Operation* CreateOperation()
	{
		return new OperationSub();
	}
};

TEST(Factory,Factory)
{
	Operation* op;
	Factory* factory;

	factory = new FactoryAdd();
	op = factory->CreateOperation();
	op->x = 1;
	op->y = 2;
	EXPECT_EQ(3,op->GetResult());
	delete op;
	delete factory;

	factory = new FactorySub();
	op = factory->CreateOperation();
	op->x = 1;
	op->y = 2;
	EXPECT_EQ(-1,op->GetResult());
	delete op;
	delete factory;

}

//////////////////////////////////////////////////////////////////////////


