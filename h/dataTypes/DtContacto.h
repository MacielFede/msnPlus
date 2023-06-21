#ifndef DTCONTACTO_H
#define DTCONTACTO_H

#include <iostream>
#include <string>

using namespace std;

class DtContacto
{
private:
    string numTel;
    string nombre;
    string imagenPerfil;

public:
    // Constructor
    DtContacto(string numTel, string nombre, string imagenPerfil);

    // Getters
    string getNumTel();
    string getNombre();
    string getImagenPerfil();
    // Destructor
    ~DtContacto();

    // friend ostream &operator<<(ostream &o, DtContacto &s);
};

#endif