#include "../../h/clases/Grupo.h"
#include "../../h/clases/Mensaje.h"

Grupo::Grupo() {}
Grupo::Grupo(map<string, Participante *> participantes, string nombre, string imagen)
{
  this->participantes = participantes;
  this->nombre = nombre;
  this->imagen = imagen;
  this->ultimoIdMensaje = 0;
}

map<string, Usuario *> Grupo::getParticipantes()
{
  map<string, Usuario *> usuarios;

  // Utilizar un iterador para recorrer el map de participantes
  for (auto it = this->participantes.begin(); it != this->participantes.end(); ++it)
  {
    // Saco participante
    Participante *participante = it->second;
    Usuario *usuario = participante->getUsuario();

    // Agrego al map
    usuarios.insert({usuario->getTelefono(), usuario});
  }

  return usuarios;
}

Grupo::~Grupo() {}

bool Grupo::getActiva()
{
  return this->activa;
}

DtConversacion Grupo::getDataConversacion(string telSesionAct)
{
  return DtConversacion(this->getIdConversacion(), this->getActiva(), "-");
}

list<DtMensaje *> Grupo::buscarMensajes(string telSesion)
{
  list<DtMensaje *> msj;
  map<int, Mensaje *>::iterator iter;
  for (iter = this->mensajes.begin(); iter != this->mensajes.end(); ++iter)
  {
    // Si el usuario no esta entre los receptores o entro al grupo despues de que se envio el mensaje no mando el Dt
    if (iter->second->esReceptor(telSesion) && iter->second->getFechaEnvio().esMayor(this->participantes.find(telSesion)->second->getFechaIngreso()))
    {
      // Seteo el visto si es que nu fue visto
      if (!iter->second->fueVisto(telSesion))
        iter->second->setVisto(telSesion);
      msj.push_back(iter->second->getDataMensaje());
    }
  }
  return msj;
}

void Grupo::asignarAConversacion(Mensaje *m) {}