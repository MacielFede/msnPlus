#include "../../h/controladores/CConversacion.h"

CConversacion *CConversacion::instancia = nullptr;
// Le doy valor a la instancia como null para que solo la primera vez creemos la instancia

CConversacion &CConversacion::getCConversacion()
{
    if (instancia == nullptr)
    {
        instancia = new CConversacion();
    }
    // Si la instancia ya fue creada retorno una referencia a la misma instancia
    return *instancia;
}

CConversacion::CConversacion() {}

CConversacion::~CConversacion()
{
}

void CConversacion::liberarInstancia()
{
    if (instancia != nullptr)
    {
        delete instancia;
        instancia = nullptr;
    }
}

CConversacion &CConversacion::operator=(const CConversacion &)
{
    return *this;
}

void CConversacion::imprimirConversaciones(bool activas)
{
    list<DtConversacion> convers = this->listarConversaciones();
    list<DtConversacion>::iterator iter;
    cout << "\tId de conversacion\tNombre de contacto\n";
    if (activas)
    {
        int cantArchiv = 0;
        for (iter = convers.begin(); iter != convers.end(); ++iter)
        {
            if (iter->getActiva())
                cout << "\t" << iter->getIdConv() << "\t" << iter->getNomUsuario() << "\n";
            else
                cantArchiv++;
        }
        cout << "Archivadas: " << cantArchiv << endl;
    }
    else
    {
        int cantActivas = 0;
        for (iter = convers.begin(); iter != convers.end(); ++iter)
        {
            if (!iter->getActiva())
                cout << "\t" << iter->getIdConv() << "\t" << iter->getNomUsuario() << "\n";
            else
                cantActivas++;
        }
        cout << "Activas: " << cantActivas << endl;
    }
}

void CConversacion::archivarConversacion(string idConversacion)
{
    CAutenticacion &autenticador = CAutenticacion::getCAutenticacion();
    Usuario *sesion = autenticador.getSesionActiva();
    sesion->archivarConversacion(idConversacion);
}

list<DtConversacion> CConversacion::listarConversaciones()
{
    CAutenticacion autenticador = CAutenticacion::getCAutenticacion();
    Usuario *sesion = autenticador.getSesionActiva();
    return sesion->buscarConver();
}


list<DtConversacion> CConversacion::listarGrupos() {
    CAutenticacion autenticador = CAutenticacion::getCAutenticacion();
    Usuario* sesion = autenticador.getSesionActiva();
    list<DtConversacion> conversaciones = sesion->buscarConver();
    list<DtConversacion> grupos;

    for (list<DtConversacion>::iterator it = conversaciones.begin(); it != conversaciones.end(); ++it)
        if(!it->getPrivada()) grupos.push_back(*it);

    return grupos;
}


list<DtMensaje *> CConversacion::selConversacion(string idConversacion)
{
    Usuario *sesion = CAutenticacion::getCAutenticacion().getSesionActiva();
    this->memConversacion = sesion->getConversacion(idConversacion);
    return memConversacion->buscarMensajes(sesion->getTelefono());
}

void CConversacion::eliminarMensaje(int idMensaje) {
    this->memConversacion->eliminarMensaje(idMensaje, CAutenticacion::getCAutenticacion().getSesionActivaDt().getNumTel());
}

list<DtContacto> CConversacion::listarContactos() {}

void CConversacion::seleccionarContacto(string cNumTel) {}

list<DtVisto> CConversacion::informacionMensaje(int idMensaje)
{
    // Devuelve el info mensaje e imprime el mensaje (asume que el mensaje existe).
    return memConversacion->informacionMensaje(idMensaje);
}

map<string, Usuario *> CConversacion::getIntegrantesConversacion()
{
    if (Grupo *grupo = dynamic_cast<Grupo *>(this->memConversacion))
    {
        // Crear map de integrantes
        return grupo->getParticipantes();
    }

    else if (Privada *privada = dynamic_cast<Privada *>(this->memConversacion))
    {
        // Crear map de integrantes
        return privada->getParticipantes();
    }
}

Conversacion *CConversacion::getConversacionActiva()
{
    return this->memConversacion;
}

// Creo mensaje de texto y lo guardo en memoria
void CConversacion::enviarMensajeSimple(string msgTxt)
{
    Mensaje *nuevoMensaje = new Texto(msgTxt, this->getIntegrantesConversacion(), Relojito::getRelojito().getFechaActual(), CAutenticacion::getCAutenticacion().getSesionActiva(), this->getConversacionActiva()->getUltimoIdMensaje());
    this->memMensaje = nuevoMensaje;
    cout << "\n El mensaje fue creado correctamente.\n";
}

// Creo mensaje de imagen y lo guardo en memoria
void CConversacion::enviarImg(string url, string formato, string size, string desc)
{
    Mensaje *nuevoMensaje = new Imagen(this->getIntegrantesConversacion(), Relojito::getRelojito().getFechaActual(), CAutenticacion::getCAutenticacion().getSesionActiva(), this->getConversacionActiva()->getUltimoIdMensaje(), formato, size, desc, url);
    this->memMensaje = nuevoMensaje;
    cout << "\n El mensaje fue creado correctamente.\n";
}

// Creo mensaje de video y lo guardo en memoria
void CConversacion::enviarVideo(string url, string duracion)
{
    Mensaje *nuevoMensaje = new Video(this->getIntegrantesConversacion(), Relojito::getRelojito().getFechaActual(), CAutenticacion::getCAutenticacion().getSesionActiva(), url, duracion, this->getConversacionActiva()->getUltimoIdMensaje());
    this->memMensaje = nuevoMensaje;
    cout << "\n El mensaje fue creado correctamente.\n";
}

// Creo mensaje de contacto y lo guardo en memoria
void CConversacion::enviarContacto(string cNumTel)
{
    DtUsuario contacto = CAutenticacion::getCAutenticacion().getSesionActiva()->getContacto(cNumTel);
    Mensaje *nuevoMensaje = new Contacto(this->getIntegrantesConversacion(), Relojito::getRelojito().getFechaActual(), CAutenticacion::getCAutenticacion().getSesionActiva(), this->getConversacionActiva()->getUltimoIdMensaje(), contacto);
    this->memMensaje = nuevoMensaje;
    cout << "\n El mensaje fue creado correctamente.\n";
}

void CConversacion::crearMensaje()
{
    try
    {
        this->memConversacion->asignarAConversacion(this->memMensaje);
        cout << "\nEl mensaje enviado a la conversacion seleccionada.\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool CConversacion::existeConver(string idConver)
{
    Usuario *sesion = CAutenticacion::getCAutenticacion().getSesionActiva();
    return sesion->existeConver(idConver);
}


bool CConversacion::existeMensajeYEsER(int idMensaje) {
    string telSesion = CAutenticacion::getCAutenticacion().getSesionActiva()->getTelefono();
    list<DtMensaje *> mensajes = memConversacion->buscarMensajes(telSesion);
    list<DtMensaje *>::iterator iter;
    for (iter = mensajes.begin(); iter != mensajes.end(); ++iter)
    {
        //(* ) esto se usa para desreferenciar, iter es un iterador a un puntero.
        if ((*iter)->getIdMensaje() == idMensaje && (*iter)->usuarioEsReceptor(telSesion) && (*iter)->usuarioEsEmisor(telSesion)) //Si estoy en el mensaje y el usuario es emisor -> true
            return true;
        else if ((*iter)->getIdMensaje() == idMensaje) //Si estoy en el mensaje pero el usuario no es emisor u receptor -> false 
            return false;
    }
    return false; // No existe el mensaje
}