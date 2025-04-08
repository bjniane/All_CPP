#include "Cure.h"
#include "AMateria.h"
#include "ICharacter.h"

Cure::Cure()
    : AMateria()
{
    type = "cure";
}

Cure::Cure(std::string const & type)
    : AMateria(type)
{
    AMateria::type = "cure";
}

Cure::Cure(const Cure& src)
    : AMateria(src)
{
}

Cure&   Cure::operator=(const Cure& rhs)
{
    if (this != &rhs)
        AMateria::operator=(rhs);
    return *this;
}

Cure::~Cure()
{
}

AMateria*   Cure::clone() const
{
    return (new Cure());
}

void   Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
