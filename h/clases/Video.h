#ifndef VIDEO_H
#define VIDEO_H

#include "Mensaje.h"
#include "../dataTypes/DtVideo.h"

class Video : public Mensaje
{
private:
  string url, duracion;
public:
  Video(map<string, Usuario*> receptores, DtFecha fechaEnv, Usuario* emisor, string URL, string dur, int ultimoId);
  ~Video();

  string getUrl();
  string getDuracion();

  DtMensaje*getDataMensaje();
};

#endif