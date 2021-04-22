#include <iostream>
#include <functional>
#include <memory>

struct DataVisitorBase{};

template <typename T>
struct DataVisitor : public DataVisitorBase{
    DataVisitor(T v):value(v)
    {}
    void Set(T v){
        value = v;
    }
    T Get(){
        return value;
    }
    T value;
};

struct RoutineFactory{
    using VoidFunc= std::function<void()>;
    using CreateRoutineFunc = std::function<VoidFunc()>;
    CreateRoutineFunc create_routine_;
    std::shared_ptr<DataVisitorBase> data_visitor_ = nullptr;
};

template <typename T, typename F>
RoutineFactory CreateRoutineFactory(F&& f, const std::shared_ptr<DataVisitor<T>>& dv){
    RoutineFactory factory;
    factory.data_visitor_ = dv;

    RoutineFactory::VoidFunc voidfunc = [=](){
        // if true
            f(dv->Get());
        // else
        // wait
    };

    factory.create_routine_ = [=](){
        return voidfunc;
    };

    factory.create_routine_ = [=](){
        return [=](){
            // if true
                f(dv->Get());
            // else
            // wait
        };
    };
    return factory;
}

bool CreateTask(std::function<void()>&& func, std::shared_ptr<DataVisitorBase> visitor){
    func();
}

bool CreateTask(const RoutineFactory& factory){
    CreateTask(factory.create_routine_(), factory.data_visitor_);
}

int main(){
    
    auto func = [=](int value){
        std::cout << "aaa: " << value << "\n" ;
    };

    auto dv = std::make_shared<DataVisitor<int>>(6);
    //auto factory = CreateRoutineFactory(func, dv);
    auto factory = CreateRoutineFactory<int>(func, dv);
    //factory.create_routine_();
    CreateTask(factory);
    dv->Set(8);
    CreateTask(factory);
    factory.create_routine_()();
    return 1;
}
