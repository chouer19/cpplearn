#include <iostream>
using namespace std;

[[noreturn]] void test(){
    int b=6;
    cout << "b is " << b << endl;
    return ;
    int a=3;
    cout << "a is " << a << endl;
}

int main(){
    test();
    return 1;
}
