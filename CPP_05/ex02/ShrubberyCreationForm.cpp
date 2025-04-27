#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("None", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw GradeTooLowException();
    if (executor.getGrade() > getExecute())
        throw GradeTooLowException();
    std::string filename = getName() + "_shrubbery";
    std::ofstream   outputFile(filename.c_str());
    if (outputFile.is_open())
    {
        std::string tree =
            "        ^\n"
            "       ^^^\n"
            "      ^^^^^\n"
            "     ^^^^^^^\n"
            "    ^^^^^^^^^\n"
            "   ^^^^^^^^^^^\n"
            "  ^^^^^^^^^^^^^\n"
            " ^^^^^^^^^^^^^^^\n"
            "^^^^^^^^^^^^^^^^^\n"
            "       |||\n"
            "       |||\n"
            "       |||\n";
        outputFile << tree;
        outputFile.close();
    }
    else
        std::cout << "Error opening the file" << std::endl;
}