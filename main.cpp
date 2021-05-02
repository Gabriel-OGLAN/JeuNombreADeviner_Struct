#include <iostream>
#include "CDate.h"
#include "CMeasure.h"
using namespace std;

void afficherDate (CDate &d)

{
    cout << d.getDay() << "/" << d.getMonth() << "/" << d.getYear() << "   " << d.getHour() << ":" << d.getMinute() << ":" << d.getSec() << endl;
}

int main()
{
    CMeasure Mesure1 (69,5,5,2019,20,14,1);
    CMeasure Mesure2 (69);
    CDate d1= Mesure1.getDate();
    CDate d2= Mesure2.getDate();

    cout << "Date de la 1re mesure : " << endl;
    afficherDate(d1);
    cout << "Date de la 2e mesure : " << endl;
    afficherDate(d2);
}

