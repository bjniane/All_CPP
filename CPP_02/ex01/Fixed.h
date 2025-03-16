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
};

std::ostream&   operator<<(std::ostream& os, const Fixed& obj);

#endif