#ifndef CAUTENTICACION_H
#define CAUTENTICACION_H

// C++ macros
#include <string>
#include <map> // STL

/******** Dependencies **********/
// Datatypes
#include "../dataTypes/DtUsuario.h"
// Classes
#include "../clases/Usuario.h"

using namespace std;

class CAutenticacion
{

private:
    string numTel;
    Usuario *memUsuario;                         // Usuario en memoria
    map<string, Usuario *> memColeccionUsuarios; // Coleccion de usuarios del sistema
    static CAutenticacion *instancia;            // Instancia del singleton
    CAutenticacion();                            // Constructor
    CAutenticacion &operator=(const CAutenticacion &);

public:
    static CAutenticacion &getCAutenticacion();
    bool ingresarNumero(string numTel);
    void registrarUsuario(string nombre, string urlPerfil, string desc);
    DtUsuario obtenerSesionActiva();
    Usuario infoUsuario(string cNumTel);

    // Destructor
    ~CAutenticacion();
};

#endif