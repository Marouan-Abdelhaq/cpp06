#include <iostream>
#include <cstdlib>
#include <limits>
#include <errno.h>
#include <iomanip>

class ScalarConverter
{
private:
    /* data */
public:
    ScalarConverter();
    ~ScalarConverter();

    static void convert(const std::string& string);
};

bool isDouble(const std::string& string)
{
    if (string == "nan" || string == "+inf" || string == "-inf")
        return true;
    if (string.find('.') == std::string::npos)
        return false;
    int j = 0;
    for (size_t i = 0; i < string.length(); i++)
    {
        if (string[i] == '.')
        {
            if (j++ > 0)
                return false;
        }
        else if (!std::isdigit(string[i]) && !(i == 0 && (string[i] == '+' || string[i] == '-')))
            return false;
    }
    return true;
}

bool isFloat(const std::string& string)
{
    if (string == "nanf" || string == "+inff" || string == "-inff")
        return true;
    if (string.find('.') == std::string::npos || string.back() != 'f')
        return false;
    int j = 0;
    for (size_t i = 0; i < string.length() - 1; i++)
    {
        if (string[i] == '.')
        {
            if (j++ > 0)
                return false;
        }
        else if (!std::isdigit(string[i]) && !(i == 0 && (string[i] == '+' || string[i] == '-')))
            return false;
        else if (string[i] == 'f' && i != string.length() - 1)
            return false;
    }
    return true;
}

bool isInt(const std::string& string)
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

void ScalarConverter::convert(const std::string& string)
{
    if (string.length() == 1 && !std::isdigit(string[0]) && std::isprint(string[0]))
    {
        std::cout << "char : " << string << std::endl;
        std::cout << "int : " << static_cast<int>(string[0]) << std::endl;
        std::cout << "float : " << static_cast<float>(string[0]) << std::endl;
        std::cout << "double : " << static_cast<double>(string[0]) << std::endl;
        return;
    }
    else if (isInt(string))
    {
        int val = std::atoi(string.c_str());
        if (std::isprint(val))
            std::cout << "char : " << static_cast<char>(val) << std::endl;
        else if (val >= 0 && val <= 127)
            std::cout << "char : " << "Non displayable" << std::endl;
        else
            std::cout << "char : " << "impossible" << std::endl;
        std::cout << "int : " << val << std::endl;
        std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(val) << std::endl;
    }
    else if (isFloat(string))
    {
        float val = std::atof(string.c_str());
        if (std::isprint(static_cast<int>(val)))
            std::cout << "char : " << static_cast<char>(val) << std::endl;
        else if (val >= 0 && val <= 127)
            std::cout << "char : " << "Non displayable" << std::endl;
        else
            std::cout << "char : " << "impossible" << std::endl;
        if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min() || std::isnan(val) || std::isinf(val))
            std::cout << "int : " << "impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(val) << std::endl;
        std::cout << "float : " << std::fixed << std::setprecision(1) << val << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(val) << std::endl;
    }
    else if (isDouble(string))
    {
        double val = std::atof(string.c_str());
        if (std::isprint(static_cast<int>(val)))
            std::cout << "char : " << static_cast<char>(val) << std::endl;
        else if (val >= 0 && val <= 127)
            std::cout << "char : " << "Non displayable" << std::endl;
        else
            std::cout << "char : " << "impossible" << std::endl;
        if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min() || std::isnan(val) || std::isinf(val))
            std::cout << "int : " << "impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(val) << std::endl;
        if (val > std::numeric_limits<float>::max() || val < -std::numeric_limits<float>::max())
            std::cout << "float : " << "impossible" << std::endl;
        else
            std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double : " << val << std::endl;
    }
    else
    {
        throw(std::invalid_argument("Invalid input"));
    }
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}
