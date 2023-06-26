#ifndef DTTEXTO_H
#define DTTEXTO_H

#include <iostream>
#include <string>
#include "DtMensaje.h"

using namespace std;

class DtTexto : public DtMensaje
{
private:
  string texto;
public:
  // Constructor
  DtTexto(string texto, int idMen, DtFecha fechaEnv, list<DtVisto> infoMens);

  // Destructor
  ~DtTexto();
  void imprimir();
  // friend ostream &operator<<(ostream &o, DtContacto &s);
};

#endif