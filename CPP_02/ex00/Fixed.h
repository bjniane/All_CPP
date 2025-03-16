#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed 
{
    private:
        int integer;
        static const int    fractional = 8;
    public:
        Fixed();
        Fixed(const Fixed& source);
        Fixed&  operator=(const Fixed& rhs);
        ~Fixed();

        int getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif