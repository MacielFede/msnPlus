#include "../../h/controladores/CAutenticacion.h"

CAutenticacion *CAutenticacion::instancia = nullptr;
// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

CAutenticacion &CAutenticacion::getCAutenticacion()
{
    if (instancia == nullptr)
    {
        instancia = new CAutenticacion();
        instancia->memUsuario = nullptr; // Cuando se instancia, le doy valor nulo al mamon del usuario de la memoria
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

CAutenticacion &CAutenticacion::operator=(const CAutenticacion &)
{
    return *this;
}

// Si memUsuario no es null, hay sesion activa
bool CAutenticacion::existeSesionActiva()
{
    return this->memUsuario != nullptr;
}

// Chequea que exista un usuario con ese numero
bool CAutenticacion::ingresarNumero(string numTel)
{
    this->numTel = numTel; // Guardo en memoria
    for (const auto &par : memColeccionUsuarios)
    {
        if (par.first == numTel)
        {
            return true; // El número de teléfono existe en el map
        }
    }
    return false;
}

// Seteo usuario
void CAutenticacion::iniciarSesion(DtFecha nuevaFechaConexion)
{
    try
    {
        Usuario *nuevaSesionActiva = this->infoUsuario(numFormat(this->numTel)); // Busco usuario y lo traigo
        nuevaSesionActiva->setFechaConexion(nuevaFechaConexion);      // Seteo nueva fecha
        this->memUsuario = nuevaSesionActiva;                         // Seteo sesion
        cout << "\n Sesion iniciada correctamente!";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Cierra sesion y actualiza fecha y hora de ultima conexion
void CAutenticacion::cerrarSesion(DtFecha nuevaFechaConexion)
{
    try
    {
        this->memUsuario->setFechaConexion(nuevaFechaConexion);
        this->memUsuario = nullptr;
        cout << "\nHa cerrado sesion satisfactoriamente. Hasta luego!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Crea instancia usuario y lo mete a la coleccion
// Pre: Usuario no existe todavia
void CAutenticacion::registrarUsuario(string nombre, string urlPerfil, string desc, DtFecha fechaActual)
{
    try
    {
        Usuario *nuevoUsuario = new Usuario(numFormat(this->numTel), nombre, urlPerfil, desc, fechaActual); // creo usuario
        this->memColeccionUsuarios.insert({numFormat(this->numTel), nuevoUsuario});                         // Inserto usuario
        this->memUsuario = nuevoUsuario;                                                         // seteo sesion
        cout << "\n Usuario creado y sesion iniciada correctamente.\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

Usuario* CAutenticacion::registrarJuegoDatosUsuario(string numero, string nombre, string urlPerfil, string desc, DtFecha fechaActual)
{
    numero = numFormat(numero);

    try
    {
        Usuario *nuevoUsuario = new Usuario(numero, nombre, urlPerfil, desc, fechaActual); // creo usuario
        this->memColeccionUsuarios.insert({numero, nuevoUsuario});                         // Inserto usuario
        cout << "\n Usuario "<< nombre  <<" creado.\n";

        return nuevoUsuario;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Devolvemos DtUsuario a capa-presentacion
DtUsuario CAutenticacion::getSesionActivaDt()
{
    return this->memUsuario->getDataUsuario();
}

Usuario *CAutenticacion::getSesionActiva()
{
    return this->memUsuario;
}

Usuario *CAutenticacion::infoUsuario(string cNumTel)
{
    try
    {
        auto it = memColeccionUsuarios.find(cNumTel);
        if (it != memColeccionUsuarios.end())
        {
            return it->second; // Devuelve el usuario encontrado
        }
        else // Tiro error si no esta
            throw invalid_argument("\nEl usuario que ingreso no existe.\n");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

DtUsuario CAutenticacion::cambiarDescripcion(string des)
{
    this->memUsuario->setDesc(des);
    return this->memUsuario->getDataUsuario();
}

DtUsuario CAutenticacion::cambiarFoto(string url)
{
    this->memUsuario->setDesc(url);
    return this->memUsuario->getDataUsuario();
}

DtUsuario CAutenticacion::cambiarNombre(string nom)
{
    this->memUsuario->setDesc(nom);
    return this->memUsuario->getDataUsuario();
}

bool CAutenticacion::esUsuario(string cNumTel)
{
    return this->memColeccionUsuarios.count(cNumTel);
}