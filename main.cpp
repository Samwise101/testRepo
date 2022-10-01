#include <iostream>
#include <memory>

class MyClass{
public:
    //constructor
    MyClass() {
        std::cout << "Constructor invoked!" << '\n';
    }
    //destructor
    ~MyClass() {
        std::cout << "Destructor invoked!" << '\n';
    }
};

int main() {
    //unique pointer
    std::unique_ptr<MyClass> unPtr1 = std::make_unique<MyClass>();
    std::unique_ptr<MyClass> unPtr2 = std::move(unPtr1);

    //shared pointer
    std::shared_ptr<MyClass> shPtr1 = std::make_shared<MyClass>();
    std::cout << shPtr1.use_count() << '\n';

    {
        std::shared_ptr<MyClass>sharedPtr = shPtr1;
        std::cout << shPtr1.use_count() << '\n';
    }
    std::cout << shPtr1.use_count() << '\n';

    std::weak_ptr<int> weakPtr1;
    {
        std::shared_ptr<int> shPtr3 = std::make_shared<int>(5);
        weakPtr1 = shPtr3;
    }

    return 0;
}
