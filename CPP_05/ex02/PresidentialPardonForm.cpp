#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("None", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
    : AForm(src)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw GradeTooLowException();
    if (executor.getGrade() > getExecute())
        throw GradeTooLowException();
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}