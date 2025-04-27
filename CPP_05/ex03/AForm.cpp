#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low";
}

AForm::AForm()
    : name("None"), isSigned(false), signGrade(1), execGrade(1)
{
}

AForm::AForm(const std::string& name, int sign, int exec)
    : name(name), isSigned(false), signGrade(sign), execGrade(exec)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
    : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), execGrade(src.execGrade)
{
}

AForm&   AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
        isSigned = rhs.isSigned;
    return *this;
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
    return name;
}

bool    AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getSign() const
{
    return signGrade;
}

int AForm::getExecute() const
{
    return execGrade;
}

void    AForm::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() >= signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream&   operator<<(std::ostream& out, const AForm& form)
{
    out << "AForm: " << form.getName() << " [signGrade: " << form.getSign() << ", execGrade: " << form.getExecute() << ", signed: " << form.getIsSigned() << "]";
    return out;
}