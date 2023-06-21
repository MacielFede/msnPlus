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

    virtual void registrarUsuario(string nombre, string urlPerfil, string desc) = 0;

    virtual DtUsuario obtenerSesionActiva() = 0;

    virtual Usuario infoUsuario(string cNumTel) = 0;
};

#endif