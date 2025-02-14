#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class   Contact 
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
        // Contact();
        bool    IsEmpty();
        void    set_first_name(std::string first);
        void    set_last_name(std::string last);
        void    set_nickname(std::string nick);
        void    set_phone_number(std::string number);
        void    set_darkest_secret(std::string darkest);
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
};

#endif