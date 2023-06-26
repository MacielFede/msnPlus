#include "../../h/dataTypes/DtVideo.h"

DtVideo::DtVideo(string duracion, int idMen, DtFecha fechaEnv, list<DtVisto> infoMens) {
  this->duracion = duracion;
  this->idMensaje = idMen;
  this->fechaEnvio = fechaEnv;
  this->infoMensaje = infoMens;
}

void DtVideo::imprimir() {
  cout << "id: " << this->idMensaje << " fecha envio: ";
  this->fechaEnvio.imprimirFechayHora();
  cout << " duracion del video: " << this->duracion << endl;
}
