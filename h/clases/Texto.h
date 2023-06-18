#ifndef TEXTO_H
#define TEXTO_H

#include "Mensaje.h"

class Texto : public Mensaje
{
private:
  string texto;
public:
  //Texto(string text, map<string, Usuario> &receptores, DtRelojito fechaSistema, Usuario &emisor);
  ~Texto();

  string getTexto();

  //DtMensaje getDataMensaje();
  //DtInfoMensaje crearInfoMsg();
};



#endif