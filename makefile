# Compilador
CC = g++

# Flags del compilador, se puede agregar -Werror si queremos que trate las warnings como errores
CFLAGS = -g -Wall -Wno-unknown-pragmas

# Ejecutable
PRINCIPAL = main

# Directorios
HDIR = h
CPPDIR = cpp
ODIR = o

# Clases
CLASES_CLASSES = Contacto Conversacion Imagen Mensaje Relojito Texto Usuario Video Visto Grupo Privada Participante
CLASES_CONTROLLERS = CAutenticacion CContacto CConversacion
CLASES_FABRICA = Fabrica
CLASES_DATATYPES = DtContacto DtConversacion DtFecha DtInfoMensaje DtMensaje DtUsuario DtVisto
CLASES_INTERFACES = IAutenticacion IContacto IConversacion
CLASES_UTILS = utils

CLASES = $(CLASES_CLASSES) $(CLASES_CONTROLLERS) $(CLASES_FABRICA) $(CLASES_DATATYPES) $(CLASES_UTILS)

# Archivos
HS_CLASSES = $(CLASES_CLASSES:%=$(HDIR)/clases/%.h)
CPPS_CLASSES = $(CLASES_CLASSES:%=$(CPPDIR)/clases/%.cpp)

HS_CONTROLLERS = $(CLASES_CONTROLLERS:%=$(HDIR)/controladores/%.h)
CPPS_CONTROLLERS = $(CLASES_CONTROLLERS:%=$(CPPDIR)/controladores/%.cpp)

HS_FABRICA = $(CLASES_FABRICA:%=$(HDIR)/fabrica/%.h)
CPPS_FABRICA = $(CLASES_FABRICA:%=$(CPPDIR)/fabrica/%.cpp)

HS_DATATYPES = $(CLASES_DATATYPES:%=$(HDIR)/dataTypes/%.h)
CPPS_DATATYPES = $(CLASES_DATATYPES:%=$(CPPDIR)/dataTypes/%.cpp) 

HS_INTERFACES = $(CLASES_INTERFACES:%=$(HDIR)/interfaces/%.h)

HS_UTILS = $(CLASES_UTILS:%=$(HDIR)/%.h)
CPPS_UTILS = $(CLASES_UTILS:%=$(CPPDIR)/%.cpp)

HS = $(HS_CLASSES) $(HS_CONTROLLERS) $(HS_FABRICA) $(HS_DATATYPES) $(HS_INTERFACES) $(HS_UTILS)
CPPS = $(CPPS_CLASSES) $(CPPS_CONTROLLERS) $(CPPS_FABRICA) $(CPPS_DATATYPES) $(CPPS_UTILS)

OS = $(CLASES:%=$(ODIR)/%.o)

# Archivo main y los subdirectorios
LAB5 = main.cpp $(HDIR) $(CPPDIR) $(ODIR)

#La regla que se va a ejecutar por defecto (ya que es la primera)
all: make

#Compila los .o (del directorio o/*.o) a partir de los .cpp y los .h
$(ODIR)/%.o: $(CPPDIR)/clases/%.cpp $(HDIR)/clases/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: $(CPPDIR)/controladores/%.cpp $(HDIR)/controladores/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: $(CPPDIR)/fabrica/%.cpp $(HDIR)/fabrica/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: $(CPPDIR)/dataTypes/%.cpp $(HDIR)/dataTypes/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

#Compila el main.o a partir del main.cpp
$(PRINCIPAL).o:$(PRINCIPAL).cpp
	$(CC) $(CFLAGS) -c $< -o $@

#Linkea todos los .o con el main.cpp y crea el ejecutable llamado main
make: main.cpp $(OS)
	$(CC) $(CFLAGS) -o main main.cpp $(OS)

#Crea un zip (hay que tener zip instalado en linux) con todos los archivos pertinentes
zip: $(LAB5) Makefile
	rm -f Gr3_Lab5.zip
	zip -r Gr3_Lab5.zip $(LAB5) integrantes.txt Makefile

#Borra todo
clean:
	-rm -f $(ODIR)/*.o
	-rm -f main
	-rm -f main.o
	-rm -f Gr3_Lab5.zip
