#include <iostream>
#include <cstdlib>
#include <limits>
#include <errno.h>

class ScalarConverter
{
private:
    /* data */
public:
    ScalarConverter();
    ~ScalarConverter();

    static void convert(const std::string& string);
};

bool isFloat(const std::string& string)
{

}

bool isInt(const std::string& string)
{
    if (string.length() == 1 && std::isdigit(string[0]))
    {
        char* ptr;
        errno = 0;
        long val = std::strtol(string.c_str(), &ptr, 10);
        if (*ptr != '\0')
            return false;
        if (errno == ERANGE || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
            return false;
        return true;
    }
    return false
}

void ScalarConverter::convert(const std::string& string)
{
    try
    {
        try
        {
            if (string.length() == 1 && !std::isdigit(string[0]) && std::isprint(string[0]))
            {
                std::cout << "char : " << string << std::endl;
                std::cout << "int : " << static_cast<int>(string[0]) << std::endl;
                std::cout << "float : " << static_cast<float>(string[0]) << std::endl;
                std::cout << "double : " << static_cast<double>(string[0]) << std::endl;
                return;
            }
            if (isInt(string))
            {
                std::cout << "char : " << "Non displayable" << std::endl;
                std::cout << "int : " << static_cast<int>(string[0]) << std::endl;
                std::cout << "float : " << static_cast<float>(string[0]) << std::endl;
                std::cout << "double : " << static_cast<double>(string[0]) << std::endl;
            }
        }
        catch(...)
        {
            if ()
            
        }
        
    }
    catch(...)
    {
        std::cout << "Invalid input" << std::endl;
    }
    
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}
