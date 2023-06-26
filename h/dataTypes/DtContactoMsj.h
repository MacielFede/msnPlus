#ifndef DTCONTACTOMSJ_H
#define DTCONTACTOMSJ_H

#include <iostream>
#include <string>
#include "DtMensaje.h"

using namespace std;

class DtContactoMsj : public DtMensaje
{
private:
  string numTel;
  string nombre;
public:
  // Constructor
  DtContactoMsj(string numTel, string nombre, int idMen, DtFecha fechaEnv, list<DtVisto> infoMens);

  // Getters
  string getNumTel();
  string getNombre();
  // Destructor
  ~DtContactoMsj();
  void imprimir();
  // friend ostream &operator<<(ostream &o, DtContacto &s);
};

#endif