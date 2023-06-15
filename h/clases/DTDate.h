#ifndef DTDATE_H
#define DTDATE_H
#include <iostream>
using namespace std;

class DtDate
{
    private:
        // No tiro enie aca porque sino puede colapsar todo
        int day, month, year;
    public:
        // Constructores
        DtDate();
        DtDate(int d, int m, int y);
        // Getters
        int getDay();
        int getMonth();
        int getYear();
        
        bool operator==(const DtDate &fecha);
        friend ostream &operator<<(ostream &o, DtDate &f);
        // Destructor
        ~DtDate();

        // Métodos
        bool isValid();
};

#endif
