#include "CDate.h"

class CMeasure
{
    public:

    CMeasure(float val, int j, int m, int a, int s, int minu, int h);

    CMeasure(float val = 0);

    float getVal();

    CDate getDate();

    bool operator > (const CMeasure &mes);

    bool operator < (const CMeasure &mes);

    bool operator == (const CMeasure &mes);

    ~CMeasure();

    private:

       float value;

       CDate date;
};
