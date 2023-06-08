#ifndef FABRICA_H
#define FABRICA_H

//#include "../controladores/CConversacion.h"
//#include "../controladores/CContacto.h"
//#include "../controladores/CAutenticacion.h"

class Fabrica{
private:
  static Fabrica *instancia;
    // Declaro la instancia fabrica que despues le damos valor en cpp (no le doy valor aqui porque lo haria constante)
    Fabrica();
    // Hago el constructor privado para que ningún otro objeto pueda crear una instancia Fabrica
    Fabrica(const Fabrica &);
    // el constructor de copia sirve para que si alguien quiere crear otra instancia se cree una copia de la primera
    Fabrica &operator=(const Fabrica &);
    // el operator override lo uso para que no se pueda usar Fabrica = x y romper todo
    //CConversacion * cconver;
    //CContacto * ccontact;
    //CAutorizacion * caut;
public:
  static Fabrica &getFabrica();
  // crea una instancia de Fabrica si es que no se creo y la retorna.
  //CConversacion getCConversacion();
  //CAutenticacion getCAutenticacion();
  //CContacto getCContacto();
  ~Fabrica();
};

#endif