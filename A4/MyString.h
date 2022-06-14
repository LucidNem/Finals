#include <iostream>
#include <cstring>

using namespace std;
 
class MyString
{
private:
    char * str;

public:
    MyString();
    MyString(char *);
    MyString( const MyString & );
    ~MyString();

    bool operator==(const MyString &);
    bool operator!=(const MyString &);
    bool operator> (const MyString &);
    bool operator< (const MyString &);
    void operator += (char);
    const char * getString() const;
    int getLength();

};