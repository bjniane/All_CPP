#include "Character.h"
#include "AMateria.h"
#include <cstddef>
#include <optional>

Character::Character()
    : name("None"), node(NULL)
{
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
    }
}

Character::Character(std::string name)
    : name(name), node(NULL)
{
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
    }
}

Character::Character(const Character& src)
    : name(src.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (src.slots[i] != NULL)
            slots[i] = src.slots[i]->clone();
        else
            slots[i] = NULL;
    }
}

Character&  Character::operator=(const Character& rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
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

int isDeleted(MateriaNode *head)
{
    MateriaNode* node = head->next;
    while (node)
    {
        if (node->materia == head->materia)
            return 0;
        node = node->next;
    }
    return 1;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (slots[i])
        {
            MateriaNode* newNode = new MateriaNode();
            newNode->materia = slots[i];
            newNode->next = node;
            node = newNode;
        }
    }
    while (node)
    {
        MateriaNode* next = node->next;
        if (isDeleted(node))
            delete node->materia;
        delete node;
        node = next;
    }
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] == NULL)
        {
            slots[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && slots[idx] != NULL)
    {
        MateriaNode* newNode = new MateriaNode();
        newNode->materia = slots[idx];
        newNode->next = node;
        node = newNode;
        slots[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && slots[idx] != NULL)
        slots[idx]->use(target);
}