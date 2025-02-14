#include "file.h"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        // std::string filename;
        // std::string s1;
        // std::string s2;

        // filename = av[1];
        // s1 = av[2];
        // s2 = av[3];

        redirectFile(av[1], av[2], av[3]);
    }
    else
        std::cout << "There is three options to enter(filename, string1, string2)." << std::endl;
}