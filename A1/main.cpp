#include <iostream>
#include "Moment.h"

using namespace std;

int main(int argc, char **argv)
{
    Moment m1(18,31,27);
    Moment m2(6,3,10);
    Moment m3(12,12,49);
    Moment m4(m3);
    Moment m5 = m1 +68;
    Moment m6 = m2 +m3;

    cout << m1.getMoment()<< endl;
    cout << m2.getMoment()<< endl;
    cout << m3.getMoment()<< endl;
    cout << m4.getMoment()<< endl;
    cout << m5.getMoment()<< endl;
    cout << m6.getMoment() << endl;


    return 0;
}