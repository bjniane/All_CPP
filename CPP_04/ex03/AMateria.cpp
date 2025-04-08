#include "AMateria.h"
#include "ICharacter.h"

AMateria::AMateria()
    : type("None")
{
}

AMateria::AMateria(std::string const & type)
    : type(type)
{
}

AMateria::AMateria(const AMateria& src)
    : type(src.type)
{
}

AMateria&   AMateria::operator=(const AMateria& rhs)
{
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << target.getName() << std::endl;
}
