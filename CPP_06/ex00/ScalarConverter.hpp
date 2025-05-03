#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <string>

class ScalarConverte
{
    public:
        ScalarConverte();
        ScalarConverte(const ScalarConverte& src);
        ScalarConverte& operator=(const ScalarConverte& rhs);
        ~ScalarConverte();

        static bool isInt(const std::string& str);
        static bool isFloat(const std::string& str);
        static bool isDouble(const std::string& str);
        static void convertChar(const std::string& str);
        static void convertInt(const std::string& str);
        static void convertFloat(const std::string& str);
        static void convertDouble(const std::string& str);
        static void convert(const std::string& literal);
};

#endif