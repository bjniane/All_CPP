#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat Test1("Test1", 50);
        Form form("form1", 50, 51);
        std::cout << form << std::endl;
        Test1.signForm(form);
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}