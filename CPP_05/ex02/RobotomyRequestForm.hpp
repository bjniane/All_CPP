#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        ~RobotomyRequestForm();

        void    execute(Bureaucrat const & executor) const;
};

#endif