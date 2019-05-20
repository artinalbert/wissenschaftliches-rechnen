//
// Created by chris on 5/20/19.
//
#include <iostream>
#include <string>
#include <exception>

//class Foo throws in the destructor
class Foo {
public:
    ~Foo() {
        throw my_exception("Foo exception");
    }
};


// class Bar throws in the constructor
class Bar {
public:
    Bar() {
        throw my_exception("Bar exception");
    }
};

int main()
try {
    Foo f;
    Bar b;
}
catch (const std::exception &e) {
    std::cout << "ERROR:" << e.what() << std::endl;
}
