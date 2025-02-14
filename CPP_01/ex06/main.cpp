#include "Harl.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Enter one of these options (debug, info, warning and error). " << std::endl;
        return (1);
    }
    Harl    h;
    h.complain(av[1]);
}