#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Invalid format" << std::endl;
    else
        ScalarConverte::convert(av[1]);
    return 0;
}