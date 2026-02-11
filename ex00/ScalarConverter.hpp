#include <iostream>
#include <cstdlib>
#include <limits>
#include <errno.h>
#include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& obj);
    ScalarConverter& operator= (const ScalarConverter& obj);
    ~ScalarConverter();
    
public:
    static void convert(const std::string& string);
};

