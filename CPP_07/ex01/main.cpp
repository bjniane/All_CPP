#include "iter.hpp"
#include <string>

void print(int x)
{
    std::cout << x << " ";
}

void printChar(char x)
{
    std::cout << x << " ";
}

void printString(std::string x)
{
    std::cout << x << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    iter(arr, 6, print);
    std::cout << std::endl;
    char array[] = {'h', 'e', 'l', 'l', 'o'};
    iter(array, 5, printChar);
    std::cout << std::endl;
    std::string s[] = {"hello", "Test", "how", "are", "you"};
    iter(s, 5, printString);
}
