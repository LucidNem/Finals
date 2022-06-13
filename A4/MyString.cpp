#include "MyString.h"
#include <iostream>
#include <cstring>

using namespace std;


MyString::MyString()
{
    str = new char [0];
    str = "";
}

MyString::MyString(char * str)
{
    this->str = new char [strlen(str)+1];
    for (int i=0; i<strlen(str)+1; i++)
    {
        this->str[i] =str[i];
    }
}

MyString::MyString(const MyString & x )
{
    this->str = new char [strlen(x.str)+1];
    for (int i=0; i<strlen(x.str)+1; i++)
    {
        this->str[i] =x.str[i];
    }   
}

MyString::~MyString()
{
    delete [] str;
}

bool MyString::operator==(const MyString & x)
{
    if (strlen(str) == strlen(x.str))
    {
        for (int i=0 ; i<strlen(str); i++)
        {
            if (str[i]!=x.str[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool MyString::operator!=(const MyString & x)
{
    if (strlen(str) == strlen(x.str))
    {
        for (int i=0 ; i<strlen(str); i++)
        {
            if (str[i]!=x.str[i])
            {
                return true;
            }
        }
        return false;
    }
    return true;
}

bool MyString::operator> (const MyString & x)
{
    if (strcmp(str,x.str)> 0)
    {
        return true;
    }
    return false;
}

bool MyString::operator< (const MyString & x)
{
    if (strcmp(str,x.str)< 0)
    {
        return true;
    }
    return false;
}

MyString MyString::operator += (char ch)
{
    char * temp;
    temp = new char [strlen(str)+1];
    for (int i=0; i<strlen(str)+1; i++)
    {
        temp[i] =str[i];
    }   
    delete [] str;

    this->str = new char [strlen(temp)+1];
    for (int i=0; i<strlen(temp)+1; i++)
    {
        this->str[i] = temp[i];
    }
    
    delete [] temp;

}

const char * MyString::getString() const
{
    return str;
}

int MyString::getLength()
{
    return strlen(str);
}

