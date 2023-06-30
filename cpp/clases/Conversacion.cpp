#include "../../h/clases/Conversacion.h"
#include "../../h/clases/Texto.h"
#include "../../h/clases/Contacto.h"
#include "../../h/clases/Imagen.h"
#include "../../h/clases/Video.h"

Conversacion::~Conversacion() {}


int Conversacion::getUltimoIdMensaje()
{
  return ++this->ultimoIdMensaje;
}

string Conversacion::getIdConversacion()
{
  return this->idConversacion;
}

list<DtVisto> Conversacion::informacionMensaje(int idMensaje)
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