#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

Form::Form()
    : name("None"), isSigned(false), signGrade(1), execGrade(1)
{
}

Form::Form(const std::string& name, int sign, int exec)
    : name(name), isSigned(false), signGrade(sign), execGrade(exec)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& src)
    : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), execGrade(src.execGrade)
{
}

Form&   Form::operator=(const Form& rhs)
{
    if (this != &rhs)
        isSigned = rhs.isSigned;
    return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
    return name;
}

bool    Form::getIsSigned() const
{
    return isSigned;
}

int Form::getSign() const
{
    return signGrade;
}

int Form::getExecute() const
{
    return execGrade;
}

void    Form::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() >= signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream&   operator<<(std::ostream& out, const Form& form)
{
    out << "Form: " << form.getName() << " [signGrade: " << form.getSign() << ", execGrade: " << form.getExecute() << ", signed: " << form.getIsSigned() << "]";
    return out;
}