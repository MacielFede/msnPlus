#include "../../h/clases/Usuario.h"
#include "../../h/clases/Conversacion.h"
#include "../../h/clases/Grupo.h"
#include "../../h/clases/Privada.h"

Usuario::Usuario(string telefono, string nombre, string imagenPerfil, string descripcion, DtFecha fechaActual)
{
  this->telefono = telefono;
  this->nombre = nombre;
  this->imagenPerfil = imagenPerfil;
  this->descripcion = descripcion;
  this->fechaRegistro = fechaActual;
  this->ultimaConexion = fechaActual;
}

Usuario::~Usuario() {}

void Usuario::agregarContacto(Usuario* c)
{
  contactos.insert({ c->getDataUsuario().getNumTel(), c });
}

list<DtConversacion> Usuario::buscarConver() {
  list<DtConversacion> convers;
  map<string, Conversacion*>::iterator iter;
  for (iter = this->conversaciones.begin(); iter != this->conversaciones.end(); ++iter) {
    if (Grupo* grupo = dynamic_cast<Grupo*>(iter->second))
      convers.push_back(iter->second->getDataConversacion());
    else if (Privada* privada = dynamic_cast<Privada*>(iter->second))
      convers.push_back(iter->second->getDataConversacion(this->getNombre()));
  }
  return convers;
}

string Usuario::getNombre() {
  return this->nombre;
}

// Actualizo fecha de ultima conexion
void Usuario::setFechaConexion(DtFecha nuevaFechaConexion)
{
  this->ultimaConexion = nuevaFechaConexion;
}

DtUsuario Usuario::setDesc(string desc)
{
  this->descripcion = desc;
  return this->getDataUsuario();
}

DtUsuario Usuario::setImagen(string url)
{
  this->imagenPerfil = url;
  return this->getDataUsuario();
}

DtUsuario Usuario::setNombre(string nom)
{
  this->nombre = nom;
  return this->getDataUsuario();
}

DtUsuario Usuario::getDataUsuario()
{
  return DtUsuario(this->telefono, this->nombre, this->fechaRegistro, this->imagenPerfil, this->descripcion, this->ultimaConexion);
}

void Usuario::archivarConversacion(string idConversacion) {
  if (this->conversaciones.find(idConversacion) != this->conversaciones.end()) { //Si no encuetra un objeto con esa clave, retorna un iterador del final del map
    this->conversaciones[idConversacion]->setActivaFalse(); //Como lo encontro, seteo en falso activa
  }
}

bool Usuario::existeConver(string idConver) {
  return conversaciones.find(idConver) != conversaciones.end();
}

Conversacion* Usuario::getConversacion(string idConversacion) {
  return conversaciones.find(idConversacion)->second;
}

string Usuario::getTelefono() {
  return this->telefono;
}