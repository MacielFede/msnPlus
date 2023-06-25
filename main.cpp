#include <string>
#include <list>
#include "h/fabrica/Fabrica.h"
#include "h/interfaces/IAutenticacion.h"
#include "h/interfaces/IConversacion.h"
#include "h/interfaces/IContacto.h"
#include "h/clases/Relojito.h"
#include "h/dataTypes/DtUsuario.h"
#include "h/utils.h"

using namespace std;

int main()
{
    string comando, idConver, numeroTelefono, modificacionPerfil;
    Relojito& relojito = Relojito::getRelojito();
    Fabrica& fabrica = Fabrica::getFabrica();
    IConversacion& Cconv = fabrica.getCConv();
    IAutenticacion& Caut = fabrica.getCAut();
    //IContacto& Ccont = fabrica.getCCont();

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
                if (comando[0] != '2') {
                    //Si el usuario selecciono imprimir las conversaciones archivadas anteriormente (osea ya estan impresas todas las conversaciones) no imprimo de nuevo
                    imprimirConversaciones(true);
                }

                cout << "\nComandos:\n";
                cout << "1 - Abrir conversacion.\n";
                cout << "2 - Ver conversaciones archivadas.\n";
                cout << "3 - Archivar conversacion.\n";
                cout << "4 - Agregar participantes a un grupo.\n";
                cout << "5 - Ver fecha y hora actual.\n";
                cout << "6 - Actualizar fecha y hora actual.\n";
                cout << "7 - Volver al menu anterior.\n\n";
                cout << "Que desea hacer? > ";
                fflush(stdin);
                getline(cin, comando);

                switch (comando[0])
                {
                case '1':
                    // TODO: do{ if(!Cconv.existeConver(idConver)) cout << "No existe esa conversacion."; }while(!Cconv.existeConver(idConver));
                    // TODO: CConversacion -> existeConver(string idConver): true o false
                    cout << "Ingrese el id de la conversacion que quiere abrir, si es un grupo sera el nombre, si es privada sera el numero de telefono.\n> ";
                    fflush(stdin);
                    getline(cin, idConver);
                    do
                    {
                        // TODO: Imprimir mensajes de la conversacion.
                        cout << "\nComandos:\n";
                        cout << "1 - Ver informacion de un mensaje.\n";
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
                    break;
                case '2': { // Pongo llaves porque me tira error el switch si no
                    imprimirConversaciones(false);
                    break;
                }
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

                    break;

                case '7':
                    cout << "Volviendo al menu principal.\n";
                    break;
                default:
                    cout << "Ingresaste un comando inexistente.\n";
                    break;
                }
            } while (comando[0] != '7');
            break;
#pragma endregion

        case '2':
#pragma region Crear grupo
            // TODO: Crear grupo

#pragma endregion
            break;

        case '3':
#pragma region EnviarMensaje
            // TODO: Enviar mensaje
#pragma endregion
            break;

        case '4':
#pragma region VerContactos
            // TODO: Ver contactos

            /*
            Mostrar contactos del usuario
            */
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

                    if (true /*Existe el contacto en el sistema*/)
                    {
                        if (true /*!CContacto.esContacto(newContactNum)*/)
                        {
                            DtContacto newContactDt("a", "a", "a"); // CContacto getDt

                            cout << "Información del contacto a agregar:\n";
                            cout << "Nombre:" << newContactDt.getNombre() << "\n";
                            cout << "Número:" << newContactDt.getNumTel() << "\n";
                            cout << "Imagen de perfil:" << newContactDt.getImagenPerfil() << "\n\n";

                            cout << "¿Desea agregarlo? S/N\n";
                            fflush(stdin);
                            getline(cin, newContactNum);

                            if (comando[0] == 'S' || comando[0] == 's')
                            {
                                // CContacto.agregarContacto(newContactNum);
                                cout << "Contacto agregado.\n";
                            }
                        }
                        else
                        {
                            cout << "El usuario especificado ya es un contacto.\n";
                        }
                    }
                    else
                    {
                        cout << "No existe un usuario con el número especificado.\n";
                    }
                }
            } while (comando[0] != '2');

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