#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <ctype.h>
#include "Contact.h"

class   PhoneBook 
{
    private:
        Contact contacts[8];
        int CurrentIndex;
        int TotalContacts;
    public:
        PhoneBook();
        void    ADD();
        void    SEARCH();
};

#endif