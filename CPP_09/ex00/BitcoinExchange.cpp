#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <utility>

std::map<std::string, float> dataBit(const std::string& data)
{
    std::map<std::string, float> map;
    std::ifstream   inputData(data.c_str());
    if (!inputData.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return map;
    }
    std::string line;
    std::getline(inputData, line);
    while (std::getline(inputData, line))
    {
        std::stringstream s(line);
        std::string date;
        std::string value;
        if (!std::getline(s, date, ',') || !std::getline(s, value, ','))
        {
            std::cerr << "Error: bad input ==> " << line << std::endl;
            continue;
        }
        date = Trim(date);
        value = Trim(value);
        float price = convertFloat(value);
        map.insert(std::make_pair(date, price));
    }
    return map;
}

float   getClosestDate(std::map<std::string, float>&dataBase, const std::string& date)
{
    std::map<std::string, float>::iterator it = dataBase.lower_bound(date);
    if (it == dataBase.begin() && it->first != date)
        return it->second;
    if (it == dataBase.end() || it->first != date)
        --it;
    return it->second;
}

void    BitcoinExchange(const std::string& filename)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    std::string line;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {
        std::stringstream s(line);
        std::string date;
        std::string value;
        if (!std::getline(s, date, '|') || !std::getline(s, value, '|'))
        {
            std::cout << "Error: bad input ==> " << line << std::endl;
            continue;
        }
        date = Trim(date);
        value = Trim(value);
        if (date.empty() || value.empty() || !validDate(date) || !isFloat(value))
        {
            std::cerr << "Error: bad input ==> " << line << std::endl;
            continue;
        }
        if (validValue(value) == -1)
            continue;
        float floatValue = validValue(value);
        std::map<std::string, float> dataBase = dataBit("data.csv");
        float   price = getClosestDate(dataBase, date);
        std::cout << date << " => " <<floatValue << " = " << floatValue * price << std::endl;
    }
    inputFile.close();
}