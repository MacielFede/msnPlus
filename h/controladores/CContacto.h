#ifndef CCONTACTO_H
#define CCONTACTO_H

#include <string>
#include <cstdlib>
#include <list>
// Datatypes
#include "../dataTypes/DtUsuario.h"
// Clases
#include "../clases/Usuario.h"
// Interfaces
#include "../interfaces/IContacto.h"

using namespace std;

class CContacto : public IContacto
{
private:
    Usuario *memContacto;
    // Declaro la instancia CContacto que despues le damos valor en cpp (no le doy valor aqui porque lo haria constante)
    static CContacto *instancia;
    // Hago el constructor privado para que ningún otro objeto pueda crear una instancia CContacto
    CContacto();
    // el operator override lo uso para que no se pueda usar CContacto = x y romper todo
    CContacto &operator=(const CContacto &);

public:
    // Crea una instancia de CContacto si es que no se creo y la retorna.
    static CContacto &getCContacto();

    list<DtContacto> listarContactos();
    Usuario ingresarNumeroContacto(string cNumTel);
    void agregarContacto(string cNumTel);

    ~CContacto();
};

#endif