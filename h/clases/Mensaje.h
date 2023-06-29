#ifndef MENSAJE_H
#define MENSAJE_H

#include "Visto.h"
#include "Usuario.h"
#include "../dataTypes/DtMensaje.h"
#include "../dataTypes/DtFecha.h"
#include <string>
using namespace std;

class Mensaje
{
protected:
  int id; //Es autogenerado y depende de la conversacion, osea que debemos saber cual fue el ultimo id agregado en la conversacion.
  DtFecha fechaEnvio;
  Usuario* emisor;
  map<string, Visto*> receptores;
public:
  Mensaje(map<string, Usuario*> receptores, DtFecha fechaEnv, Usuario* emisor, int ultimoId);
  //El map de receptores va a tener todos los usuarios que tenga la conversacion actualmente, por lo tanto el emisor tambien va a ser receptor.
  //Esto lo hacemos para cumplir con las reglas de borrado logico y facilitar la impresion.
  virtual ~Mensaje() = default;
  // No tenemos setters porque no queremos cambiar nada del mensaje ya que estariamos alterando informacion fundamental del sistema.

  bool esEmisor(string telefonoSesion);
  bool esReceptor(string telefonoSesion);
  bool fueVisto(string telefonoSesion);
  void setVisto(string telefonoSesion);
  DtFecha getFechaEnvio();
  void eliminarReceptor(string telUser);
  virtual DtMensaje* getDataMensaje() = 0;
  list<DtVisto> crearInfoMsg();
};

#endif