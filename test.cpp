#include <iostream>
#include <cstdlib>

#include <iostream>

class A {
    public:
    virtual ~A() {}
};

class B : public A {
    public:

    void print() {
        std::cout << "B" << std::endl;
    }
    void name(){
        std::cout << "s";
    }
};

class C : public A {
    public:
    
    void name()
    {
        std::cout << "hhhhhhhhhhhh" << std::endl;
    }
    void print() {
        std::cout << "C" << std::endl;
    }
};


int main() {
    // A* a = new B;

    C* c;
    std::cout << c << std::endl;
    c->print();
    c->name();
    // delete a;    
}
