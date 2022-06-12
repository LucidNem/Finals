#include <iostream>

using namespace std;

class Moment
{
private:
    int hour;
    int minute;
    int second;
public:
    Moment(int ,int ,int );
    ~Moment();
    Moment(const Moment&);

    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    const int getHour() const;
    const int getMinute() const;
    const int getSecond() const;

    Moment operator+ (int);
    Moment operator+ (Moment &);

    string getMoment();
    bool operator== (const Moment &);
    
}; 