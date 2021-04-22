// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>
#include <string>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

template <class T>
//typename std::enable_if<std::is_integral<T>::value>::type
//typename std::enable_if<std::is_floating_point<T>::value>::type
typename std::enable_if<true>::type
  call_cout (T i) {std::cout << i << std::endl;}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
           class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

int main() {

  short int i = 1;    // code does not compile if type of i is not integral

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;
  call_cout(float{1.1});
  call_cout(int{1});
  call_cout(std::string{"dsafdsaf"});

  return 0;
}
