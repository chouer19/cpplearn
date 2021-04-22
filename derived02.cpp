#include<iostream>
using namespace std;
 
class A
{
public:
	void foo()
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
	//void fun()
	void fun() override
	{
		printf("B::fun()\n");
	}
};
int main(void)
{
	A a;
	B *pb = (B*)&a;
	pb->foo();
	pb->fun();
	return 0;
}
