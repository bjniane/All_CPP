#ifndef CURE_H
#define CURE_H

#include "AMateria.h"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string const & type);
        Cure(const Cure& src);
        Cure&   operator=(const Cure& rhs);
        ~Cure();

        AMateria*   clone() const;
        void    use(ICharacter& target);
};

#endif