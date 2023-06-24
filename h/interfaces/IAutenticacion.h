#ifndef IAUTENTICACION_H
#define IAUTENTICACION_H

#include <cstdlib>
#include <string>
#include "../clases/Usuario.h"
#include "../dataTypes/DtUsuario.h"

using namespace std;

class IAutenticacion
{
private:

public:
    virtual bool ingresarNumero(string numTel) = 0;

    virtual void registrarUsuario(string nombre, string urlPerfil, string desc, DtFecha fechaActual) = 0;

    virtual void iniciarSesion(DtFecha nuevaFechaConexion) = 0;

    virtual void cerrarSesion(DtFecha nuevaFechaConexion) = 0;

    virtual Usuario * getSesionActiva() = 0;

    virtual DtUsuario getSesionActivaDt() = 0;

    virtual Usuario * infoUsuario(string cNumTel) = 0;

    virtual DtUsuario cambiarDescripcion(string des) = 0;

    virtual DtUsuario cambiarFoto(string url) = 0;

    virtual DtUsuario cambiarNombre(string nom) = 0;

    virtual bool existeSesionActiva() = 0;
};

#endif