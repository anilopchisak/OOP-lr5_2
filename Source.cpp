#include <iostream>
using namespace std;

class Base
{
//protected:
//	int x;
public:
	Base()
	{
		printf("Base()\n");
		//x = 0;
	}
	/*Base(int _x)
	{
		printf("Base(int _x)\n");
		x = _x;
	}
	Base(const Base& b)
	{
		printf("Base(const Base &b)\n");
		x = b.x;
	}*/
	virtual ~Base()
	{
		printf("~Base()\n");
	}
	virtual string classname()
	{
		printf("virtual string classname() - Base\n");
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
	/*Inheritor1(int _x)
	{
		printf("Inheritor1(int _x)\n");
	}
	Inheritor1(const Inheritor1& inh)
	{
		printf("Inheritor1(int _x)\n");
		x = inh.x;
	}*/
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
		return Base::isA(classname); //вызов метода предка
	}
	void OK1()
	{
		printf("void OK1() - Inheritor1");
	}
};
class Inheritor2 : public Base
{
public:
	Inheritor2()
	{
		printf("Inheritor2()\n");
	}
	/*Inheritor2(int _x) : Base(_x)
	{
		printf("Inheritor2(int _x)\n");
	}
	Inheritor2(const Inheritor2& inh)
	{
		printf("Inheritor2(int _x)\n");
		x = inh.x;
	}*/
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
		return Base::isA(classname);
	}
	void OK2()
	{
		printf("void OK2() - Inheritor2");
	}
};
class Inheritor3 : public Base
{
public:
	Inheritor3()
	{
		printf("Inheritor3()\n");
	}
	/*Inheritor3(int _x) : Base(_x)
	{
		printf("Inheritor2(int _x)\n");
	}
	Inheritor3(const Inheritor3& inh)
	{
		printf("Inheritor3(int _x)\n");
		x = inh.x;
	}*/
	~Inheritor3()
	{
		printf("~Inheritor3()\n");
	}
	string classname() override
	{
		printf("string classname() override - Inheritor3\n");
		return "Inheritor3";
	}
	bool isA(string classname) override
	{
		printf("bool isA(string classname) override - Inheritor3\n");
		if (classname == "Inheritor3")
		{
			printf("true\n");
			return true;
		}
		return Base::isA(classname);
	}
	void OK3()
	{
		printf("void OK3() - Inheritor3");
	}
};

int main()
{
	//безопасное приведение типов и предварительная проверка типа с помощью реализованного метода isA

	Base* base[4] = { new Base(), new Inheritor1(), new Inheritor2(), new Inheritor3() }; printf("\n");

	for (int i = 0; i < 4; i++)
	{
		if (base[i]->classname() == "Inheritor1")
		{
			((Inheritor1*)base[i])->OK1();
			printf("\n");
		}

		if (base[i]->isA("Inheritor2"))
		{
			((Inheritor2*)base[i])->OK2();
			printf("\n");
		}	

		if (dynamic_cast<Inheritor3*>(base[i]) != nullptr)
		{
			dynamic_cast<Inheritor3*>(base[i])->OK3();
			printf("\n");
		}

		printf("\n");
	}

	printf("\n\n");
	for (int i = 0; i < 4; i++)
	{
		delete base[i];
	}

	return 0;
}


