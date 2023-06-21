## Laboratorio 6

### Realidad

  Con el objetivo de mejorar la comunicación entre estudiantes, docentes y otros usuarios de una
determinada institución educativa, se le ha encomendado la importante tarea de desarrollar una
aplicación de mensajería instantánea. Esta aplicación debe manejar la información de usuarios y
las conversaciones que estos mantienen entre sí, incluyendo mensajes y otros contenidos.
En primer lugar, interesa recabar información sobre los usuarios de la aplicación. De los usuarios
se conoce su número de teléfono celular el cual lo identifica, el nombre, la fecha de registro en la
aplicación, una imagen de perfil, una descripción y cuando se conectó por última vez. Además,
cada usuario tiene una lista personal de contactos, compuesta por los contactos de su dispositivo
inteligente que también utilizan la aplicación.
Los usuarios de la aplicación se envían mensajes, estableciendo de esta forma conversaciones.
Interesa conocer para un usuario su lista de conversaciones y para cada conversación el contacto
con el cual se estableció la misma y la lista de mensajes intercambiados en la conversación. A su
vez, una conversación puede ser activa o estar archivada.
Un mensaje puede ser simple cuando se trata de un texto, multimedia si contiene una foto o video,
y contacto cuando contiene los datos de un contacto que se quiere compartir. De los mensajes se
conoce un código que lo identifica y la fecha y hora en que fue enviado. Adicionalmente, se conoce
si un mensaje fue visto o no por su receptor. Para el caso de los mensajes simples, interesa saber
el texto que fue enviado en el mensaje. Para el caso de los mensajes multimedia, si contiene una
imagen se conoce su formato, tamaño y un texto que puede ser opcional. Si contiene un video se
conoce la duración de este. Por último, de los mensajes que contienen un contacto se conoce el
nombre y teléfono de contacto.
Cuando dos o más usuarios quieren mantener una conversación entre ellos, pueden crear un
grupo. De cada grupo se conoce un nombre que lo identifica, una imagen y la fecha y hora de
creación. Adicionalmente se conoce la lista de usuarios que integra el grupo. Por último, en un
grupo los usuarios pueden ser miembros o administradores. Los usuarios miembro pueden
enviar/recibir mensajes en el grupo y a la vez pueden editar las propiedades básicas del grupo
como el nombre y la imagen. Por otro lado, los usuarios administradores adicionalmente pueden
agregar/sacar usuarios del grupo. Todo grupo tiene al menos un usuario administrador, el cual
es por defecto el usuario que crea el grupo.
Por último, cuando un usuario quiere compartir un pensamiento con todos sus contactos utiliza
lo que se llama estado. Un estado es una publicación del usuario que se comparte con todos sus
contactos, por un tiempo limitado. Al pasar 24 horas desde la publicación de un nuevo estado,
este desaparece de la plataforma. De un estado se conoce un texto y la fecha y hora en que fue
publicado. A su vez un usuario puede tener varios estados activos al mismo tiempo.


El equipo de analistas del proyecto recabó información adicional acerca del sistema y como
conclusión se hará primero un prototipo como prueba de concepto. Para ello se definieron
ciertos requisitos funcionales a satisfacer. Estos requisitos están expresados en los siguientes
casos de uso. Un aspecto no funcional que se recabó es que el prototipo será usado por un
usuario a la vez; no concurrentemente. Por último, en todos los casos de uso que se necesite,
asumir que se cuenta con la fecha y hora actual (“fecha y hora del sistema”).


Nombre - Abrir app
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario desea utilizar la aplicación
ingresando con su número de celular. Si el número ingresado no existe en el
sistema, el usuario podrá volver a ingresar otro número (tantas veces como
lo desee), darse de alta con ese número o cancelar el caso de uso. Si desea
darse de alta, el sistema le solicita nombre, la URL de la imagen de perfil y
una descripción. Luego el sistema da de alta al usuario con la fecha y hora
actual del sistema, le asigna una sesión al usuario y actualiza la fecha y hora
de la última conexión con la fecha y hora actual del sistema. Por último, le
muestra la fecha y hora de conexión y finaliza el caso de uso. Si el usuario,
teniendo ya una sesión, intenta abrir la app nuevamente usando el mismo
número, el sistema no hace nada y termina el caso de uso. Si lo intenta con
otro número, el sistema le avisa que debe cerrar la sesión actual antes de abrir
con un número distinto y le da la opción de seguir con el caso de uso “Cerrar
App”. Luego, finaliza el caso de uso.
Comentarios
adicionales
Tener una sesión es requisito para usar cualquier otra funcionalidad de esta
aplicación.


Nombre - Cerrar app
Actores - Usuario
Sinopsis - El caso de uso permite cerrar la sesión de un usuario, que previamente ha
iniciado sesión en el sistema. El sistema elimina la sesión del usuario y
actualiza la fecha y hora de la última conexión con la fecha y hora actual del
sistema.


Nombre - Agregar contactos
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea agregar a otros usuarios de la aplicación como sus contactos.
Para ello, para cada contacto que desee agregar, primero el sistema lista los
contactos que el usuario posee. De cada uno se muestra el número de celular,
el nombre y la URL de la imagen de perfil. Luego el usuario puede agregar
un nuevo contacto, ingresando el número de celular de este o finalizar el caso
de uso. En la primera opción, el usuario indica el número de celular y el
sistema le muestra todos sus datos. El usuario confirma si desea agregarlo y
en caso afirmativo, el sistema lo agrega como contacto del usuario. Acto
seguido, el usuario puede elegir finalizar el caso de uso o continuar agregando
contactos como se describió anteriormente. En caso de que el usuario a
agregar como contacto no exista o corresponda a un contacto que ya posee,
el sistema muestra un mensaje acorde sin finalizar el caso de uso.


Nombre - Alta grupo
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea dar de alta un grupo. Este caso se realiza en dos grandes pasos.
El primer paso consiste en la elección de los participantes del grupo que debe
ser al menos uno (además del usuario que da de alta al grupo). Para este paso,
mientras el usuario lo desee se procede de la siguiente forma. El sistema lista
por un lado los datos de los contactos elegidos hasta el momento como
participantes del grupo y por otro de los contactos del usuario restantes.
Luego, el usuario puede quitar algún contacto elegido previamente o elegir
un nuevo participante. Para cualquiera de estas dos opciones utiliza el número
de celular. Si no elige a ningún participante, el sistema le avisa que debe
seleccionar al menos 1 y el usuario elige entre repetir este primer paso o
cancelar el caso de uso. Una vez elegidos los participantes del grupo, el paso
dos consiste en el ingreso por parte del usuario del nombre del grupo y la
URL de la imagen. El sistema termina dando de alta el grupo usando además
la fecha y hora actual como fecha y hora de creación del grupo y al usuario
con sesión como el administrador del grupo. En caso de que el usuario no
posea contactos, el sistema muestra un aviso y se finaliza el caso de uso. En
situaciones análogas se procede de la misma manera.
Comentarios
adicionales
En este caso de uso, los datos del contacto corresponden al número de celular
y el nombre.


Nombre - Agregar administradores a un grupo
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea agregar a otros participantes como administradores de un grupo.
Para ello el sistema lista el nombre de cada grupo en el que el usuario
participa. Luego el usuario selecciona un grupo del listado indicando su
nombre. El sistema lista datos de los participantes del grupo indicando
además para cada uno si es administrador o no. Si el usuario es administrador
del grupo, selecciona a uno de los participantes que no sea administrador para
agregarlo como tal. Luego el sistema agrega al participante elegido como 
administrador del grupo. Este proceso se repite mientras haya participantes
que no sean administradores y el usuario desee agregar administradores al
grupo. Al terminar este proceso, finaliza el caso de uso. En caso de que el
usuario no sea administrador del grupo o que el participante elegido ya sea
administrador, el sistema muestra un mensaje acorde a la situación, sin
finalizar el caso de uso.
En caso de que el usuario no participe en ningún grupo, el sistema muestra
un mensaje y finaliza el caso de uso.
Comentarios
adicionales
En este caso de uso, los datos de los participantes corresponden al número de
celular y el nombre.


Nombre - Enviar mensaje
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea enviar un mensaje. Primero, el sistema lista las conversaciones
del usuario. Para cada conversación activa, si se corresponde a un grupo se
muestra el nombre del grupo. Si es una conversación simple, se muestra
nombre y número de celular del contacto con el cual se mantiene la misma.
Para el caso de las conversaciones archivadas, se muestra una sola entrada
con la etiqueta “Archivadas” y la cantidad de conversaciones archivadas.
A continuación, el usuario puede elegir entre las siguientes opciones:
1. Seleccionar una conversación activa
2. Ver las conversaciones archivadas
3. Enviar un mensaje a un contacto con el cual aún no ha iniciado una
conversación
Si el usuario elige la primera opción, luego ingresa el identificador de la
conversación activa que quiere seleccionar. En caso de elegir la segunda
opción, el sistema lista las conversaciones archivadas de igual forma a la que
se listan las conversaciones activas. Luego el usuario ingresa el identificador
de la conversación archivada que quiere seleccionar. Si elige la tercera
opción, el sistema lista todos los contactos del usuario, mostrando para cada
uno su número de celular y nombre. Luego el usuario indica el contacto con
el cual quiere iniciar la conversación individual, ingresando el número de
celular de este. Posteriormente, el usuario elige el tipo de mensaje que desea
enviar entre las opciones simple, imagen, video o contacto. En caso de elegir
un mensaje simple debe ingresar el texto a enviar. En el caso de una imagen,
debe ingresar su URL, formato, tamaño y de forma opcional un texto
descriptivo de la imagen. En caso de elegir un video debe ingresar la URL de
este y la duración. Por último, si elige un contacto, el sistema lista el nombre
y número de celular de todos los contactos del usuario. Luego el usuario
selecciona el contacto que desea compartir ingresando el número de celular
de este. Finalmente, el sistema crea el mensaje con un código identificatorio
autogenerado por el sistema y la fecha y hora de envío con la fecha y hora
actual del sistema. Adicionalmente, en caso de que el mensaje sea enviado en
una conversación archivada, la misma se convierte en activa. Por último, el
mensaje se agrega como no visto. En caso de que el usuario no participe en
ninguna conversación, el sistema muestra un mensaje apropiado y se finaliza
el caso de uso. Este comportamiento se repite para situaciones análogas.


Nombre - Ver mensajes
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea ver los mensajes de una conversación. Primero, el sistema lista
las conversaciones del usuario. Para cada conversación activa, si se
corresponde a un grupo se muestra el nombre del grupo. Si es una
conversación simple, se muestra nombre y número de celular del contacto con
el cual se mantiene la misma. Para el caso de las conversaciones archivadas,
se muestra una sola entrada con la etiqueta “Archivadas” y la cantidad de
conversaciones archivadas.
A continuación, el usuario puede elegir entre las siguientes opciones:
1. Seleccionar una conversación activa
2. Ver las conversaciones archivadas
Si el usuario elige la primera opción, luego ingresa el identificador de la
conversación activa que quiere seleccionar.
En caso de elegir la segunda opción, el sistema lista las conversaciones
archivadas de igual forma a la que se listan las conversaciones activas. Luego
el usuario ingresa el identificador de la conversación archivada que quiere
seleccionar. A continuación, el sistema muestra todos los datos de los
mensajes de esa conversación. En caso de que sea de un grupo, sólo muestra
los mensajes cuya fecha y hora de envío sea mayor o igual a la fecha y hora
en que el usuario fue añadido al grupo. Además, marca aquellos mensajes
mostrados en el cual el usuario es receptor como mensaje visto registrando la
fecha y hora de visto con la fecha y hora actual del sistema. Finalmente, el
usuario puede elegir ver información adicional de sus mensajes enviados.
Seleccionando un mensaje enviado, el sistema muestra el nombre y número
de celular de los receptores que lo han visto junto con la fecha y hora en que
lo hicieron. Esto lo repite para los mensajes que desee. Luego, finaliza el caso
de uso. En caso de que el usuario no participe en ninguna conversación, el
sistema muestra un aviso y se finaliza el caso de uso. En situaciones análogas
se procede de la misma manera.
Comentarios
adicionales
Los datos de los mensajes corresponden al valor de sus atributos más la
información de visto en el caso de mensajes enviados por el usuario.


Nombre - Archivar conversaciones
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea archivar una o más conversaciones. Para ello el sistema lista las
conversaciones activas del usuario. Si la conversación corresponde a un grupo,
se muestra el nombre del grupo. Si corresponde a una conversación simple, se
muestra nombre y número de celular del contacto con el cual se mantiene la
conversación. Luego el usuario selecciona una conversación proporcionando
su identificador y finalmente el sistema cambiará dicha conversación a
archivada. Este proceso se repite mientras el usuario desee archivar
conversaciones. Luego finaliza el caso de uso. En caso de que el usuario no
tenga conversaciones activas, el sistema muestra un mensaje acorde y se
finaliza el caso de uso.


Nombre - Agregar participantes a un grupo
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea agregar participantes a un grupo. Para ello el sistema lista el
nombre de cada grupo en el cual el usuario participa y este selecciona uno
indicando su nombre. Acto seguido el sistema lista los datos de los
participantes del grupo, indicando además para cada uno si es administrador
y la fecha y hora en que fue añadido al grupo. Luego el sistema lista los
contactos del usuario. El usuario selecciona uno y en caso de que este no
forme parte del grupo, el sistema lo agrega. Esto se repite mientras el usuario
desee agregar contactos a un grupo. Al finalizar este proceso termina el caso
de uso. En caso de que el usuario no sea administrador del grupo o que el
número de celular no sea contacto del usuario, el sistema muestra un mensaje
apropiado, sin finalizar el caso de uso. En caso de que el usuario no participe
en ningún grupo, el sistema muestra un aviso y se finaliza el caso de uso.
Comentarios
adicionales
En este caso de uso, los datos de los participantes corresponden al número de
celular y el nombre.


Nombre - Eliminar participantes de un grupo
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea eliminar participantes de un grupo. Para ello el sistema lista el
nombre de cada grupo en el cual el usuario participa y este selecciona uno
indicando su nombre. El sistema lista los datos de los participantes del grupo,
indicando además para cada uno si es administrador. Si el usuario es
administrador del grupo, selecciona uno de los participantes indicando su
número de celular y el sistema lo elimina del grupo. Los mensajes del
participante dentro del grupo NO son eliminados. A su vez, de aquí en
adelante el participante eliminado no puede ver la conversación del grupo (por
tanto, no ve ningún mensaje del grupo ni puede enviar mensajes al mismo).
Esto se repite mientras el usuario desee eliminar participantes del grupo.
Luego finaliza el caso de uso. En caso de que el usuario no sea administrador
del grupo o que el número de celular del participante seleccionado no forme
parte del grupo, el sistema muestra un mensaje apropiado sin finalizar el caso
de uso. En caso de que el usuario no participe en ningún grupo, el sistema
muestra un aviso y se finaliza el caso de uso.
Comentarios
adicionales
En este caso de uso, los datos de los participantes corresponden al número de
celular y el nombre.


Nombre - Modificar usuario
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea modificar su información personal con excepción de su número
de celular y la fecha y hora de registro. Para ello el usuario ingresa los nuevos
valores de la información personal que desea actualizar, pudiendo elegir entre
el nombre de usuario, la URL de la imagen de perfil y su descripción personal.
Luego el sistema actualiza la información personal del usuario con los nuevos
valores ingresados y finaliza el caso de uso.


Nombre - Eliminar mensaje
Actores - Usuario
Sinopsis - El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea eliminar un mensaje. Primero, el sistema lista las
conversaciones del usuario. Para cada conversación activa, si se corresponde
a un grupo se muestra el nombre del grupo. Si es una conversación simple, se
muestra nombre y número de celular del contacto con el cual se mantiene la
misma. Para el caso de las conversaciones archivadas, se muestra una sola
entrada con la etiqueta “Archivadas” y la cantidad de conversaciones
archivadas.
A continuación, el usuario puede elegir entre las siguientes opciones:
1. Seleccionar una conversación activa
2. Ver las conversaciones archivadas
Si el usuario elige la primera opción, luego ingresa el identificador de la
conversación activa que quiere seleccionar.
En caso de elegir la segunda opción, el sistema lista las conversaciones
archivadas de igual forma a la que se listan las conversaciones activas. Luego
el usuario ingresa el identificador de la conversación archivada que quiere
seleccionar.
A continuación, el sistema muestra todos los datos de los mensajes de esa
conversación. En caso de que sea de un grupo, sólo muestra los mensajes cuya
fecha y hora de envío sea mayor o igual a la fecha y hora en que el usuario
fue añadido al grupo. Finalmente, el usuario selecciona el mensaje que desea
eliminar. Si el usuario es el emisor del mensaje, el sistema elimina el mensaje
desvinculándolo incluso de la conversación y de manera que no pueda ser
visto ni por su emisor ni por sus receptores en el futuro. Si el usuario es
receptor del mensaje se lo elimina de manera que pueda ser visto por el emisor
y los otros receptores. Dicho de otra forma, el primer caso corresponde a una
eliminación física y en el segundo caso a una eliminación lógica para el
usuario. En caso de que el usuario no participe en ninguna conversación, el
sistema muestra un aviso y se finaliza el caso de uso. En situaciones análogas
se procede de la misma manera.
Comentarios
adicionales
Los datos de los mensajes corresponden al valor de sus atributos más la
información de visto en el caso de mensajes enviados por el usuario.