#include <iostream>

using namespace std;

class Student
{
private:
    int AM;
    char * name;
    int semester;
    bool active;
public:
    Student(int, const char *, int ,bool);
    ~Student();

    void setAM(int AM);
    void setName(char *);
    void setSemester(int);
    void setActive(bool);

    const int getAM() const;
    const char * getName() const;
    const int getSemester() const;
    const bool getActive() const;

    void printStuds();



};