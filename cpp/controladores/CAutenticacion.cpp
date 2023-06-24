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

Usuario* CAutenticacion::obtenerSesionActiva() {
    return this->memUsuario;
}

Usuario CAutenticacion::infoUsuario(string cNumTel) {}

DtUsuario CAutenticacion::cambiarDescripcion(string des) {
    this->memUsuario->setDesc(des);
    return this->memUsuario->getDataUsuario();
}

DtUsuario CAutenticacion::cambiarFoto(string url) {
    this->memUsuario->setDesc(url);
    return this->memUsuario->getDataUsuario();
}

DtUsuario CAutenticacion::cambiarNombre(string nom) {
    this->memUsuario->setDesc(nom);
    return this->memUsuario->getDataUsuario();
}