#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <deque>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <cctype>

int convertInt(const std::string& token)
{
    int value;
    std::stringstream str(token);
    str >> value;
    return value;
}

bool check(const std::string& token)
{
    if (token.empty() || token.size() > 10)
        return false;
    size_t  i = 0;
    if (i < token.length() && token[i] == '+')
        i++;
    while (i < token.length())
    {
        if (!std::isdigit(token[i]))
            return false;
        i++;
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> vec;
    std::deque<int> deq;
    int i = 1;
    while (i < ac)
    {
        if (!check(av[i]))
        {
            std::cerr << "Error: parsing" << std::endl;
            return 1;
        }
        int value = convertInt(av[i]);
        vec.push_back(value);
        deq.push_back(value);
        i++;
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << ' ';
    std::cout << std::endl;
    mergeByVector(vec);
    mergeByDeque(deq);
    return 0;
}