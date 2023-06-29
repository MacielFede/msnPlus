#include "../../h/clases/Grupo.h"
#include "../../h/clases/Mensaje.h"

Grupo::Grupo(){}
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
      value->getUsuario()->agregarGrupo(nombre, this); //pdria ser id
    }
}
Grupo::~Grupo() {}

DtConversacion Grupo::getDataConversacion(string telSesionAct) {
  return DtConversacion(this->getIdConversacion(), this->getActiva(), "-", false);
}

list<DtMensaje*> Grupo::buscarMensajes(string telSesion) {
  list<DtMensaje*> msj;
  map<int, Mensaje*>::iterator iter;
  for (iter = this->mensajes.begin(); iter != this->mensajes.end(); ++iter) {
    //Si el usuario no esta entre los receptores o entro al grupo despues de que se envio el mensaje no mando el Dt
    if (iter->second->esReceptor(telSesion) && iter->second->getFechaEnvio().esMayor(this->participantes.find(telSesion)->second->getFechaIngreso())) {
      //Seteo el visto si es que nu fue visto
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
  p->getUsuario()->agregarGrupo(nombre, this);//idunica en vez de nombre
}

void Grupo::asignarAConversacion(Mensaje* m) {}

map<string, DtContacto> Grupo::getParticipantes()
{
    map<string, DtContacto> vals;

    for (const auto &[key, value] : participantes)
    {
        Usuario* u = value->getUsuario();
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