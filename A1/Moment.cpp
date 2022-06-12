#include "Moment.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

Moment::Moment(int hour,int minute,int second)
{
    this->hour=hour;
    this->minute=minute;
    this->second=second;
}

Moment::~Moment()
{

}

Moment::Moment(const Moment& x)
{
    this->hour = x.hour;
    this->minute = x.minute;
    this->second = x.second;
}

void Moment::setHour(int hour)
{
    this->hour = hour;
}

void Moment::setMinute(int minute)
{
    this->minute = minute;
}

void Moment::setSecond(int second)
{
    this->second = second;
}

const int Moment::getHour() const
{
    return hour;
}
const int Moment::getMinute() const
{
    return minute;
}

const int Moment::getSecond() const
{
    return second;
}

Moment Moment::operator+ (int x)
{
    int newHour, newMinute, newSecond, all;
    all = (hour *3600) + (minute * 60) + second +x;

    newHour = all / 3600;
    all = all - (newHour *3600);
    newMinute = all / 60 ;
    all = all - (newMinute *60);
    newSecond = all;

    Moment newMoment( newHour, newMinute, newSecond);
    return newMoment;
}

Moment Moment::operator+ (Moment & x)
{
    int newHour, newMinute, newSecond, all;
    all = (hour *3600) + (minute * 60) + second + (x.hour *3600) + (x.minute * 60) + x.second;

    newHour = all / 3600;
    all = all - (newHour *3600);
    newMinute = all / 60 ;
    all = all - (newMinute *60);
    newSecond = all;

    Moment newMoment( newHour, newMinute, newSecond);
    return newMoment;

}

string Moment::getMoment()
{
    string temp= to_string(hour);
    temp += ":";
    temp += to_string(minute);
    temp += ":";
    temp += to_string(second);

    return temp;

}

bool Moment::operator== (const Moment & x)
{
    if (this->hour == x.hour && this->minute== x.minute && this->second==x.second)
    {
        return true;
    }
    
    return false;
}