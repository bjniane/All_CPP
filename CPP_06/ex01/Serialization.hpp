#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serialization
{
    public:
        Serialization();
        Serialization(const Serialization& src);
        Serialization&  operator=(const Serialization& rhs);
        ~Serialization();

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif