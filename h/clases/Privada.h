#ifndef PRIVADA_H
#define PRIVADA_H

#include "Conversacion.h"
#include <map>

class Privada : public Conversacion
{
private:
    map<string, Usuario *> participantes;
    map<int, Mensaje *> mensajes;

public:
    Privada(Usuario *yo, Usuario *otro); // Creo conversacion privada con los dos integrantes

    map<string, Usuario *> getParticipantes();

    void setActivaFalse(string idUsuario);

    void eliminarMensaje(int idMensaje, string telSesion);

    list<DtVisto> infoMensajeCtm(int idMensaje);

    DtConversacion getDataConversacion(string telSesionAct, string telefonoOtro);

    string getNomUsuario(string otroUsuario);

    list<DtMensaje *> buscarMensajes(string telSesion);

    void asignarAConversacion(Mensaje *m);

    bool getActiva(string idUsuario);

    ~Privada();
};

#endif
