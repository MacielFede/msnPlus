#ifndef USUARIO_H
#define USUARIO_H

// C++ macros
#include <string>
#include <map>

/******** Dependencies **********/
//  Datatypes
#include "../dataTypes/DtUsuario.h"
#include "../dataTypes/DtConversacion.h"
#include "../dataTypes/DtContacto.h"
// Classes
// #include "Conversacion.h"
using namespace std;

class Conversacion;

class Usuario
{
private:
    string telefono;
    string nombre;
    DtFecha fechaRegistro;
    string imagenPerfil;
    string descripcion;
    DtFecha ultimaConexion;
    map<string, Conversacion*> conversaciones;
    map<string, Usuario*> contactos;

public:
    Usuario(); // Constructor
    DtUsuario getDataUsuario();
    void archivarConversacion(string idConversacion);
    map<string, DtConversacion> buscarConver();
    map<string, DtContacto> listarContactos();
    void agregarContacto(Usuario* c);
    Conversacion* crearConversacion(string cNumTel);
    void sincronizarConversacion(Conversacion* conver);
    Conversacion* getConversacion(string idConversacion);

    // destructor
    ~Usuario();
};

#endif