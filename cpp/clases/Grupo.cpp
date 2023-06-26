#include "../../h/clases/Grupo.h"

Grupo::Grupo(){}
Grupo::Grupo(map<string, Participante *> participantes, string nombre, string imagen)
{
    this->participantes = participantes;
    this->nombre = nombre;
    this->imagen = imagen;
}

Grupo::~Grupo(){}

DtConversacion Grupo::getDataConversacion(){}

list<DtMensaje> Grupo::buscarMensajes(){}

DtInfoMensaje Grupo::informacionMensaje(string idMensaje){}

void Grupo::asignarAConversacion(Mensaje* m){}