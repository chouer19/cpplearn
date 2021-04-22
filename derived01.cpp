
#include<iostream>
using namespace std;
 
class A
{
public:
	virtual void foo()
	//void foo()
	{
		printf("A::foo()\n");
	}
	virtual void fun()
	{
		printf("A::fun()\n");
	}
};
class B : public A
{
public:
	void foo()
	{
		printf("B::foo()\n");
	}
	void fun()
	{
		printf("B::fun()\n");
	}
};
int main(void)
{
	A a;
	B b;
	A *p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	return 0;
}
