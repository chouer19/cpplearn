#include <iostream>
#include <string>
#include <type_traits>

///#define DEFINE_TYPE_TRAIT(name, func)                     \
///  template <typename T>                                   \
///  struct name {                                           \
///    template <typename Class>                             \
///    static constexpr bool Test(decltype(&Class::func)*) { \
///      return true;                                        \
///    }                                                     \
///    template <typename>                                   \
///    static constexpr bool Test(...) {                     \
///      return false;                                       \
///    }                                                     \
///                                                          \
///    static constexpr bool value = Test<T>(nullptr);       \
///  };                                                      \
///                                                          \
///  template <typename T>                                   \
///  constexpr bool name<T>::value;

namespace message{
  template <typename T>                                   
  struct HasParseFromString{                                           
    template <typename Class>                             
    static constexpr bool Test(decltype(&Class::ParseFromString)*) { 
      //std::cout << "no function named ParseFromString in Class\n";
      return true;                                        
    }                                                     
    template <typename>                                   
    static constexpr bool Test(...) {                     
      //std::cout << "yes function named ParseFromString in Class\n";
      return false;                                       
    }                                                     
                                                          
    static constexpr bool value = Test<T>(nullptr);       
  };                                                      
                                                          
  template <typename T>                                   
  constexpr bool HasParseFromString<T>::value;
}


struct ChangeMsg{
    ///bool ParseFromString(const std::string& msg){
    ///    if(msg.find("xuechong") != std::string::npos){
    ///        return true;
    ///    }
    ///    return false;
    ///}

    void ParseFromString(){

    }
};

namespace message{

//DEFINE_TYPE_TRAIT(HasParseFromString, ParseFromString)

template <typename T>
typename std::enable_if<HasParseFromString<T>::value, bool>::type
ParseFromString(const std::string& str, T* message) {
  std::cout<< "cond is true!\n";
  //return message->ParseFromString(str);
  return true;
}


template <typename T>
typename std::enable_if<!HasParseFromString<T>::value, bool>::type
ParseFromString(const std::string& str, T* message) {
  std::cout<< "cond is not true!\n";
  return false;
}
}

int main(){
    ChangeMsg msg;
    bool parse_result = message::ParseFromString("dsafdsfqewr",&msg);
    ///if(parse_result){
    ///    std::cout << "ok, go on parsing!\n";
    ///}

    ///parse_result = message::ParseFromString("xuechongchongchong",&msg);
    ///if(parse_result){
    ///    std::cout << "ok, go on parsing!\n";
    ///}

    ///if(message::HasParseFromString<ChangeMsg>::value){
    ///    std::cout << "ChangeMsg's cond is true, the type ChangeMsg is enabled!\n";
    ///}

    return 1;
}
