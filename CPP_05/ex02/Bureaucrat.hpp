#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        ~Bureaucrat();

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
        int getGrade() const;
        void    increment();
        void    decrement();

        void    signForm(AForm& form);
        void    executeForm(AForm const & form);
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& obj);

#endif