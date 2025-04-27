#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(0));
    try
    {
        Bureaucrat Test1("Test1", 33);
        RobotomyRequestForm   Form("form");

        Test1.signForm(Form);
        Test1.executeForm(Form);
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}