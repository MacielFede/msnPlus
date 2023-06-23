#ifndef CCONVERSACION_H
#define CCONVERSACION_H

#include <string>
// Clases
#include "../clases/Conversacion.h"
#include "../clases/Mensaje.h"
#include "../clases/Privada.h"
#include "../clases/Grupo.h"
// Datatypes
#include "../dataTypes/DtConversacion.h"
#include "../dataTypes/DtContacto.h"
#include "../dataTypes/DtInfoMensaje.h"

// Interfaces
#include "../interfaces/IConversacion.h"

using namespace std;

class CConversacion : public IConversacion
{
private:
  Conversacion *memConversacion;
  Mensaje *memMensaje;
  static CConversacion *instancia;
  // Declaro la instancia CConversacion que despues le damos valor en cpp (no le doy valor aqui porque lo haria constante)
  CConversacion();
  // Hago el constructor privado para que ningún otro objeto pueda crear una instancia CConversacion
  CConversacion &operator=(const CConversacion &);
  // el operator override lo uso para que no se pueda usar CConversacion = x y romper todo
public:
  static CConversacion &getCConversacion();
  // crea una instancia de CConversacion si es que no se creo y la retorna.
  void archivarConversacion(string idConversacion);
  list<DtConversacion> listarConversacionesActivas();
  list<DtConversacion> listarConvArch();
  list<DtMensaje>  selConversacion(string idConversacion);
  void eliminarMensaje(string idMensaje);
  list<DtContacto> listarContactos();
  void seleccionarContacto(string cNumTel);
  DtInfoMensaje informacionMensaje(string idMensaje);
  void enviarMensajeSimple(string msgTxt);
  void enviarImg(string url, string formato, string size, string desc);
  void enviarVideo(string url, string duracion);
  void enviarContacto(string cNumTel);
  void crearMensaje();

  // Destructor
  ~CConversacion();
  void liberarInstancia();
};

#endif
