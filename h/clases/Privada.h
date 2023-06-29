#ifndef PRIVADA_H
#define PRIVADA_H

#include "Conversacion.h"
#include <map>

class Privada : public Conversacion
{
private:
    map<string, Usuario *> participantes;
    map<int, Mensaje *> mensajes;
    bool activa;

public:
    Privada(Usuario *yo, Usuario *otro); // Creo conversacion privada con los dos integrantes\

    map<string, Usuario *> getParticipantes();

    DtConversacion getDataConversacion(string telSesionAct);

    string getNomUsuario(string otroUsuario);

    list<DtMensaje *> buscarMensajes(string telSesion);

    void asignarAConversacion(Mensaje *m);

    bool getActiva();

    ~Privada();
};

#endif
