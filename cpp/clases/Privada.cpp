#include "../../h/clases/Privada.h"
#include "../../h/clases/Mensaje.h"
#include "../../h/clases/Texto.h"
#include "../../h/clases/Contacto.h"
#include "../../h/clases/Imagen.h"
#include "../../h/clases/Video.h"

Privada::Privada(Usuario *yo, Usuario *otro)
{
  // Inserto ambos participantes y listo
  this->participantes.insert({yo->getTelefono(), yo});
  this->participantes.insert({otro->getTelefono(), otro});
  this->privada = true;
  this->activa.insert({yo->getTelefono(), true});
  this->activa.insert({otro->getTelefono(), true});

  this->ultimoIdMensaje = 0;
}

void Privada::setActivaFalse(string idUsuario)
{
  auto it = this->activa.find(idUsuario);
  if (it != this->activa.end())
  {
    it->second = false;
  }
}

void Privada::eliminarMensaje(int idMensaje, string telSesion)
{
  map<int, Mensaje *>::iterator iterMsj = mensajes.find(idMensaje);
  if (iterMsj != mensajes.end())
  {
    if (iterMsj->second->esReceptor(telSesion) && iterMsj->second->esEmisor(telSesion))
    {
      delete iterMsj->second;
      mensajes.erase(idMensaje);
    }
    else if (iterMsj->second->esReceptor(telSesion))
    {
      iterMsj->second->eliminarReceptor(telSesion);
    }
    else
      cout << "Ya eliminaste el mensaje indicado.\n";
  }
  else
    cout << "El mensaje indicado no existe.\n";
}

list<DtVisto> Privada::infoMensajeCtm(int idMensaje)
{
  auto it = this->mensajes.find(idMensaje);
  if (it == this->mensajes.end())
  {
    cout << "Mensaje no encontrado." << endl;
    // Manejar el caso cuando el mensaje no se encuentra en el mapa.
    // Puedes lanzar una excepción, retornar un valor predeterminado, etc.
    return {}; // Retorna una lista vacía como ejemplo.
  }

  Mensaje *mens = it->second;
  if (mens == nullptr)
  {
    cout << "Puntero de mensaje nulo." << endl;
    // Manejar el caso cuando el puntero es nulo.
    return {}; // Retorna una lista vacía como ejemplo.
  }

  // Resto del código para imprimir y retornar información del mensaje.
  cout << "< ";
  if (Texto *texto = dynamic_cast<Texto *>(mens))
  {
    texto->getDataMensaje()->imprimir();
  }
  else if (Video *video = dynamic_cast<Video *>(mens))
  {
    video->getDataMensaje()->imprimir();
  }
  else if (Imagen *imagen = dynamic_cast<Imagen *>(mens))
  {
    imagen->getDataMensaje()->imprimir();
  }
  else if (Contacto *contacto = dynamic_cast<Contacto *>(mens))
  {
    contacto->getDataMensaje()->imprimir();
  }
  return mens->crearInfoMsg();
}

map<string, Usuario *> Privada::getParticipantes()
{
  return this->participantes;
}

bool Privada::getActiva(string idUsuario)
{
  return this->activa.find(idUsuario)->second;
}

Privada::~Privada() {}

DtConversacion Privada::getDataConversacion(string telSesionAct, string telefonoOtro)
{
  return DtConversacion(telefonoOtro, this->getActiva(telSesionAct), this->getNomUsuario(telefonoOtro));
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

void Privada::asignarAConversacion(Mensaje *m)
{
  this->mensajes.insert({m->getIdMensaje(), m});
}