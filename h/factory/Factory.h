#ifndef FACTORY_H
#define FACTORY_H

#include "../controladores/CConversacion.h"
//#include "../controladores/CContacto.h"
//#include "../controladores/CAutenticacion.h"

class Factory{
private:
  static Factory *instancia;
    // Declaro la instancia Factory que despues le damos valor en cpp (no le doy valor aqui porque lo haria constante)
    Factory();
    // Hago el constructor privado para que ningún otro objeto pueda crear una instancia Factory
    Factory(const Factory &);
    // el constructor de copia sirve para que si alguien quiere crear otra instancia se cree una copia de la primera
    Factory &operator=(const Factory &);
    // el operator override lo uso para que no se pueda usar Factory = x y romper todo
    CConversacion & cconver = CConversacion::getCConversacion();
    //CContacto & ccontact;
    //CAutorizacion & caut;
public:
  static Factory &getFactory();
  // crea una instancia de Factory si es que no se creo y la retorna.
  CConversacion getCConversacion();
  //CAutenticacion getCAutenticacion();
  //CContacto getCContacto();
  ~Factory();
};

#endif