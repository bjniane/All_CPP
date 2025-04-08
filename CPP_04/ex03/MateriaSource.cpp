#include "MateriaSource.h"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src.slots[i] != NULL)
            slots[i] = src.slots[i]->clone();
        else
            slots[i] = NULL;
    }
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (slots[i] != NULL)
            {
                delete slots[i];
                slots[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (rhs.slots[i] != NULL)
                slots[i] = rhs.slots[i]->clone();
            else
                slots[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] != NULL)
        {
            delete slots[i];
            slots[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* type)
{
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] == NULL)
        {
            slots[i] = type;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] != NULL && type == slots[i]->getType())
            return (slots[i]->clone());
    }
    return NULL;
}