#include <iostream>
using namespace std;

class X{
public:
    X(const int& value_a, const int& value_b)
    : a(value_a), b(value_b)
    {
    }

    void print(){
        cout << "My a is : " << a << endl;
        cout << "My b is : " << b << endl;
    }

private:
    int a;
    int b;
};

int main(){
    X a{1,2};
    X b{2,3};
    X c = X{3,4};
    //X::print(&a);
    a.print();
    return 0;
}
