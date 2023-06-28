#ifndef CAUTENTICACION_H
#define CAUTENTICACION_H

// C++ macros
#include <string>
#include <map> // STL
#include <algorithm> // STL
/******** Dependencies **********/
// Datatypes
#include "../dataTypes/DtUsuario.h"
// Classes
#include "../clases/Usuario.h"
#include "../utils.h"

// Interfaces
#include "../interfaces/IAutenticacion.h"

using namespace std;

class CAutenticacion : public IAutenticacion
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
    void iniciarSesion(DtFecha nuevaFechaConexion);
    void cerrarSesion(DtFecha nuevaFechaConexion);
    void registrarUsuario(string nombre, string urlPerfil, string desc, DtFecha fechaActual);
    Usuario *registrarJuegoDatosUsuario(string numero, string nombre, string urlPerfil, string desc, DtFecha fechaActual);
    Usuario *getSesionActiva();
    DtUsuario getSesionActivaDt();
    Usuario *infoUsuario(string cNumTel);
    DtUsuario cambiarDescripcion(string des);
    DtUsuario cambiarFoto(string url);
    DtUsuario cambiarNombre(string nom);
    bool esUsuario(string cNumTel);
    bool existeSesionActiva();

    // Destructor
    ~CAutenticacion();
    void liberarInstancia();
};

#endif