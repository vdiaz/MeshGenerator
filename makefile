EXEC = treegrowthsimulator
CC = g++
LFLAGS = -O2 -lgsl -lgslcblas -lconfig++
PKG_CONFIG = `pkg-config gtkglextmm-1.2 --cflags --libs sigc++-2.0`

SOURCES = ./src/arco.cpp ./src/arcos.cpp ./src/cara.cpp ./src/caras.cpp ./src/comando.cpp ./src/configreader.cpp ./src/generar.cpp ./src/guardar.cpp ./src/GUIDialogInformacion.cc ./src/GUIDialogInformacion_glade.cc ./src/GUIVentanaPrincipal.cc ./src/GUIVentanaPrincipal_glade.cc ./src/informacionmalla.cpp ./src/informar.cpp ./src/malla.cpp ./src/nodo.cpp ./src/nodos.cpp ./src/polinomio.cpp ./src/punto.cpp ./src/segmenttriangleintersection.cpp ./src/segtriint.cpp ./src/SimpleGLScene.cc ./src/treegrowthsimulator.cc ./src/vect.cpp ./src/generafromcomsol_1.cpp ./src/generafrommatlab.cpp ./src/GUIDialogAbrirMatlab.cc ./src/GUIDialogAbrirMatlab_glade.cc ./src/generafromoff.cpp ./src/generafromarchivosxyzu.cpp ./src/almacenatocomsol_1.cpp ./src/almacenatooff.cpp ./src/almacenatoxyzu.cpp ./src/GUIDialogNuevaMalla.cc ./src/GUIDialogNuevaMalla_glade.cc ./src/generacilindro.cpp ./src/generafrommedula.cpp ./src/mejdelaunay.cpp ./src/mejorar.cpp ./src/refinar.cpp ./src/GUIDialogRefinar.cc ./src/GUIDialogRefinar_glade.cc ./src/lepp.cpp ./src/leppdelaunay.cpp ./src/delaunaylongestedgebisection.cpp ./src/angulominimo.cpp ./src/areacara.cpp ./src/largoarcomaximo.cpp ./src/desrefinar.cpp ./src/desrefinamientoedgecollapse.cpp ./src/GUIDialogDesrefinar.cc ./src/GUIDialogDesrefinar_glade.cc ./src/largoarcominimo.cpp ./src/distribuirhormona.cpp ./src/GUIDialogDistribuirHormona.cc ./src/GUIDialogDistribuirHormona_glade.cc ./src/deformar.cpp ./src/GUIDialogCambios.cc ./src/GUIDialogCambios_glade.cc ./src/verificacionlocal.cpp ./src/verificacionnodosvecinos.cpp ./src/noverificacion.cpp 
OUTPUT = salida

default:
	$(CC) $(SOURCES) $(LFLAGS) $(PKG_CONFIG) -o $(EXEC) 2> $(OUTPUT)
clean:
	rm -rf $(EXEC)
