#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>

#include "Student.h"

using namespace std;

vector <Student> createFromFile(string filename);

int main(int argc, char **argv)
{
    vector <Student> StudList;
    StudList= createFromFile("stoixeia.csv");

    for (int i=0; i< StudList.size(); i++)
    {
        StudList[i].printStuds();
    }
   

    return 0;
}

vector <Student> createFromFile(string filename)
{
    vector <Student> StudList;
    vector <string> row;
    string line, word, temp;

    ifstream Data;
    Data.open(filename.c_str(),ios::in);
    if (Data.is_open())
    {
        
        while( getline(Data,line))
        {
            if (line.empty())
            {
                break;
            }

            istringstream iss(line);
            string s1,s2,s3,s4;

            getline(iss, s1, ',');
            getline(iss, s2, ',');
            getline(iss, s3, ',');
            getline(iss, s4, ',');

            int AM = atoi(s1.c_str());
            char * name= new char [strlen(s2.c_str())];
            strcpy(name,s2.c_str());
            int semester = atoi(s3.c_str());
            bool active = atoi(s4.c_str());

            StudList.push_back(Student(AM,name,semester,active));
        }
       

    }
	Data.close();

    return StudList;
}