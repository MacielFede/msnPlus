#ifndef CONTACTO_H
#define CONTACTO_H

#include "Mensaje.h"
#include "../dataTypes/DtContactoMsj.h"

class Contacto : public Mensaje
{
private:
  DtUsuario contacto;
public:
  Contacto();
  Contacto(map<string, Usuario*> receptores, DtFecha fechaEnv, Usuario* emisor, int ultimoId, DtUsuario contact);
  ~Contacto();

  DtUsuario getContacto();

  DtMensaje* getDataMensaje();
};

#endif