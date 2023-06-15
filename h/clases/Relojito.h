#ifndef RELOJITO_H
#define RELOJITO_H

#include <string>
#include "DTDateTime.h"

using namespace std;

class Relojito 
{
    private:
        DtDateTime curTime;
        // Declaro la instancia CContacto que despues le damos valor en cpp (no le doy valor aqui porque lo haria constante)
        static Relojito* instance;
        // Hago el constructor privado para que ningún otro objeto pueda crear una instancia CContacto
        Relojito();
        // eEl operator override lo uso para que no se pueda usar CContacto = x y romper todo
        Relojito& operator=(const Relojito&);
    public:
        // Crea una instancia de CContacto si es que no se creo y la retorna.
        static Relojito& getRelojito();

        // Obtener la fecha y hora actual
        DtDateTime getCurTime();
        
        // Establecer una nueva fecha y hora
        void setTime(DtDateTime newTime);
    
        ~Relojito();
};


#endif