#ifndef DTINFOMENSAJE_H
#define DTINFOMENSAJE_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include "DTVisto.h"

using namespace std;

class DtInfoMensaje
{
    private:
        string phoneNum;
        string name;
        list<DtVisto> seenBy;
    public:
        // Constructor
        DtInfoMensaje(string phoneNum, string name, list<DtVisto> seenBy);

        // Getters
        string getPhoneNum();
        string getName();
        list<DtVisto> getSeenBy();
 
        // Destructor
        ~DtInfoMensaje();
            
        //friend ostream &operator<<(ostream &o, DtInfoMensaje &s);
};

#endif