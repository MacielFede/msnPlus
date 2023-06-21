#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <iostream>
#include <string>
#include "DtFecha.h"
using namespace std;

class DtUsuario
{
private:
    string numTel;
    string nombre;
    DtFecha fechaRegistro;
    string imagenPerfil;
    string descripcion;
    DtFecha ultimaConexion;

public:
    // Constructor
    DtUsuario(string numTel, string nombre, DtFecha fechaRegistro, string imagenPerfil, string descripcion, DtFecha ultimaConexion);

    // Getters
    string getNumTel();
    string getNombre();
    DtFecha getFechaRegistro();
    string getImagenPerfil();
    string getDescripcion();
    DtFecha getUltimaConexion();
    // Destructor
    ~DtUsuario();

    // friend ostream &operator<<(ostream &o, DtUsuario &s);
};

#endif