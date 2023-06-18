#ifndef CCONVERSACION_H
#define CCONVERSACION_H

#include <string>
#include "../clases/Conversacion.h"
#include "../clases/Mensaje.h"
#include "../dataTypes/DtConversacion.h"
#include "../dataTypes/DtContacto.h"
#include "../dataTypes/DtInfoMensaje.h"

using namespace std;

class CConversacion {
private:
  // Conversacion *memConversacion;
  // Mensaje *memMensaje
  static CConversacion* instancia;
  // Declaro la instancia CConversacion que despues le damos valor en cpp (no le doy valor aqui porque lo haria constante)
  CConversacion();
  // Hago el constructor privado para que ningún otro objeto pueda crear una instancia CConversacion
  CConversacion& operator=(const CConversacion&);
  // el operator override lo uso para que no se pueda usar CConversacion = x y romper todo
public:
  static CConversacion& getCConversacion();
  // crea una instancia de CConversacion si es que no se creo y la retorna.
  void archivarConversacion(string idConversacion);
  //   DtConversacion listarConversacionesActivas();
  //  DtConversacion listarConvArch();
  //  DtMensaje selConversacion(string idConversacion);
  void eliminarMensaje(string idMensaje);
  //  DtContacto listarContactos();
  void seleccionarContacto(string cNumTel);
  //  DtInfoMensaje informacionMensaje(string idMensaje);
  void enviarMensajeSimple(string msgTxt);
  void enviarImg(string url, string formato, string size, string desc);
  void enviarVideo(string url, string duracion);
  void enviarContacto(string cNumTel);
  void crearMensaje();
  ~CConversacion();
};


#endif