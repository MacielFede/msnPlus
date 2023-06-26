#ifndef GRUPO_H
#define GRUPO_H

#include "Conversacion.h"
#include "Participante.h"

class Grupo : public Conversacion
{
private:
    string imagen;
    DtFecha fechaCreacion;
    map<string, Participante*> participantes;
public:
    DtConversacion getDataConversacion();

    list<DtMensaje*> buscarMensajes(string telSesion);

    void asignarAConversacion(Mensaje* m);

    Grupo(); // Lo dejo vacio porque no se bien como seria el caso de uso de crear un grupo y como se le irian pasando los parametros

    //No creo setters porque no deberiamos querer cambiar nada de los grupos

    string getImagen();

    DtFecha getFechaCreacion();

    //list<DtParticipantes> getParticipantes(); No se si es necesario pero dejo la firma por las dudas

    ~Grupo();
};

#endif