#include <iostream>
#include <cstdlib>

int main()
{
    float a = 5.0f;
    int c;

    c = static_cast<int>(a);
    std::cout << std::fixed << a<< std::endl;
}