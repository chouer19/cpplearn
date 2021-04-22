#include <iostream>
#include <vector>
using namespace std;
int main(){
    //int a[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> a{0,1,2,3,4,5,6,7,8,9};
    cout << a.operator[](3) << endl;
    cout << 3[]a << endl;
    return 0;
}
