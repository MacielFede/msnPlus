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

void Usuario::agregarContacto(Usuario *c)
{
  contactos.insert({c->getDataUsuario().getNumTel(), c});
}

Conversacion *Usuario::crearConversacion(string cNumTel)
{
  try
  {
    Usuario *contacto = nullptr; // Puntero para almacenar el contacto encontrado
    Usuario *yo = this;

    // Buscar el contacto en el map de contactos
    auto it = contactos.find(cNumTel);

    // Verificar si se encontró el contacto
    if (it != contactos.end())
    {
      contacto = it->second;                                               // Almacenar el puntero al contacto encontrado
      Conversacion *nuevaConver = new Privada(contacto, yo);               // Crear conversacion
      this->conversaciones.insert({contacto->getTelefono(), nuevaConver}); // Agregarla al map de conversaciones
      contacto->conversaciones.insert({this->getTelefono(), nuevaConver}); // Agregarla al map del contacto
      cout << "Conversacion con " << contacto->getNombre() << " creada satisfactoriamente." << endl;
      return nuevaConver;
    }
    else
    {
      // Contacto no encontrado, puedes lanzar una excepción o manejar el caso en consecuencia
      throw invalid_argument("\n Usted no tiene un contacto con dicho numero.\n");
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

list<DtConversacion> Usuario::buscarConver()
{
  list<DtConversacion> convers;
  map<string, Conversacion *>::iterator iter;
  for (iter = this->conversaciones.begin(); iter != this->conversaciones.end(); ++iter)
  {
    if (Grupo *grupo = dynamic_cast<Grupo *>(iter->second))
      convers.push_back(iter->second->getDataConversacion("-"));
    else if (Privada *privada = dynamic_cast<Privada *>(iter->second))
      convers.push_back(iter->second->getDataConversacion(this->getNombre()));
  }
  return convers;
}

string Usuario::getNombre()
{
  return this->nombre;
}

// Actualizo fecha de ultima conexion
void Usuario::setFechaConexion(DtFecha nuevaFechaConexion)
{
  this->ultimaConexion = nuevaFechaConexion;
}

void Usuario::agregarGrupo(Conversacion *grupo)
{ // Falta generador de ids de conversaciones
  conversaciones.insert({"sdaasdasid", grupo});
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

map<string, DtContacto> Usuario::listarContactos()
{
  map<string, DtContacto> dtContacts;

  for (const auto &[key, value] : contactos)
  {
    // cout << key << " - " << value->getUsuario()->getDataUsuario().getNombre() << "\n";
    DtUsuario u = value->getDataUsuario();
    DtContacto c = {u.getNumTel(), u.getNombre(), u.getImagenPerfil()};
    dtContacts.insert({key, c});
  }

  return dtContacts;
}

DtUsuario Usuario::getDataUsuario()
{
  return DtUsuario(this->telefono, this->nombre, this->fechaRegistro, this->imagenPerfil, this->descripcion, this->ultimaConexion);
}

void Usuario::archivarConversacion(string idConversacion)
{
  if (this->conversaciones.find(idConversacion) != this->conversaciones.end())
  {                                                         // Si no encuetra un objeto con esa clave, retorna un iterador del final del map
    this->conversaciones[idConversacion]->setActivaFalse(); // Como lo encontro, seteo en falso activa
  }
}

bool Usuario::existeConver(string idConver)
{
  return conversaciones.find(idConver) != conversaciones.end();
}

Conversacion *Usuario::getConversacion(string idConversacion)
{
  return conversaciones.find(idConversacion)->second;
}

string Usuario::getTelefono()
{
  return this->telefono;
}