#ifndef DTVISTO_H
#define DTVISTO_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>   
#include "DTDateTime.h"

using namespace std;

class DtVisto
{
    private:
        string phoneNum;
        string name;
        DateTime seenDate;
    public:
        // Constructor
        DtVisto(string phoneNum, string name, DateTime seenDate);

        // Getters
        string getPhoneNum();
        string getName();
        DateTime getSeenDate();
 
        // Destructor
        ~DtVisto();
            
        //friend ostream &operator<<(ostream &o, DtVisto &s);
};

#endif