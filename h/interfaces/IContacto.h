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
    list<DtContacto> listarContactos();

    Usuario ingresarNumeroContacto(string cNumTel);

    void agregarContacto();
};

#endif