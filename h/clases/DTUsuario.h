#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <iostream>
#include <string>
#include "DTDate.h"
#include "DTDateTime.h"
using namespace std;

class DtUsuario
{
    private:
        string phoneNum;
        string name;
        DtDate regDate;
        string profileImg;
        string description;
        DtDateTime lastConnection;
    public:
        // Constructor
        DtUsuario(string phoneNum, string name, DtDate regDate, string profileImg, string description, DtDateTime lastConnection);

        // Getters
        string getPhone();
        string getName();
        DtDate getRegDate();
        string getProfileImg();
        string getDescription();
        DtDateTime getLastConnection();   
        // Destructor
        ~DtUsuario();
            
        friend ostream &operator<<(ostream &o, DtUsuario &s);
};

#endif