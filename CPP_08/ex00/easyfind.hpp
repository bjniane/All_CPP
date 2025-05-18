#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator found = std::find(container.begin(), container.end(), value);
    if (found == container.end())
        throw std::runtime_error("Value not found!");
    return found;
}

#endif