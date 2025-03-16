#include "Fixed.h"

Fixed::Fixed()
    : integer(0)
{
}

Fixed::Fixed(const int a)
{
    integer = a * (1 << fractional);
}

Fixed::Fixed(const float a)
{
    integer = (int)roundf(a * (1 << fractional));
}

Fixed::Fixed(const Fixed& source)
    : integer(source.integer)
{
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this == &rhs)
        return *this;
    this->integer = rhs.integer;
    return *this;
}

int Fixed::getRawBits(void) const
{
    return integer;
}

void    Fixed::setRawBits(int const raw)
{
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

//OVERLOADED COMPARISON OPERATORS
bool    Fixed::operator==(const Fixed& rhs)
{
    if (integer == rhs.integer)
        return true;
    return false;
}

bool    Fixed::operator!=(const Fixed& rhs)
{
    if (integer == rhs.integer)
        return false;
    return true;
}

bool    Fixed::operator>(const Fixed& rhs)
{
    if (integer > rhs.integer)
        return true;
    return false;
}

bool    Fixed::operator<(const Fixed& rhs)
{
    if (integer < rhs.integer)
        return true;
    return false;
}

bool    Fixed::operator>=(const Fixed& rhs)
{
    if (integer >= rhs.integer)
        return true;
    return false;
}

bool    Fixed::operator<=(const Fixed& rhs)
{
    if (integer <= rhs.integer)
        return true;
    return false;
}

//4 ARITHMETIC OPERATORS:
Fixed   Fixed::operator+(const Fixed& rhs) const
{
    Fixed   result;
    result.setRawBits(this->getRawBits() + rhs.getRawBits());
    return result;
}

Fixed   Fixed::operator-(const Fixed& rhs) const
{
    Fixed   result;
    result.setRawBits(this->getRawBits() - rhs.getRawBits());
    return result;
}

Fixed   Fixed::operator*(const Fixed& rhs) const
{
    Fixed   result;
    result.setRawBits((this->getRawBits() * rhs.getRawBits()) / (1 << fractional));
    return result;
}

Fixed   Fixed::operator/(const Fixed& rhs) const
{
    Fixed   result;
    result.setRawBits((this->getRawBits() * (1 << fractional)) / rhs.getRawBits());
    return result;
}

//4 INCREMENT/DECREMENT OPERATORS:
Fixed&  Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}
Fixed&  Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return temp;
}
Fixed   Fixed::operator--(int)
{
    Fixed   temp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return temp;
}

//4 MIN/MAX OVERLOADED FUNCTIONS
Fixed&   Fixed::min(Fixed& num1, Fixed& num2)
{
    if (num1.getRawBits() < num2.getRawBits())
        return num1;
    return num2;
}

const Fixed&   Fixed::min(Fixed const& num1, Fixed const& num2)
{
    if (num1.getRawBits() < num2.getRawBits())
        return num1;
    return num2;
}

Fixed&   Fixed::max(Fixed& num1, Fixed& num2)
{
    if (num1.getRawBits() > num2.getRawBits())
        return num1;
    return num2;
}

const Fixed&   Fixed::max(Fixed const& num1, Fixed const& num2)
{
    if (num1.getRawBits() > num2.getRawBits())
        return num1;
    return num2;
}