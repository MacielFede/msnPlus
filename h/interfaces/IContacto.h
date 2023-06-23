#ifndef ICONTACTO_H
#define ICONTACTO_H

#include <cstdlib>
#include <list>
#include <string>
#include "../clases/Usuario.h"
#include "../dataTypes/DtContacto.h"

using namespace std;

class IContacto
{
private:

public:
    virtual list<DtContacto> listarContactos() = 0;

    virtual Usuario ingresarNumeroContacto(string cNumTel) = 0;

    virtual void agregarContacto(string cNumTel) = 0;

    virtual bool esContacto(string cNumTel) = 0;

    virtual DtContacto numToContacto(string cNumTel) = 0;
};

#endif