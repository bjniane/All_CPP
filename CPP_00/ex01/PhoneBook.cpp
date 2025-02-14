#include "PhoneBook.h"

PhoneBook::PhoneBook()
    : CurrentIndex(0), TotalContacts(0)
{
}

void    PhoneBook::ADD()
{
    Contact NewContact;
    std::string input;

    std::cin.ignore(10000, '\n');

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    NewContact.set_first_name(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    NewContact.set_last_name(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    NewContact.set_nickname(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    NewContact.set_darkest_secret(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    NewContact.set_phone_number(input);

    if (NewContact.IsEmpty())
    {
        std::cout << "A saved contact can't have empty fields." << std::endl;
        return ;
    }

    contacts[CurrentIndex] = NewContact;
    CurrentIndex = (CurrentIndex + 1) % 8;

    if (TotalContacts < 8)
        TotalContacts++;
    std::cout << "Contact saved successfully!" << std::endl;
}

void    PhoneBook::SEARCH()
{
    if (TotalContacts == 0)
    {
        std::cout << "Contact is empty." << std::endl;
        return ;
    }

    std::cout << "Index " << "| " << "FirstName " << "| " << "LastName " << "| " << "NickName" << std::endl;
    for (int i = 0; i < TotalContacts; i++)
    {
        std::cout << i << " | " << contacts[i].get_first_name() << " | " << contacts[i].get_last_name() << " | " << contacts[i].get_nickname() << std::endl;
    }
    std::cout << "Enter index of the contact you wanna display: ";
    int index;
    std::cin >> index;
    if (!std::cin)
    {
        std::cout << "Invalid input!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return ;
    }
    if (index < 0 || index >= TotalContacts)
    {
        std::cout << "Invalid index. Try again!" << std::endl;
        return ;
    }
    std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "NickName: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
    std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
}
