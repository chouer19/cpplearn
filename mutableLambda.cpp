#include <iostream>
using namespace std;

void test(){

}

int main(){
    int count = 10;
    auto ff = [count]()mutable->int {return --count;};
    //auto ff = [count](){return --count;};
    cout << ff() << endl;
    cout << ff() << endl;
    cout << ff() << endl;
    cout << ff() << endl;
    cout << ff() << endl;
    return 1;
}
