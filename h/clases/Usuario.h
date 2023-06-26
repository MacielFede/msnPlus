#ifndef USUARIO_H
#define USUARIO_H

// C++ macros
#include <string>
#include <map>
#include <list>

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
    Usuario(string telefono, string nombre, string imagenPerfil, string descripcion, DtFecha fechaActual); // Constructor
    DtUsuario getDataUsuario();
    void archivarConversacion(string idConversacion);
    list<DtConversacion> buscarConver();
    map<string, DtContacto> listarContactos();
    void agregarContacto(Usuario* c);
    Conversacion* crearConversacion(string cNumTel);
    void sincronizarConversacion(Conversacion* conver);
    void setFechaConexion(DtFecha nuevaFechaConexion);
    Conversacion* getConversacion(string idConversacion);
    DtUsuario setNombre(string nom);
    DtUsuario setImagen(string url);
    DtUsuario setDesc(string desc);
    string getNombre();
    bool existeConver(string idConver);
    string getTelefono();

    // destructor
    ~Usuario();
};

#endif