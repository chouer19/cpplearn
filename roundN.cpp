#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

template <int N>
//template <typename N>
double roundN(double input){
    return double{round(input * pow(10,N))}/pow(10,N);
}

struct AnyType{
    //friend bool operator==(const AnyType&, const AnyType&) = default;
};
//class AnyType{
////struct AnyType{
//    //using value_type = int;
//};
//template <typename T=AnyType>
enum NoType{};
//using AnyType = int;
//using AnyType = NoType;
template <AnyType &T>
//template <int T=0>
void anyFunc(){
    //using content= T;
    //T t{};
}

void test(){
    //AnyType t;
    //anyFunc<t>();
}

int main(){
    double test = 1.223445453;
    cout << roundN<3>(test) << endl;
    cout << roundN<3>(test) << endl;
    int tmp = 12;
    int tmp2 = 1000;
    double tmp3 = tmp / tmp2;
    cout << "tmp3 is : " << tmp3 << endl;
    return 1;
}
