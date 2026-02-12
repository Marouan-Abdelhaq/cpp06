#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data type;
    type.num = 42;
    Data *ptr = &type;
    uintptr_t val = Serializer::serialize(ptr);
    Data *ptr1 = Serializer::deserialize(val);
    std::cout << &type << std::endl;
    std::cout << val << std::endl;
    std::cout << ptr1 << std::endl;
    std::cout << ptr1->num << std::endl;
    
}