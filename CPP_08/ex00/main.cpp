#include "easyfind.hpp"
#include <exception>
#include <vector>

int main()
{
    std::vector<int> arr;
    arr.push_back(3);
    arr.push_back(42);
    arr.push_back(54);
    arr.push_back(2);
    arr.push_back(30);
    arr.push_back(98);
    try
    {
        std::vector<int>::iterator i = easyfind(arr, 3);
        std::cout << "Found: " << *i << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}