#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");

    AForm* unknown = someRandomIntern.makeForm("unknown form", "Nowhere");

    delete rrf;
    delete scf;
    delete unknown;

    return 0;
}