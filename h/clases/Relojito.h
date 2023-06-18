#ifndef RELOJITO_H
#define RELOJITO_H

#include <string>
#include "DTFecha.h"

using namespace std;

class Relojito 
{
    private:
        int dia, mes, anio, horas, minutos;
        // Declaro la instancia CContacto que despues le damos valor en cpp (no le doy valor aqui porque lo haria constante)
        static Relojito* instance;
        // Hago el constructor privado para que ningún otro objeto pueda crear una instancia CContacto
        Relojito();
        // El operator override lo uso para que no se pueda usar CContacto = x y romper todo
        Relojito& operator=(const Relojito&);
    public:
        // Crea una instancia de CContacto si es que no se creo y la retorna.
        static Relojito& getRelojito();

        // Obtener la fecha y hora actual
        DtFecha getFechaActual();
        
        // Establecer una nueva fecha y hora
        void setTime(DtFecha fechaNueva);
    
        ~Relojito();
};
#endif