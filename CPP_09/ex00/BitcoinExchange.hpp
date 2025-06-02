#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

void    BitcoinExchange(const std::string& filename);
bool isLeapYear(int year);
std::string Trim(std::string& s);
bool isDigit(const std::string& s);
int convertInt(std::string& s);
bool validDate(std::string s);
bool isFloat(const std::string& s);
float convertFloat(const std::string& s);
float validValue(std::string& s);
std::map<std::string, float> dataBit(const std::string& data);
int main(int ac, char **av);

#endif