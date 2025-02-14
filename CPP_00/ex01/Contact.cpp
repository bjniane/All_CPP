#include "Contact.h"

// Contact::Contact()
//     : FirstName(""), LastName(""), NickName(""), PhoneNumber(""), DarkestSecret("") 
// {
// }

bool    Contact::IsEmpty()
{
    return (FirstName.empty() || LastName.empty() || NickName.empty() || PhoneNumber.empty() || DarkestSecret.empty());
}

void    Contact::set_first_name(std::string first)
{
    FirstName = first;
}

void    Contact::set_last_name(std::string last)
{
    LastName = last;
}

void    Contact::set_nickname(std::string nick)
{
    NickName = nick;
}

void    Contact::set_phone_number(std::string phone)
{
    PhoneNumber = phone;
}

void    Contact::set_darkest_secret(std::string darkest)
{
    DarkestSecret = darkest;
}

std::string Contact::get_first_name()
{
    return FirstName;
}

std::string Contact::get_last_name()
{
    return LastName;
}

std::string Contact::get_nickname()
{
    return NickName;
}

std::string Contact::get_phone_number()
{
    return PhoneNumber;
}

std::string Contact::get_darkest_secret()
{
    return DarkestSecret;
}