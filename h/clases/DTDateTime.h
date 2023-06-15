#ifndef DTDATETIME_H
#define DTDATETIME_H
#include <iostream>
#include "DTDate.h"
using namespace std;

class DtDateTime : public DtDate
{
    private:
        // No tiro enie aca porque sino puede colapsar todo
        int hh, mm;
    public:
        // Constructores
        DtDateTime();
        DtDateTime(int d, int m, int y, int hh, int mm);
        // Getters
        int getHrs();
        int getMins();

        bool operator==(const DtDateTime &fecha);
        friend ostream &operator<<(ostream &o, DtDateTime &f);
        // Destructor
        ~DtDateTime();

        // Métodos
        bool isValid();
};
#endif
