#include "../../h/clases/Grupo.h"
#include "../../h/clases/Mensaje.h"
#include "../../h/clases/Texto.h"
#include "../../h/clases/Contacto.h"
#include "../../h/clases/Imagen.h"
#include "../../h/clases/Video.h"

Grupo::Grupo() {}
Grupo::Grupo(string id, map<string, Participante *> participantes, string nombre, string imagen)
{
  this->idConversacion = nombre;
  this->idUnica = id;
  this->participantes = participantes;
  this->nombre = nombre;
  this->imagen = imagen;
  this->activa = true;
  this->privada = false;
  for (const auto &[key, value] : participantes)
  {
    value->getUsuario()->agregarGrupo(nombre, this); // pdria ser id
  }
}
Grupo::Grupo(map<string, Participante *> participantes, string nombre, string imagen)
{
  this->participantes = participantes;
  this->nombre = nombre;
  this->imagen = imagen;
  this->ultimoIdMensaje = 0;
}

void Grupo::eliminarMensaje(int idMensaje, string telSesion)
{
  map<int, Mensaje *>::iterator iterMsj = mensajes.find(idMensaje);
  if (iterMsj != mensajes.end())
  {
    if (iterMsj->second->esReceptor(telSesion))
      iterMsj->second->eliminarReceptor(telSesion);
    else if (iterMsj->second->esReceptor(telSesion) && iterMsj->second->esEmisor(telSesion))
    {
      delete iterMsj->second;
      mensajes.erase(idMensaje);
    }
    else
      cout << "Ya eliminaste el mensaje indicado.\n";
  }
  else
    cout << "El mensaje indicado no existe.\n";
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

list<DtVisto> Grupo::infoMensajeCtm(int idMensaje)
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

DtConversacion Grupo::getDataConversacion(string telSesionAct)
{
  return DtConversacion(this->getIdConversacion(), this->getActiva(), "-", false);
}

bool Grupo::getActiva()
{
  return this->activa;
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

void Grupo::addParticipante(Participante *p)
{
  participantes.insert({p->getUsuario()->getTelefono(), p});
  p->getUsuario()->agregarGrupo(nombre, this); // idunica en vez de nombre
}

map<string, DtContacto> Grupo::getDtContactoParticipantes()
{
  map<string, DtContacto> vals;

  for (const auto &[key, value] : participantes)
  {
    Usuario *u = value->getUsuario();
    vals.insert({key, DtContacto(u->getTelefono(), u->getNombre(), u->getDataUsuario().getImagenPerfil())});
  }

  return vals;
}

bool Grupo::esAdmin(string val)
{
  if (!participantes.count(val))
    return false;

  return participantes.at(val)->getAdminStatus();
}

void Grupo::asignarAConversacion(Mensaje *m)
{
  this->mensajes.insert({m->getIdMensaje(), m});
}