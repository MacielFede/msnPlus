#include "../../h/dataTypes/DtContactoMsj.h"


DtContactoMsj::DtContactoMsj(string numTel, string nombre, int idMen, DtFecha fechaEnv, list<DtVisto> infoMens, DtUsuario emisor) {
  this->numTel = numTel;
  this->nombre = nombre;
  this->idMensaje = idMen;
  this->fechaEnvio = fechaEnv;
  this->infoMensaje = infoMens;
  this->emisor = emisor;
}

void DtContactoMsj::imprimir() {
  cout << "< id: " << this->idMensaje << " fecha envio: ";
  this->fechaEnvio.imprimirFechayHora();
  cout << " numero: " << this->numTel << " nombre: " << this->nombre << endl;
}