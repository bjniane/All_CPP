#include "PhoneBook.h"
#include "Contact.h"

int main()
{
    PhoneBook   contact;
    std::string command;

    while (true)
    {
        std::cout << "Enter one of the following options:(ADD, SEARCH and EXIT): ";
        std::cin >> command;
        if (command == "ADD")
            contact.ADD();
        else if (command == "SEARCH")
            contact.SEARCH();
        else if (command == "EXIT")
        {
            std::cout << "exitting the program successfully!" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Try again!" << std::endl;
    }
    return (0);
}