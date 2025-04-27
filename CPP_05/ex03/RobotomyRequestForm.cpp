#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("None", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw GradeTooLowException();
    if (executor.getGrade() > getExecute())
        throw GradeTooLowException();
    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << getName() << " has been robotomized successfully 50% of the time." << std::endl;
    else
        std::cout << "Robotomy failed on " << getName() << std::endl;
}