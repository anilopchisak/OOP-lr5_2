#include <iostream>
using namespace std;

class Base
{
protected:
	int x;
public:
	Base()
	{
		printf("Base()\n");
		x = 0;
	}
	Base(int _x)
	{
		printf("Base(int _x)\n");
		x = _x;
	}
	Base(const Base& b)
	{
		printf("Base(const Base &b)\n");
		x = b.x;
	}
	virtual ~Base()
	{
		printf("~Base()\n");
	}
	virtual string classname()
	{
		printf("virtual string classname()\n");
		return "Base";
	}
	virtual bool isA(string classname) //проверка типов
	{
		printf("virtual bool isA(string classname) - Base\n");
		if (classname == "Base")
		{
			printf("true\n");
			return true;
		}
		printf("false\n");
		return false;
	}
};
class Inheritor1 : public Base
{
public:
	Inheritor1()
	{
		printf("Inheritor1()\n");
	}
	Inheritor1(int _x) : Base(_x)
	{
		printf("Inheritor1(int _x)\n");
	}
	Inheritor1(const Inheritor1& inh)
	{
		printf("Inheritor1(int _x)\n");
		x = inh.x;
	}
	~Inheritor1()
	{
		printf("~Inheritor1()\n");
	}
	string classname() override
	{
		printf("string classname() override - Inheritor1\n");
		return "Inheritor1";
	}
	bool isA(string classname) override 
	{
		printf("bool isA(string classname) override - Inheritor1\n");
		if (classname == "Inheritor1")
		{
			printf("true\n");
			return true;
		}
		printf("false\n");
		return false;
	}
};
class Inheritor2 : public Base
{
public:
	Inheritor2()
	{
		printf("Inheritor2()\n");
	}
	Inheritor2(int _x) : Base(_x)
	{
		printf("Inheritor2(int _x)\n");
	}
	Inheritor2(const Inheritor2& inh)
	{
		printf("Inheritor2(int _x)\n");
		x = inh.x;
	}
	~Inheritor2()
	{
		printf("~Inheritor2()\n");
	}
	string classname() override
	{
		printf("string classname() override - Inheritor2\n");
		return "Inheritor2";
	}
	bool isA(string classname) override
	{
		printf("bool isA(string classname) override - Inheritor2\n");
		if (classname == "Inheritor2")
		{
			printf("true\n");
			return true;
		}
		printf("false\n");
		return false;
	}
};
class Special
{
public:
	Special()
	{
		printf("Special()\n");
	}
	/*Special(int _x) : Base(_x)
	{
		printf("Inheritor2(int _x)\n");
	}
	Inheritor2(const Inheritor2& inh)
	{
		printf("Inheritor2(int _x)\n");
		x = inh.x;
	}*/
	~Special()
	{
		printf("~Special()\n");
	}
	string classname()
	{
		printf("string classname() override - Special\n");
		return "Special";
	}
	bool isA(string classname)
	{
		printf("bool isA(string classname) override - Special\n");
		if (classname == "Special")
		{
			printf("true\n");
			return true;
		}
		printf("false\n");
		return false;
	}
};

int main()
{
	//проверка типов isA и classname
	Base* base = new Inheritor1(); printf("\n");
	Inheritor1* inh1 = new Inheritor1(); printf("\n");
	Inheritor2* inh2 = new Inheritor2(); printf("\n");
	Special* spec = new Special(); printf("\n\n");

	//проверка типов
	base->isA(base->classname()); printf("\n");
	base->isA(inh1->classname()); printf("\n");
	base->isA(inh2->classname()); printf("\n");
	base->isA(spec->classname()); printf("\n");
	printf("\n\n");
	
	inh1->isA(inh1->classname()); printf("\n");
	printf("\n\n");
	
	inh2->isA(inh2->classname()); printf("\n");
	inh2->isA(inh1->classname()); printf("\n");
	printf("\n\n");

	spec->isA(inh1->classname()); printf("\n");

	delete base; printf("\n");
	delete inh1; printf("\n");
	delete inh2; printf("\n");

	//Продемонстрировать опасное приведение типов и предварительную проверку типа с помощью 
	//реализованного метода isA. Продемонстрировать использование стандартных средств языка 
	//(dynamic_cast в c++ или аналог на используемом языке).

	return 0;
}