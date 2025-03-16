#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed 
{
    private:
        int integer;
        static const int    fractional = 8;
    public:
        Fixed();
        Fixed(const int a);
        Fixed(const float a);
        Fixed(const Fixed& source);
        Fixed&  operator=(const Fixed& rhs);
        ~Fixed();

        int getRawBits(void) const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;

        //6 OVERLOADED COMPARISON OPERATORS:
        bool    operator==(const Fixed& rhs);
        bool    operator!=(const Fixed& rhs);
        bool    operator>(const Fixed& rhs);
        bool    operator<(const Fixed& rhs);
        bool    operator>=(const Fixed& rhs);
        bool    operator<=(const Fixed& rhs);

        //4 ARITHMETIC OPERATORS:
        Fixed   operator+(const Fixed& rhs) const;
        Fixed   operator-(const Fixed& rhs) const;
        Fixed   operator*(const Fixed& rhs) const;
        Fixed   operator/(const Fixed& rhs) const;

        //4 INCREMENT/DECREMENT OPERATORS:
        Fixed&  operator++();
        Fixed&  operator--();
        Fixed   operator++(int);
        Fixed   operator--(int);

        //4 MIN/MAX OVERLOADED FUNCTIONS
        static Fixed&   min(Fixed& num1, Fixed& num2);
        static const Fixed&   min(Fixed const& num1, Fixed const& num2);
        static Fixed&   max(Fixed& num1, Fixed& num2);
        static const Fixed&   max(Fixed const& num1, Fixed const& num2);
};

std::ostream&   operator<<(std::ostream& os, const Fixed& obj);

#endif