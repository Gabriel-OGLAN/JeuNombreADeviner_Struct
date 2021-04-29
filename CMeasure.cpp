#include <time.h>
#include <iostream>
using namespace std;

#include "CDate.h"
#include "CMeasure.h"

CMeasure::CMeasure(float val, int jour, int mois, int annee, int seconde, int minute, int heure)
{
    this->value=val;
    CDate dateinit(jour,mois,annee,seconde,minute,heure);
    this->date=dateinit;
}

CMeasure::CMeasure(float val)
{
    val = 0;
    this->value = val;
}

float CMeasure::getVal()
{
    return this->value;
}

CDate CMeasure::getDate()
{
    return this->date;
}
