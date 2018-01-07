//composite.cpp
//组合模式：将对象组合成树形结构以表“部分-整体”的层次结构。

#include "gtest/gtest.h"
#include <string>
#include <list>

class Component
{
public:
	Component() {}
	virtual ~Component() {}

	virtual int Add(Component*) = 0;
	virtual int Remove(Component*) = 0;
	virtual int Operation() = 0;
};

class Leaf : public Component
{
public:
	Leaf(std::string n) : name(n) {}
	~Leaf() {}

	int Add(Component* c)
	{
		return 0;
	}

	int Remove(Component* c)
	{
		return 0;
	}

	int Operation()
	{
		return int('L');
	}

private:
	std::string name;
};


class Composite : public Component
{
public:
	Composite(std::string n) : name(n) {}
	~Composite() 
	{
		std::list<Component*>::iterator i;
		for (i = lst.begin();i != lst.end();i++)
		{
			delete *i;
		}
	}

	int Add(Component* c)
	{
		lst.push_back(c);
		return 0;
	}

	int Remove(Component* c)
	{
		lst.remove(c);
		return 0;
	}

	int Operation()
	{
		return int('C');
	}

private:
	std::string name;
	std::list<Component*> lst;
};



TEST(Composite,composite)
{
	Composite* root = new Composite("root");
	root->Add(new Leaf("Leaf A"));
	root->Add(new Leaf("Leaf B"));

	Composite* compo = new Composite("composite1");
	root->Add(new Leaf("Leaf C"));
	root->Add(new Leaf("Leaf D"));

	root->Add(compo);

	delete root;
}
