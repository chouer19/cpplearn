#include <iostream>
#include <memory>
#include <map>
#include <unordered_map>

struct C1{

    void test(){
        std::cout << "C1 test ......\n";
    }

    ~C1(){
        std::cout << "C1 deconstructor!\n";
    };
};

int main(int argc, char* argv[]){
    std::map<std::string, std::shared_ptr<C1>> contents;

    {
        contents.emplace("aaa",std::make_shared<C1>());
    }
    contents.erase("aaa");
    contents.emplace("bbb",std::make_shared<C1>());
    contents["bbb"]->test();

    return 0;
}
