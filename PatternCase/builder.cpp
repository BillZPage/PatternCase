//builder.cpp
//������ģʽ�����ڴ���һЩ���Ӷ�����Щ�����ڲ��������
//����˳��ͨ�����ȶ��ģ����Ƕ����ڲ��Ĺ���ͨ�������Ÿ��ӵı仯��

#include "gtest/gtest.h"
#include <string>

//��Ʒ
class Product
{
public:
	Product() {}
	~Product() {}
	std::string value;
};

//
class Builder
{
public:
	Builder() {}
	virtual ~Builder() {}

	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
	virtual Product* GetResult() = 0;
};

class ConcreteBuilder1 : public Builder
{
public:
	ConcreteBuilder1() 
	{
		product = new Product();
	}

	~ConcreteBuilder1() {}

	void BuildPartA()
	{
		product->value += "A1";
	}

	void BuildPartB()
	{
		product->value += "B1";
	}

	Product* GetResult()
	{
		return product;
	}

private:
	Product* product;
};

class ConcreteBuilder2 : public Builder
{
public:
	ConcreteBuilder2() 
	{
		product = new Product();
	}

	~ConcreteBuilder2() {}

	void BuildPartA()
	{
		product->value += "A2";
	}

	void BuildPartB()
	{
		product->value += "B2";
	}

	Product* GetResult()
	{
		return product;
	}

private:
	Product* product;
};


//ָ����
class Director
{
public:
	Director() {}
	~Director() {}

	void Construct(Builder* builder)
	{
		builder->BuildPartA();
		builder->BuildPartB();
	}
};

TEST(Builder,builder)
{
	Director* director = new Director();
	Builder* builder1 = new ConcreteBuilder1();
	Builder* builder2 = new ConcreteBuilder2();

	director->Construct(builder1);
	Product* p1 = builder1->GetResult();
	EXPECT_STREQ("A1B1",p1->value.c_str());

	director->Construct(builder2);
	Product* p2 = builder2->GetResult();
	EXPECT_STREQ("A2B2",p2->value.c_str());

	delete director;
	delete builder1;
	delete builder2;
	delete p1;
	delete p2;
}