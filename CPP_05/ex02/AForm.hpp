#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        AForm();
        AForm(const std::string& name, int sign, int exec);
        AForm(const AForm& src);
        AForm&   operator=(const AForm& rhs);
        virtual ~AForm();

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
        virtual void    execute(Bureaucrat const & executor) const = 0;
};

std::ostream&   operator<<(std::ostream& out, const AForm& form);

#endif