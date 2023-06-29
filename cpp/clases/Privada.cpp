#include "../../h/clases/Privada.h"
#include "../../h/clases/Mensaje.h"

Privada::Privada(Usuario *yo, Usuario *otro)
{
  // Inserto ambos participantes y listo
  this->participantes.insert({yo->getTelefono(), yo});
  this->participantes.insert({otro->getTelefono(), otro});
  this->activa = true;
  this->ultimoIdMensaje = 0;
}

map<string, Usuario *> Privada::getParticipantes()
{
  return this->participantes;
}

bool Privada::getActiva()
{
  return this->activa;
}

Privada::~Privada() {}

DtConversacion Privada::getDataConversacion(string telSesionAct)
{
  return DtConversacion(telSesionAct, this->getActiva(), this->getNomUsuario(telSesionAct));
}

string Privada::getNomUsuario(string otroUsuario)
{
  // Necesito retornar el nombre del otro participante de la conversacion privada
  auto it = this->participantes.find(otroUsuario);
  if (it != this->participantes.end())
  {
    return it->second->getNombre(); // Devuelve el usuario encontrado
  }
}

list<DtMensaje *> Privada::buscarMensajes(string telSesion)
{
  list<DtMensaje *> msj;
  map<int, Mensaje *>::iterator iter;
  for (iter = this->mensajes.begin(); iter != this->mensajes.end(); ++iter)
  {
    // Si el usuario no esta entre los receptores no mando el Dt
    if (iter->second->esReceptor(telSesion))
    {
      // Seteo el visto si es que nu fue visto
      if (!iter->second->fueVisto(telSesion))
        iter->second->setVisto(telSesion);
      msj.push_back(iter->second->getDataMensaje());
    }
  }
  return msj;
}

void Privada::asignarAConversacion(Mensaje *m) {}