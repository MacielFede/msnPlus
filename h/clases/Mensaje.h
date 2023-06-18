#ifndef MENSAJE_H
#define MENSAJE_H

#include "Visto.h"
#include "Usuario.h"
#include "../dataTypes/DtMensaje.h"
#include "../dataTypes/DtInfoMensaje.h"
#include "../dataTypes/DtFecha.h"
#include <string>
using namespace std;

class Mensaje
{
private:
  int id;
  DtFecha fechaEnvio;
  Usuario* emisor;
  map<string, Visto*> receptores;
public:
  //Mensaje(map<string, Usuario> &receptores, DtRelojito fechaSistema, Usuario &emisor);
  ~Mensaje();
  // No tenemos setters porque no queremos cambiar nada del mensaje ya que estariamos alterando informacion fundamental del sistema.

  void eliminarReceptor(Usuario user);
  virtual DtMensaje getDataMensaje() = 0;
  virtual DtInfoMensaje crearInfoMsg() = 0;
};

#endif