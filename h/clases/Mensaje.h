#ifndef MENSAJE_H
#define MENSAJE_H

//#include "Usuario.h"
//#include "DtMensaje"
//#include "DtInfoMensaje"
//#include "DtRelojito.h"
#include "Visto.h"
#include <map>
#include <string>
using namespace std;

class Mensaje
{
private:
  int id;
  //DtRelojito fechaEnvio;
  //Usuario * emisor;
  map<string, Visto>* receptores;
public:
  //Mensaje(map<string, Usuario> &receptores, DtRelojito fechaSistema, Usuario &emisor);
  ~Mensaje();

  //map<string, Usuario> getReceptores();

  // No tenemos setters porque no queremos cambiar nada del mensaje ya que estariamos alterando informacion fundamental del sistema.

  //void eliminarReceptor(Usuario user);
  //virtual DtMensaje getDataMensaje() = 0;
  //virtual DtInfoMensaje crearInfoMsg() = 0;
};

#endif