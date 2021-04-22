
#include<iostream>
using namespace std;
 
class A
{
public:
	virtual void ff()
	{
		cout<<"A::ff()"<<endl;
	}
	void gg()
	{
		cout<<"A::gg()"<<endl;
	}
	void hh(int x)
	{
		cout<<"A::hh()"<<endl;
	}
};
class B :public A
{
public:
	virtual void ff()
	{
		cout<<"B::ff()"<<endl;
	}
	void gg()
	{
		cout<<"B::gg()"<<endl;
	}
	void hh(float x)
	{
		cout<<"B::hh()"<<endl;
	}
};
int main()
{
	B b;
	A* pa = &b;
	B* pb = &b;
	pa->ff(); //多态，即就是重写或者叫覆盖
	pb->ff();
	printf("------------\n");
	pa->gg();//非多态，是隐藏
	pb->gg();
	printf("------------\n");
	pa->hh(3); //非多态，是隐藏
	pb->A::hh(3);
	pb->hh(3);
	
	return 0;
}

