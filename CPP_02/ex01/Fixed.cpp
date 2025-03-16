#include "Fixed.h"

Fixed::Fixed()
    : integer(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int a)
{
    std::cout << "Int constructor called" << std::endl;
    integer = a * (1 << fractional);
}

Fixed::Fixed(const float a)
{
    std::cout << "Float constructor called" << std::endl;
    integer = (int)roundf(a * (1 << fractional));
}

Fixed::Fixed(const Fixed& source)
    : integer(source.integer)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &rhs)
        return *this;
    this->integer = rhs.integer;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return integer;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    integer = raw;
}

int     Fixed::toInt(void) const
{
    return (integer / (1 << fractional));
}

float   Fixed::toFloat(void) const
{
    float   result;

    result = (float)integer / (1 << fractional);
    return result;
}

std::ostream&   operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}