#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>
#include <ios>
#include <limits>
#include <sstream>
#include <string>

ScalarConverte::ScalarConverte()
{
}

ScalarConverte::ScalarConverte(const ScalarConverte& src)
{
    (void)src;
}

ScalarConverte& ScalarConverte::operator=(const ScalarConverte& rhs)
{
    (void)rhs;
    return *this;
}

ScalarConverte::~ScalarConverte()
{
}

bool ScalarConverte::isInt(const std::string& str)
{
    if (str.empty())
        return false;
    int start = 0;
    if (str[0] == '+' || str[0] == '-')
        start++;
    for (std::string::size_type i = start; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverte::isFloat(const std::string& str)
{
    int start = 0;
    bool point = false;

    if (str.empty())
        return false;
    if (str[0] == '+' || str[0] == '-')
        start++;
    for (std::string::size_type i = start; i < str.length(); i++)
    {
        if (str == "+inff" || str == "-inff" || str == "nanf")
            return true;
        if (isdigit(str[i]))
            continue;
        else if (str[0] != '.' && str[i] == '.' && !point)
            point = true;
        if (point && str[str.length() - 1] == 'f' && isdigit(str[str.length() - 2]))
            return true;
        else
            return false;
    }
    return true;
}

bool ScalarConverte::isDouble(const std::string& str)
{
    int start = 0;
    bool point = false;
    
    if (str.empty())
        return false;
    for (std::string::size_type i = start; i < str.length(); i++)
    {
        if (str == "+inf" || str == "-inf" || str == "nan")
            return true;
        if (isdigit(str[i]))
            continue;
        else if (str[0] != '.' && str[i] == '.' && !point)
            point = true;
        else
            return false;
    }
    return true;
}

void ScalarConverte::convertChar(const std::string& str)
{
    char c = str[0];
    int i = c;
    float f = c;
    double d = c;

    std::cout << "Char: '" << c << "'" << std::endl;
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
        std::cout << "int: " << "Non displayable" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverte::convertInt(const std::string& str)
{
    std::stringstream s(str);
    long long i = 0;
    s >> i;
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: Non displayable" << std::endl;
    else
    {
        char c = static_cast<char>(i);
        if (!std::isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "Char: '" << c << "'" << std::endl;
    }
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
        std::cout << "int: Non displayable" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverte::convertFloat(const std::string& str)
{
    if (str == "+inff" || str == "-inff" || str == "nanf")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::string& s = const_cast<std::string&>(str);
        s.erase(s.size() - 1);
        std::cout << "double: " << s << std::endl;
        return;
    }
    std::stringstream s(str);
    float f = 0.0;
    s >> f;

    double d = static_cast<double>(f);
    
    if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
        std::cout << "char: Non displayable" << std::endl;
    else
    {
        char c = static_cast<char>(f);
        if (!std::isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "Char: '" << c << "'" << std::endl;
    }
    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "int: Non displayable" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverte::convertDouble(const std::string& str)
{
    if (str == "+inf" || str == "-inf" || str == "nan")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return;
    }
    std::stringstream   s(str);
    double  d = 0.0;
    s >> d;

    float f = static_cast<float>(d);

    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "char: Non displayable" << std::endl;
    else
    {
        char c = static_cast<char>(d);
        if (!std::isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "Char: '" << c << "'" << std::endl;
    }
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: Non displayable" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverte::convert(const std::string& literal)
{
    if (literal.length() == 1 && std::isprint(literal[0]))
        convertChar(literal);
    else if (isInt(literal))
        convertInt(literal);
    else if (isFloat(literal))
        convertFloat(literal);
    else if (isDouble(literal))
        convertDouble(literal);
    else
        std::cout << "UNKNOWN!" << std::endl;
}
