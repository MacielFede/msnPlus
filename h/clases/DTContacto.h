#ifndef DTCONTACTO_H
#define DTCONTACTO_H

#include <iostream>
#include <string>

using namespace std;

class DtContacto
{
    private:
        string phoneNum;
        string name;
        string profileImg;
    public:
        // Constructor
        DtContacto(string phoneNum, string name, string profileImg);

        // Getters
        string getPhone();
        string getName();
        string getProfileImg();
        // Destructor
        ~DtContacto();
            
        friend ostream &operator<<(ostream &o, DtContacto &s);
};

#endif