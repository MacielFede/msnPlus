#ifndef VIDEO_H
#define VIDEO_H

#include "Mensaje.h"

class Video : public Mensaje
{
private:
  string url, duracion;
public:
  //Video(map<string, Usuario> &receptores, DtFecha fechaSistema, Usuario &emisor, string URL, string dur);
  ~Video();

  string getUrl();
  string getDuracion();

  DtMensaje getDataMensaje();
  DtInfoMensaje crearInfoMsg();
};

#endif