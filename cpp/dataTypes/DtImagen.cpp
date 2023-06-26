#include "../../h/dataTypes/DtImagen.h"


DtImagen::DtImagen(string formatoImg, string descripcion, string tamano, int idMen, DtFecha fechaEnv, list<DtVisto> infoMens) {
  this->formatoImg = formatoImg;
  this->descripcion = descripcion;
  this->tamano = tamano;
  this->idMensaje = idMen;
  this->fechaEnvio = fechaEnv;
  this->infoMensaje = infoMens;
}

DtImagen::~DtImagen() {}

void DtImagen::imprimir() {
  cout << "id: " << this->idMensaje << " fecha envio: ";
  this->fechaEnvio.imprimirFechayHora();
  cout << " formato de imagen: " << this->formatoImg << " tamano: " << this->tamano << " descripcion: " << this->descripcion << endl;
}