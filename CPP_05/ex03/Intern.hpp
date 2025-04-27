#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

class Intern
{
    public:
        Intern();
        Intern(const Intern& src);
        Intern& operator=(const Intern& rhs);
        ~Intern();

        AForm*  makeForm(const std::string& name, const std::string& target);
        AForm*  createShrubbery(const std::string& target);
        AForm*  createPardon(const std::string& target);
        AForm*  createRobotomy(const std::string& target);
};

#endif