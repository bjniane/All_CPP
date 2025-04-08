#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*   slots[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& src);
        MateriaSource&  operator=(const MateriaSource& rhs);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif