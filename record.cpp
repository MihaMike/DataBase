#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"


int record::init (const char *initial_name, int initial_phone, int initial_group)
{
    phone = initial_phone;
    group = initial_group;
    if (initial_name)
    {
        name = new char[strlen(initial_name) + 1];
        if (name)
            strcpy(name, initial_name);
        else
            return 1;
    }
    return 0;
}

record::record (const char *initial_name, int initial_phone, int initial_group)
{
    init (initial_name, initial_phone, initial_group);
}

record::record (const record& rhs)
{
    init (rhs.name, rhs.phone, rhs.group);
}

record::~record()
{
    if (name)
        delete [] name;
    name = 0;
    phone = 0;
    group = 0;
}

record& record::operator= (const record& rhs)
{
    this -> record::~record();
    init(rhs.name, rhs.phone, rhs.group);
    return *this;
}

int record::operator< (const record& b) const
{
    return strcmp(name, b.name) < 0;
}

int record::operator== (const record& b) const
{
    return strcmp(name, b.name) == 0;
}
