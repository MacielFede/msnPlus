#ifndef GRUPO_H
#define GRUPO_H

#include "Conversacion.h"
#include "Participante.h"

class Grupo : public Conversacion
{
private:
    string idUnica;
    string nombre;
    string imagen;
    DtFecha fechaCreacion;

    map<string, Participante*> participantes;

public:
    DtConversacion getDataConversacion(string telSesionAct);

    list<DtMensaje*> buscarMensajes(string telSesion);

    void asignarAConversacion(Mensaje* m);

    Grupo(); // Lo dejo vacio porque no se bien como seria el caso de uso de crear un grupo y como se le irian pasando los parametros
    Grupo(string id, map<string, Participante *> participantes, string nombre, string imagen);
    //No creo setters porque no deberiamos querer cambiar nada de los grupos

    string getImagen();

    DtFecha getFechaCreacion();

    void addParticipante(Participante * p);

    map<string, DtContacto> getParticipantes();

    bool esAdmin(string val);
    ~Grupo();
};

#endif