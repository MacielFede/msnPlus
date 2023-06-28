#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include "../dataTypes/DtFecha.h"
#include "Usuario.h"

class Participante
{
private:
    DtFecha fechaIngreso;
    bool administrador;
    Usuario* usuario;
public:
    Participante(Usuario* soy, DtFecha fecha, bool soyAdmin);
    ~Participante();

    void setAdmin(bool admin);

    DtFecha getFechaIngreso();

    bool getAdminStatus();

    Usuario* getUsuario();
};

#endif