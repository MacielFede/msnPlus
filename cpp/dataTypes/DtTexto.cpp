#include "../../h/dataTypes/DtTexto.h"

DtTexto::DtTexto(string texto, int idMen, DtFecha fechaEnv, list<DtVisto> infoMens, DtUsuario emisor) {
  this->texto = texto;
  this->idMensaje = idMen;
  this->fechaEnvio = fechaEnv;
  this->infoMensaje = infoMens;
  this->emisor = emisor;
}


void DtTexto::imprimir() {
  cout << "id: " << this->idMensaje << " fecha envio: ";
  this->fechaEnvio.imprimirFechayHora();
  cout << " Mensaje: " << this->texto << endl;
}