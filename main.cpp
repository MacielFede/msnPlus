#include <string>
#include "h/fabrica/Fabrica.h"
#include "h/interfaces/IAutenticacion.h"
#include "h/interfaces/IConversacion.h"
#include "h/interfaces/IContacto.h"
#include "h/clases/Relojito.h"
#include "h/dataTypes/DtUsuario.h"

int main()
{
    // Problema de seg. fault al inicializar controladores (falta implementar, descomentar 1 por 1 al hacer)
    string comando, idConver, modificacionPerfil;
    // Relojito& relojito = Relojito::getRelojito();
    // Fabrica& fabrica = Fabrica::getFabrica();
    // IConversacion Cconv = fabrica.getCConv();
    // IAutenticacion Caut = fabrica.getCAut();
    // IContacto Ccont = fabrica.getCCont();

    cout << "\nBienvenido a su mejor chat. Recuerde, para ejecutar los comandos debe ingresar siempre el numero del mismo.\n\n";
#pragma region AbrirApp
    // TODO: ACA HACER ABRIR APP

#pragma endregion

#pragma region MenuPrincipal

    do {
        cout << "\nComandos:\n";
        cout << "1 - Mostrar Conversaciones.\n";
        cout << "2 - Crear grupo.\n";
        cout << "3 - Enviar mensaje.\n";
        cout << "4 - Ver contactos.\n";
        cout << "5 - Modificar perfil.\n";
        cout << "6 - Ver fecha y hora actual.\n";
        cout << "7 - Actualizar fecha y hora actual.\n";
        cout << "8 - Cerrar app.\n\n";
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
            do {
                //TODO: Imprimir conversaciones

                cout << "\nComandos:\n";
                cout << "1 - Abrir conversacion.\n";
                //Esta opcion mostrara los mensajes de la conversacion y ahi el usuario eligira si ver mas info de un mensaje o eliminar un mensaje
                cout << "2 - Archivar conversacion.\n";
                cout << "3 - Agregar participantes a un grupo.\n";
                cout << "4 - Ver fecha y hora actual.\n";
                cout << "5 - Actualizar fecha y hora actual.\n";
                cout << "6 - Volver al menu anterior.\n\n";
                cout << "Que desea hacer? > ";
                fflush(stdin);
                getline(cin, comando);

                switch (comando[0])
                {
                case '1':
                    // TODO: do{ if(!Cconv.existeConver(idConver)) cout << "No existe esa conversacion."; }while(!Cconv.existeConver(idConver));
                    //TODO: CConversacion -> existeConver(string idConver): true o false 
                    cout << "Ingrese el id de la conversacion que quiere abrir, si es un grupo sera el nombre, si es privada sera el numero de telefono.\n> ";
                    fflush(stdin);
                    getline(cin, idConver);
                    do {
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
                            break;
                        case '4':
                            break;

                        case '5':
                            cout << "Volviendo al menu de conversaciones.\n";
                            break;

                        case '6':
                            cout << "Volviendo al menu principal.\n";
                            //Cuando el comando es 6 siempre se volvera al menu principal
                            break;

                        default:
                            cout << "Ingresaste un comando inexistente.\n";
                            break;
                        }
                    } while (comando[0] != '6' && comando[0] != '5');
                    break;
                case '2':

                    break;
                case '3':

                    break;
                case '4':

                    break;
                case '5':

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
            //TODO: Crear grupo
#pragma endregion
            break;

        case '3':
#pragma region EnviarMensaje
            //TODO: Enviar mensaje
#pragma endregion
            break;

        case '4':
#pragma region VerContactos
            //TODO: Ver contactos
#pragma endregion
            break;

        case '5':
#pragma region ModificarPerfil
            cout << "\nQue quiere modificar? Nombre (N/n), Foto (F/f), Descripcion (D/d).\n";
            cout << "Si no indica nada o indica algo incorrecto se cancelara la operacion.\n";
            cout << "> ";

            fflush(stdin);
            getline(cin, comando);

            //DtUsuario usuarioCambiado;

            if (comando[0] == 'N' || comando[0] == 'n') {
                cout << "Indique su nuevo nombre: ";

                fflush(stdin);
                getline(cin, modificacionPerfil);

                //usuarioCambiado = Caut.cambiarNombre(modificacionPerfil);
            }
            else if (comando[0] == 'F' || comando[0] == 'f') {
                cout << "Indique el URL de su nueva foto de perfil: ";

                fflush(stdin);
                getline(cin, modificacionPerfil);

                //usuarioCambiado = Caut.cambiarFoto(modificacionPerfil);
            }
            else if (comando[0] == 'D' || comando[0] == 'd') {
                cout << "Indique su nueva descripcion: ";

                fflush(stdin);
                getline(cin, modificacionPerfil);

                //usuarioCambiado = Caut.cambiarDescripcion(modificacionPerfil);
            }

            //cout << "\nTu nueva informacion:\n";
            //cout << "Tu numero de telefono: " << usuarioCambiado->getNumTel() <<endl;
            //cout << "Tu imagen de perfil: " << usuarioCambiado->getImagenPerfil() <<endl;
            //cout << "Tu descripcion: " << usuarioCambiado->getDescripcion() <<endl;

            break;
#pragma endregion

        case '6':
#pragma region VerReloj
            //TODO: Relojito
#pragma endregion
            break;

        case '7':
#pragma region ActualizarReloj
            //TODO: Relojito
#pragma endregion
            break;

        case '8':
            cout << "\nNos vemos pronto!\n";
            break;

        default:
            cout << "Ingresaste un comando inexistente.\n";
            break;
        }
    } while (comando[0] != '8');

#pragma endregion

    //TODO: Eliminar todo
    return 0;
}