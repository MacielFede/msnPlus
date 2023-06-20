#ifndef DTINFOMENSAJE_H
#define DTINFOMENSAJE_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include "DtVisto.h"

using namespace std;

class DtInfoMensaje
{
private:
    string numTel;
    string nombre;
    list<DtVisto> vistoPor;
public:
    // Constructor
    DtInfoMensaje(string numTel, string nombre, list<DtVisto> vistoPor);

    // Getters
    string getNumTel();
    string getNombre();
    list<DtVisto> getVistoPor();

    // Destructor
    ~DtInfoMensaje();

    //friend ostream &operator<<(ostream &o, DtInfoMensaje &s);
};

#endif