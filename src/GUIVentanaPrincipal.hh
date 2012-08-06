/**
@author Nicolas Silva Herrera
 */

#ifndef _GUIVENTANAPRINCIPAL_HH
#define _GUIVENTANAPRINCIPAL_HH

#include "GUIVentanaPrincipal_glade.hh"
#include "SimpleGLScene.hh"
#include "malla.h"
#include "configreader.h"

using namespace std;

class GUIVentanaPrincipal : public GUIVentanaPrincipal_glade
{
public:
		GUIVentanaPrincipal();
		~GUIVentanaPrincipal();

private:
		Malla* malla;

		SimpleGLScene* simpleglscene;
		int velocidadAnimacion;

        void on_nuevo1_activate();
        void on_abrir1_activate();
        void on_guardar1_activate();
        void on_guardar_como1_activate();
        void on_salir1_activate();
        void on_cortar1_activate();
        void on_copiar1_activate();
        void on_pegar1_activate();
        void on_borrar1_activate();
        void on_distribuir_hormona1_activate();
        void on_deformar1_activate();
        void on_refinar1_activate();
		void on_desrefinar1_activate();
		void on_mejorar1_activate();
		void on_informacion1_activate();
        void on_mostrar_caras1_activate();
        void on_mostrar_arcos1_activate();
        void on_mostrar_colores_segun_concentracion1_activate();
		void on_enlentecer_animacion1_activate();
		void on_detener_animacion1_activate();
		void on_pausar_animacion1_activate();
		void on_iniciar_animacion1_activate();
		void on_apurar_animacion1_activate();
        void on_acerca_de1_activate();
        void on_toolbuttonNuevo_clicked();
        void on_toolbuttonAbrir_clicked();
		void on_toolbuttonGuardar_clicked();

		void escribirEnLog(string texto);
};
#endif
