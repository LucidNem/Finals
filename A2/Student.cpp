#include "Student.h"
#include <cstring>

Student::Student(int AM, const char * name, int semester ,bool active)
{
    this->AM = AM;
    this->name= new char[strlen(name)+1];
    strcpy(this->name, name);
    this->semester = semester;
    this->active = active;
}

Student::~Student()
{
    delete [] name;
}

void Student::setAM(int AM)
{
    this->AM = AM;
}

void Student::setName(char * name)
{
    delete [] this->name;
    this->name = new char[strlen(name) +1];
    strcpy(this->name, name);
}

void Student::setSemester(int)
{
    this->semester = semester;
}
    
void Student::setActive(bool)
{
    this->active = active;
}

const int Student::getAM() const
{
    return AM;
}

const char * Student::getName() const
{
    return name;
}

const int Student::getSemester() const
{
    return semester;
}

const bool Student::getActive() const
{
    return active;
}

void Student::printStuds()
{
    cout << "AM: " << AM << " Name: " << name << " Semester: " << semester << " Active state:" ;
    if (active ==true)
    {
        cout << " yes" << endl;
    }
    else
    {
        cout << " no" << endl;
    }
}