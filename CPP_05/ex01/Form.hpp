#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        Form();
        Form(const std::string& name, int sign, int exec);
        Form(const Form& src);
        Form&   operator=(const Form& rhs);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        const std::string& getName() const;
        bool    getIsSigned() const;
        int getSign() const;
        int getExecute() const;

        void    beSigned(const Bureaucrat& obj);
};

std::ostream&   operator<<(std::ostream& out, const Form& form);

#endif