#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low";
}

Bureaucrat::Bureaucrat()
    : name("None"), grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name(src.name), grade(src.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
        grade = rhs.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void    Bureaucrat::increment()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void    Bureaucrat::decrement()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}