#include "file.h"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        redirectFile(filename, s1, s2);
    }
    else
        std::cout << "you must enter in prompt like this: ./exec filename s1 s2" << std::endl;
}