#include <iostream>

#include "MyString.h"

using namespace std;

int main(int argc, char **argv)
{
    MyString s1;
    char temp[6]="Hello";
    MyString s2(temp);
    MyString s3(s2);
    MyString s4("a");
    MyString s5("b");
    MyString s6(s2);

    cout << s1.getString() << endl;
    cout << s2.getString() << endl;
    cout << s3.getString() << endl;

     s6 += 'D';
     cout << s2.getString() << endl;
     cout << s4.getString() << endl;
     cout << s5.getString() << endl;
     cout << s6.getString() << endl;


     if (s4 < s5)
     {
        cout<< s4.getString() <<  " is smaller than " << s5.getString() <<endl;
     }
     
     if (s5>s4)
     {
        cout<< s5.getString() <<  " is larger than " << s4.getString() <<endl;
     }

     
    if (s2==s3)
    {
        cout<< "The strings are the same: " << s2.getString() << " = " <<s3.getString() << endl; 
    }


    return 0;
}