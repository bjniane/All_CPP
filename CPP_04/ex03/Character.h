#ifndef CHARACTER_H
#define CHARACTER_H

#include "AMateria.h"
#include "ICharacter.h"

struct  MateriaNode
{
    AMateria*   materia;
    MateriaNode*    next;
};

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria*   slots[4];
        MateriaNode*    node;
    public:
        Character();
        Character(std::string name);
        Character(const Character& src);
        Character&  operator=(const Character& rhs);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif