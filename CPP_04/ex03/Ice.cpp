#include "Ice.h"
#include "AMateria.h"
#include "ICharacter.h"

Ice::Ice()
    : AMateria()
{
    type = "ice";
}

Ice::Ice(std::string const & type)
    : AMateria(type)
{
    AMateria::type = "ice";
}

Ice::Ice(const Ice& src)
    : AMateria(src)
{
}

Ice&    Ice::operator=(const Ice& rhs)
{
    if (this != &rhs)
        AMateria::operator=(rhs);
    return *this;
}

Ice::~Ice()
{
}

AMateria*   Ice::clone() const
{
    return (new Ice());
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
