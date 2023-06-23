#ifndef PRIVADA_H
#define PRIVADA_H

#include "Conversacion.h"
#include <map>

class Privada : public Conversacion
{
private:
    map<string, Usuario*> participantes;
public:
    DtConversacion getDataConversacion();

    list<DtMensaje> buscarMensajes();

    DtInfoMensaje informacionMensaje(string idMensaje);

    void asignarAConversacion(Mensaje* m);
    
    Privada(); //No me acuerdo el caso de uso de crear una nueva conversacion
    ~Privada();
};

#endif 
