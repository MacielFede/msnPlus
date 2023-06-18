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
#include "../clases/Conversacion.h"
using namespace std;

class Usuario
{
private:
    string telefono;
    string nombre;
    // DtDateTime fechaRegistro;
    string imagenPerfil;
    string descripcion;
    // DtDateTime ultimaConexion;
    map<string, Conversacion *> conversaciones;
    map<string, Usuario *> contactos;

public:
    Usuario(); // Constructor
    DtUsuario getDataUsuario();
    void archivarConversacion(string idConversacion);
    map<string, DtConversacion> buscarConver();
    map<string, DtContacto> listarContactos();
    Conversacion *crearConversacion(string cNumTel);
    void sincronizarConversacion(Conversacion *conver);
    Conversacion *getConversacion(string idConversacion);

    // destructor
    ~Usuario();
};

#endif