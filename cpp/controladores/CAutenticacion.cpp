#include "../../h/controladores/CAutenticacion.h"

CAutenticacion* CAutenticacion::instancia = nullptr;
// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

CAutenticacion& CAutenticacion::getCAutenticacion()
{
    if (instancia == nullptr)
    {
        instancia = new CAutenticacion();
    }
    // Si la instancia ya fue creada retorno una referencia a la misma instancia
    return *instancia;
}

CAutenticacion::CAutenticacion() {}

CAutenticacion::~CAutenticacion()
{
}

void CAutenticacion::liberarInstancia()
{
    if (instancia != nullptr)
    {
        delete instancia;
        instancia = nullptr;
    }
}

CAutenticacion& CAutenticacion::operator=(const CAutenticacion&)
{
    return *this;
}

bool CAutenticacion::ingresarNumero(string numTel) {}

void CAutenticacion::registrarUsuario(string nombre, string urlPerfil, string desc) {}

DtUsuario CAutenticacion::obtenerSesionActiva() {}

Usuario CAutenticacion::infoUsuario(string cNumTel) {}

void CAutenticacion::cambiarDescripcion(string des) {
    this->memUsuario->setDesc(des);
    this->memUsuario->getDataUsuario();
}

void CAutenticacion::cambiarFoto(string url) {
    this->memUsuario->setDesc(url);
    this->memUsuario->getDataUsuario();
}

void CAutenticacion::cambiarNombre(string nom) {
    this->memUsuario->setDesc(nom);
    this->memUsuario->getDataUsuario();
}