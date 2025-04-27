#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
    (void)src;
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return *this;
}

Intern::~Intern()
{
}

AForm*  Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::createPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::makeForm(const std::string& name, const std::string& target)
{
    AForm* (Intern::*functPtr[])(const std::string&) = {&Intern::createShrubbery, &Intern::createPardon, &Intern::createRobotomy};
    std::string names[] = {"shrubbery creation", "president pardon", "robotomy request"};
    for (int i = 0; i < 3; i++)
    {
        if (names[i] == name)
        {
            std::cout << "Intern creates " << target << std::endl;
            return (this->*functPtr[i])(target);
        }
    }
    std::cout << "The name of the form you passed does not exist." << std::endl;
    return NULL;
}