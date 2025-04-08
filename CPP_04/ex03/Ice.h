#ifndef ICE_H
#define ICE_H

#include "AMateria.h"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(std::string const & type);
        Ice(const Ice& src);
        Ice&    operator=(const Ice& rhs);
        ~Ice();

        AMateria*   clone() const;
        void    use(ICharacter& target);
};

#endif