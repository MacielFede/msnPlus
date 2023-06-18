#ifndef IAUTENTICACION_H
#define IAUTENTICACION_H

#include <cstdlib>
#include <string>
#include "h/clases/Usuario.h"
#include "h/dataTypes/DtUsuario.h"

using namespace std;

class IAutenticacion
{
private:

public:
    bool ingresarNumero(string numTel);

    void registrarUsuario(string nombre, string urlPerfil, string desc);

    DtUsuario obtenerSesionActiva();

    Usuario infoUsuario(string cNumTel);
};

#endif