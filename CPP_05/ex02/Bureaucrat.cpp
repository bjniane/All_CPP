#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

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

void    Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}