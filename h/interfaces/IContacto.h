#ifndef ICONTACTO_H
#define ICONTACTO_H

#include <cstdlib>
#include <list>
#include <string>
#include "h/clases/Usuario.h"
#include "h/dataTypes/DtContacto.h"

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