#include "Data.hpp"

Data::Data()
    : id(0), name("None")
{
}

Data::Data(int id, const std::string& name)
    : id(id), name(name)
{
}

Data::Data(const Data& src)
    : id(src.id), name(src.name)
{
}

Data&   Data::operator=(const Data& rhs)
{
    if (this != &rhs)
    {
        id = rhs.id;
        name = rhs.id;
    }
    return *this;
}

Data::~Data()
{
}
