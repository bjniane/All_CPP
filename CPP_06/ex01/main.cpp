#include "Data.hpp"
#include "Serialization.hpp"

int main()
{
    Data    data(1, "Test");

    uintptr_t   serialize = Serialization::serialize(&data);
    Data*   deserialize = Serialization::deserialize(serialize);

    if (&data == deserialize)
    {
        std::cout << "Serialization and Deserialization are successful!" << std::endl;
        std::cout << "Data information: " << std::endl;
        std::cout << "Name: " << deserialize->name << std::endl;
        std::cout << "Id: " << deserialize->id << std::endl;
    }
    else
        std::cout << "Failed!" << std::endl;
    return 0;
}