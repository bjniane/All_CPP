#include "BitcoinExchange.hpp"

bool isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return false;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

std::string Trim(std::string& s)
{
    if (s.empty())
        return "";
    size_t  start = s.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return s.substr(start, end - start + 1);
}
bool isDigit(const std::string& s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

int convertInt(std::string& s)
{
    std::stringstream str(s);
    int value;
    str >> value;
    return value;
}

bool validDate(std::string s)
{
    if (s.size() != 10 || s[4] != '-' || s[7] != '-')
        return false;
    std::string yearStr = s.substr(0, 4);
    std::string monthStr = s.substr(5, 2);
    std::string dayStr = s.substr(8, 2);
    if (!isDigit(yearStr) || !isDigit(monthStr) || !isDigit(dayStr))
        return false;
    int year = convertInt(yearStr);
    int month = convertInt(monthStr);
    int day = convertInt(dayStr);
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31)
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    else if (month == 2)
    {
        if (isLeapYear(year))
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    return true;
}

bool isFloat(const std::string& s)
{
    bool point = false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if ((s[0] == '-' || s[0] == '+') && (s[1] && s[1] != '.'))
            continue;
        if (std::isdigit(s[i]))
            continue;
        else if (s[0] != '.' && s[i] == '.' && !point)
            point = true;
        else if (s[i] == '.' && !s[i + 1])
            return false;
        else
            return false;
    }
    return true;
}

float convertFloat(const std::string& s)
{
    std::stringstream str(s);
    float   value = 0.0;
    str >> value;
    return value;
}

float validValue(std::string& s)
{
    float value = convertFloat(s);
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return -1;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return -1;
    }
    return value;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    BitcoinExchange(av[1]);
    return 0;
}