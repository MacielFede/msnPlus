#ifndef PRIVADA_H
#define PRIVADA_H

#include "Conversacion.h"
#include <map>

class Privada : public Conversacion
{
private:
    map<string, Usuario *> participantes;

public:
    Privada(Usuario *yo, Usuario *otro); // Creo conversacion privada con los dos integrantes
    DtConversacion getDataConversacion(string telSesionAct);
    string getNomUsuario(string usuarioActivo);
    list<DtMensaje *> buscarMensajes(string telSesion);
    void asignarAConversacion(Mensaje *m);

    ~Privada();
};

#endif
