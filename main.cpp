#include <string>
#include <list>
#include "h/fabrica/Fabrica.h"
#include "h/interfaces/IAutenticacion.h"
#include "h/interfaces/IConversacion.h"
#include "h/interfaces/IContacto.h"
#include "h/clases/Relojito.h"
#include "h/dataTypes/DtUsuario.h"
#include "h/dataTypes/DtMensaje.h"
#include "h/utils.h"

using namespace std;

int main()
{
    string comando, idConver, numeroTelefono, modificacionPerfil;
    int idMensaje;
    map<string, Participante *> participantesNewGrupo;
    Relojito &relojito = Relojito::getRelojito();
    Fabrica &fabrica = Fabrica::getFabrica();
    IConversacion &Cconv = fabrica.getCConv();
    IAutenticacion &Caut = fabrica.getCAut();
    IContacto &Ccont = fabrica.getCCont();

#pragma region JuegoDeDatos

    Usuario *u1 = Caut.registrarJuegoDatosUsuario("080 12 36 54", "Juan Pérez", "home/img/perfil/juan.png", "Amo usar esta app", relojito.getFechaActual());
    Usuario *u2 = Caut.registrarJuegoDatosUsuario("080 76 54 32", "María Fernández", "home/img/perfil/maria.png", "Me encanta Prog. Avanzada", relojito.getFechaActual());
    Usuario *u3 = Caut.registrarJuegoDatosUsuario("080 24 68 10", "Pablo Iglesias", "home/img/perfil/pablo.png", "Hola! Estoy aquí", relojito.getFechaActual());
    Usuario *u4 = Caut.registrarJuegoDatosUsuario("080 66 67 77", "Sara Ruiz", "home/img/perfil/sara.png", "¡Estoy feliz!", relojito.getFechaActual());

    u1->agregarContacto(u2);
    u1->agregarContacto(u3);
    u1->agregarContacto(u4);

    u2->agregarContacto(u1);
    u2->agregarContacto(u3);

    u3->agregarContacto(u1);
    u3->agregarContacto(u2);
    u3->agregarContacto(u4);

    u4->agregarContacto(u1);
    u4->agregarContacto(u3);

    /*
        Faltan covers y mensajes
    */
#pragma endregion

    cout << "\nBienvenido a su mejor chat. Recuerde, para ejecutar los comandos debe ingresar siempre el numero del mismo.\n\n";

    do
    {
        // Actualicen la fecha bo
        relojito.actualizarFecha();

#pragma region AbrirApp
        // Abrir app
        while (!Caut.existeSesionActiva())
        {
            cout << "\n Ingrese su numero de telefono, ya sea para iniciar sesion o bien registrarse.\n";
            fflush(stdin);
            getline(cin, numeroTelefono);
            numeroTelefono = numFormat(numeroTelefono);
            bool existeUsuario = Caut.ingresarNumero(numeroTelefono);
            if (existeUsuario)
            {
                cout << "\n El numero ingresado ya esta registrado. Desea iniciar sesion con este numero?\n";
                cout << "\n Si[S] o No[N]\n";
                fflush(stdin);
                getline(cin, comando);
                // Iniciar sesion con ese usuario
                if (comando[0] == 'S' || comando[0] == 's')
                {
                    DtFecha fechaActual = relojito.getFechaActual();
                    Caut.iniciarSesion(fechaActual);
                    // Mostrar fecha y hora
                    cout << "\nHora de ultima conexion: ";
                    fechaActual.imprimirFechayHora();
                }
            } // No existe el usuario
            else
            {
                cout << "\n El numero ingresado no esta registrado. Desea registrarse con este numero?\n";
                cout << "\n Si[S] o No[N]\n";
                fflush(stdin);
                getline(cin, comando);
                // registrar ese usuario
                if (comando[0] == 'S' || comando[0] == 's')
                {
                    string nombre, urlPerfil, descripcion;
                    DtFecha fechaActual = relojito.getFechaActual();
                    cout << "\n Ingrese nombre: \n";
                    fflush(stdin);
                    getline(cin, nombre);

                    cout << "\n Ingrese url de foto de perfil: \n";
                    fflush(stdin);
                    getline(cin, urlPerfil);

                    cout << "\n Ingrese descripcion: \n";
                    fflush(stdin);
                    getline(cin, descripcion);
                    Caut.registrarUsuario(nombre, urlPerfil, descripcion, fechaActual);
                    // Mostrar fecha y hora
                    cout << "\nHora de ultima conexion: ";
                    fechaActual.imprimirFechayHora();
                }
            }
        }

#pragma endregion

#pragma region MenuPrincipal

        cout << "\nComandos:\n";
        cout << "1 - Mostrar Conversaciones.\n";
        cout << "2 - Crear grupo.\n";
        cout << "3 - Enviar mensaje.\n";
        cout << "4 - Ver contactos.\n";
        cout << "5 - Modificar perfil.\n";
        cout << "6 - Ver fecha y hora actual.\n";
        cout << "7 - Actualizar fecha y hora actual.\n";
        cout << "8 - Cerrar sesion.\n";
        cout << "9 - Cerrar app.\n\n";
        cout << "Que desea hacer? > ";

        fflush(stdin);
        // fflush() limpia el buffer del sistema, como estamos usando el buffer de la libreria std siempre puede quedarnos basura en el buffer
        getline(cin, comando);
        // getLine() lee 1 linea (osea hasta encontrar un \n) y guarda todo en la variable string que le pasemos
        // cin es el buffer de la libreria std (character in)
        switch (comando[0])
        {
        case '1':

#pragma region MostrarConvers
            do
            {
                if (comando[0] != '2')
                {
                    // Si el usuario selecciono imprimir las conversaciones archivadas anteriormente (osea ya estan impresas todas las conversaciones) no imprimo de nuevo
                    Cconv.imprimirConversaciones(true);
                }

                cout << "\nComandos:\n";
                cout << "1 - Abrir conversacion.\n";
                cout << "2 - Ver conversaciones archivadas.\n";
                cout << "3 - Archivar conversacion.\n";
                cout << "4 - Agregar participantes a un grupo.\n";
                cout << "5 - Ver fecha y hora actual.\n";
                cout << "6 - Volver al menu anterior.\n\n";
                cout << "Que desea hacer? > ";
                fflush(stdin);
                getline(cin, comando);

                switch (comando[0])
                {
                case '1':
                    cout << "Ingrese el id de la conversacion que quiere abrir, si es un grupo sera el nombre, si es privada sera el numero de telefono.\n> ";
                    fflush(stdin);
                    getline(cin, idConver);
                    if (!Cconv.existeConver(idConver))
                        cout << "No existe la conversacion indicada.\n";
                    else
                    {
                        do
                        {

                            list<DtMensaje *> mensajes = Cconv.selConversacion(idConver);
                            list<DtMensaje *>::iterator iter;
                            cout << "\nLos mensajes enviados comienzan con \'<\' y los recibidos comienzan con \'>\'.\n";
                            for (iter = mensajes.begin(); iter != mensajes.end(); ++iter)
                            {
                                //(* ) esto se usa para desreferenciar, iter es un iterador a un puntero.
                                if ((*iter)->usuarioEsEmisor(Caut.getSesionActivaDt().getNumTel()))
                                {
                                    cout << "< ";
                                    (*iter)->imprimir();
                                }
                                else
                                {
                                    cout << "> ";
                                    (*iter)->imprimir();
                                }
                            }

                            cout << "\nComandos:\n";
                            cout << "1 - Ver informacion de un mensaje enviado.\n";
                            cout << "2 - Eliminar mensaje.\n";
                            cout << "3 - Ver fecha y hora actual.\n";
                            cout << "4 - Actualizar fecha y hora actual.\n";
                            cout << "5 - Volver al menu anterior.\n";
                            cout << "6 - Volver al menu principal.\n\n";
                            cout << "Que desea hacer? > ";

                            fflush(stdin);
                            getline(cin, comando);

                            switch (comando[0])
                            {
                            case '1':
                                getInt("Ingrese el numero identificador del mensaje enviado que quiere ver.\n> ", idMensaje);
                                if (!Cconv.existeMensajeYEsEmisor(idMensaje))
                                    cout << "No existe el mensaje indicado o tu no eres el emisor.\n";
                                else
                                {
                                    list<DtVisto> infoMensaje = Cconv.informacionMensaje(idMensaje);
                                    list<DtVisto>::iterator iter;
                                    cout << "\tVisto por\tEl dia\n";
                                    for (iter = infoMensaje.begin(); iter != infoMensaje.end(); ++iter)
                                    {
                                        if (iter->getVisto())
                                        {
                                            cout << "\t" << iter->getNombre() << " - " << iter->getNumTel() << "\t";
                                            iter->getFechaVisto().imprimirFechayHora();
                                            cout << endl;
                                        }
                                    }
                                }
                                break;
                            case '2':
                                break;
                            case '3':
                                relojito.getFechaActual().imprimirFechayHora();
                                break;
                            case '4':
                                menuFechayHora();
                                break;

                            case '5':
                                cout << "Volviendo al menu de conversaciones.\n";
                                break;

                            case '6':
                                cout << "Volviendo al menu principal.\n";
                                // Cambio comando[0] a 7 para que el while lo tome como que el usuario quiere ir al menu principal
                                comando[0] = '7';
                                break;

                            default:
                                cout << "Ingresaste un comando inexistente.\n";
                                break;
                            }
                        } while (comando[0] != '6' && comando[0] != '5');
                    }
                    break;
                case '2':
                    Cconv.imprimirConversaciones(false);
                    break;

                case '3':

                    cout << "Ingrese el nombre del grupo o el numero del contacto que quiere archivar\n> ";
                    fflush(stdin);
                    getline(cin, idConver);

                    Cconv.archivarConversacion(idConver);

                    break;
                case '4':
                    relojito.getFechaActual().imprimirFechayHora();
                    break;
                case '5':
                    menuFechayHora();
                    break;
                case '6':
                    cout << "Volviendo al menu principal.\n";
                    break;
                default:
                    cout << "Ingresaste un comando inexistente.\n";
                    break;
                }
            } while (comando[0] != '6');
            break;
#pragma endregion

        case '2':
#pragma region Crear grupo
            // TODO: Crear grupo
            /*
            Mostrar contactos del usuario
            */

            participantesNewGrupo.clear();
            do
            {
                cout << "\nContactos del usuario no inculidos en el grupo:\n\n";
                for (list<DtContacto>::iterator it = Ccont.listarContactos().begin(); it != Ccont.listarContactos().end(); ++it)
                {
                    if (!participantesNewGrupo.count(it->getNumTel()))
                        cout << it->getNumTel() << " - " << it->getNombre() << "\n";
                }

                /*for (const auto &kv : participantesNewGrupo)
                {
                    std::cout << kv.first << " has value " << kv.second << std::endl;
                }*/

                for (const auto &[key, value] : participantesNewGrupo)
                {
                    cout << key << " - " << value->getUsuario()->getDataUsuario().getNombre() << "\n";
                }

                cout << "\nComandos:\n";
                cout << "(Numero de contacto sin espacios) - Agrega o elimina el contacto del grupo.\n";
                cout << "1 - Confirmar participantes.\n";
                cout << "2 - Cancelar.\n";

                fflush(stdin);
                getline(cin, comando);

                if (comando[0] == '1' && comando.length() == 1)
                { // Confirmar
                    if (participantesNewGrupo.size() > 0)
                    {
                        string nombreNewGrupo;
                        string urlNewGrupo;

                        cout << "Ingrese el nombre del nuevo grupo.\n";
                        fflush(stdin);
                        getline(cin, comando);

                        nombreNewGrupo = comando;

                        cout << "Ingrese la URL de la imagen del nuevo grupo.\n";
                        fflush(stdin);
                        getline(cin, comando);

                        urlNewGrupo = comando;

                        Grupo newGroup = {participantesNewGrupo, nombreNewGrupo, urlNewGrupo};

                        for (const auto &[key, value] : participantesNewGrupo)
                        {
                            value->getUsuario()->agregarGrupo(&newGroup);
                        }
                    }
                    else
                    {
                        cout << "Error, debe seleccionar al menos 1 partcipante en el grupo.\n";
                        cout << "1 - Agregar mas participantes.\n";
                        cout << "2 - Cancelar.\n";

                        fflush(stdin);
                        getline(cin, comando);
                    }
                }
                else
                {
                    if (comando.length() == 9)
                    {
                        if (Caut.esUsuario(comando))
                        {
                            if (Ccont.esContacto(comando))
                            {
                                if (!participantesNewGrupo.count(comando))
                                { // Agrega
                                    Participante p = {Caut.infoUsuario(comando), relojito.getFechaActual(), false};
                                    participantesNewGrupo.insert({comando, &p});
                                }
                                else
                                { // Elimina
                                    participantesNewGrupo.erase(comando);
                                }
                            }
                            else
                            {
                                cout << "Error, no existe un contacto con el numero" << comando << ".\n";
                            }
                        }
                        else
                        {
                            cout << "Error, no existe un usuario con el numero" << comando << ".\n";
                        }
                    }
                    else
                    {
                        cout << "Error, el formato del numero ingresado no es valido.\n";
                    }
                }
            } while (comando[0] != '2' && comando.length() == 1);
#pragma endregion
            break;

        case '3':
#pragma region EnviarMensaje
            // Muestro las conversaciones del usuario una vez sola
            Cconv.imprimirConversaciones(true);

            do
            {
                cout << "\nComandos:\n";
                cout << "1 - Seleccionar conversacion.\n";
                cout << "2 - Ver conversaciones archivadas.\n";
                cout << "3 - Crear nueva conversacion (privada).\n";
                cout << "4 - Enviar mensaje a la conversacion seleccionada.\n";
                cout << "5 - Volver al menu principal.\n\n";
                cout << "Que desea hacer? >";
                fflush(stdin);
                getline(cin, comando);

                switch (comando[0])
                {
                case '1':
                    cout << "Ingrese el id de la conversacion que quiere seleccionar, si es un grupo sera el nombre, si es privada sera el numero de telefono.\n> ";
                    fflush(stdin);
                    getline(cin, idConver);
                    if (!Cconv.existeConver(idConver))
                        cout << "No existe la conversacion indicada.\n";
                    else
                    {
                        // Selecciono conversacion
                        Cconv.selConversacion(idConver);
                        cout << "\n Se ha seleccionado dicha conversacion\n";
                    }
                    break;
                case '2':
                    Cconv.imprimirConversaciones(false); // Imprimo conversaciones archivadas
                    break;
                case '3':
                {
                    // Mostrar todos los contactos
                    list<DtContacto> contacts = Ccont.listarContactos();
                    int contactsSize = contacts.size();
                    cout << "\nContactos del usuario: (" << contactsSize << ")\n-------------------------------\n";
                    for (list<DtContacto>::iterator it = contacts.begin(); it != contacts.end(); ++it)
                    {
                        cout << it->getNumTel() << " - " << it->getNombre() << "\n";
                    }

                    cout << "\nIngrese el numero de telefono del usuario con el que quiere iniciar una conversacion.\n> ";
                    cout << "\nDe lo contrario si no desea iniciar una conversacion, no ingrese nada.\n";
                    fflush(stdin);
                    getline(cin, numeroTelefono);

                    if (!numeroTelefono.empty() && Ccont.esContacto(numeroTelefono) && !Cconv.existeConver(numeroTelefono))
                    {
                        Caut.getSesionActiva()->crearConversacion(numeroTelefono); // Crear conversacion con este salame
                        Cconv.selConversacion(numeroTelefono);                     // y dejarla como seleccionada en el controller
                        cout << "\nSe ha creado una conversacion con el contacto con numero de telefono " << numeroTelefono << " y se marco como seleccionada."  << endl;
                    }
                    else if (!Ccont.esContacto(numeroTelefono))
                    {
                        cout << "\nEl numero de contacto ingresado no existe. Volviendo al menu...\n";
                    }
                    else if (Cconv.existeConver(numeroTelefono))
                    {
                        cout << "\n Ya tiene una conversacion con este usuario. Volviendo al menu...\n";
                    }
                }
                break;

                case '4':
                    // Enviar mensaje ctm

                case '5':
                    cout << "Volviendo al menu principal.\n";
                    break;
                default:
                    cout << "Ingresaste un comando inexistente.\n";
                    break;
                }
            } while (comando[0] != '5');

#pragma endregion
            break;

        case '4':
        {
#pragma region VerContactos
            // TODO: Ver contactos
            list<DtContacto> contacts = Ccont.listarContactos();
            int contactsSize = contacts.size();
            cout << "Contactos del usuario: (" << contactsSize << ")\n-------------------------------\n";
            for (list<DtContacto>::iterator it = contacts.begin(); it != contacts.end(); ++it)
            {
                cout << it->getNumTel() << " - " << it->getNombre() << "\n";
            }
            do
            {
                cout << "\nComandos:\n";
                cout << "1 - Agregar nuevo contacto.\n";
                cout << "2 - Regresar.\n";

                fflush(stdin);
                getline(cin, comando);

                if (comando[0] == '1')
                {
                    string newContactNum;
                    cout << "Ingrese el número del nuevo contacto\n";

                    fflush(stdin);
                    getline(cin, newContactNum);
                    newContactNum = numFormat(newContactNum);

                    if (Caut.esUsuario(newContactNum))
                    {
                        if (!Ccont.esContacto(newContactNum))
                        {
                            DtUsuario contactUDt = Caut.infoUsuario(newContactNum)->getDataUsuario();

                            cout << "Información del contacto a agregar:\n";
                            cout << "Nombre:" << contactUDt.getNombre() << "\n";
                            cout << "Número:" << contactUDt.getNumTel() << "\n";
                            cout << "Imagen de perfil:" << contactUDt.getImagenPerfil() << "\n\n";

                            cout << "¿Desea agregarlo? S/N\n";
                            fflush(stdin);
                            getline(cin, comando);

                            if (comando[0] == 'S' || comando[0] == 's')
                            {
                                Ccont.agregarContacto(newContactNum);
                                cout << "Contacto agregado.\n";
                            }
                        }
                        else
                        {
                            cout << "Error, el usuario especificado ya es un contacto.\n";
                        }
                    }
                    else
                    {
                        cout << "Error, no existe un usuario con el número especificado.\n";
                    }
                }
            } while (comando[0] != '2');
        }
#pragma endregion
        break;

        case '5':
#pragma region ModificarPerfil
            cout << "\nQue quiere modificar? Nombre (N/n), Foto (F/f), Descripcion (D/d).\n";
            cout << "Si no indica nada o indica algo incorrecto se cancelara la operacion.\n";
            cout << "> ";

            fflush(stdin);
            getline(cin, comando);

            // DtUsuario usuarioCambiado;

            if (comando[0] == 'N' || comando[0] == 'n')
            {
                cout << "Indique su nuevo nombre: ";

                fflush(stdin);
                getline(cin, modificacionPerfil);

                // usuarioCambiado = Caut.cambiarNombre(modificacionPerfil);
            }
            else if (comando[0] == 'F' || comando[0] == 'f')
            {
                cout << "Indique el URL de su nueva foto de perfil: ";

                fflush(stdin);
                getline(cin, modificacionPerfil);

                // usuarioCambiado = Caut.cambiarFoto(modificacionPerfil);
            }
            else if (comando[0] == 'D' || comando[0] == 'd')
            {
                cout << "Indique su nueva descripcion: ";

                fflush(stdin);
                getline(cin, modificacionPerfil);

                // usuarioCambiado = Caut.cambiarDescripcion(modificacionPerfil);
            }

            // cout << "\nTu nueva informacion:\n";
            // cout << "Numero de telefono: " << usuarioCambiado->getNumTel() <<endl;
            // cout << "Imagen de perfil: " << usuarioCambiado->getImagenPerfil() <<endl;
            // cout << "Descripcion: " << usuarioCambiado->getDescripcion() <<endl;

            break;
#pragma endregion

        case '6':
#pragma region VerReloj
            // TODO: Relojito
            relojito.getFechaActual().imprimirFechayHora();
#pragma endregion
            break;

        case '7':
#pragma region ActualizarReloj
            // TODO: Relojito
            menuFechayHora();
#pragma endregion
            break;
        case '8':
#pragma region cerrarSesion
            cout << "\nEsta seguro de que quiere cerrar sesion? [S] o [N]\n";
            fflush(stdin);
            getline(cin, comando);
            if (comando[0] == 'S' || comando[0] == 's')
            {
                DtFecha fechaActual = relojito.getFechaActual();
                DtUsuario mefui = Caut.getSesionActivaDt();
                Caut.cerrarSesion(fechaActual);
                // Para testear que el usuario esta bien
                cout << "Nombre: " << mefui.getNombre() << "\nTelefono: " << mefui.getNumTel() << "\nUrlPerfil: " << mefui.getImagenPerfil() << "\nDescripcion: " << mefui.getDescripcion();
                cout << "\nFechaRegistro: ";
                mefui.getFechaRegistro().imprimirFechayHora();
                cout << "Ultima conexion: ";
                mefui.getUltimaConexion().imprimirFechayHora();
            }
            else
            {
                cout << "\nPerfecto, no cierres nada loco.\n";
            }
#pragma endergion
            break;

        case '9':
            cout << "\nNos vemos pronto!\n";
            break;

        default:
            cout << "Ingresaste un comando inexistente.\n";
            break;
        }
    } while (comando[0] != '9');

#pragma endregion

    // TODO: Eliminar todo
    return 0;
}