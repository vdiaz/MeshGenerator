// generated 2007/5/4 17:18:16 CLT by chupacabrasx@amd64-3000.(none)
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/chupacabrasx/codeblocks/TreeGrowthSimulator/TreeGrowthSimulator.glade
// for gtk 2.10.11 and gtkmm 2.10.8
//
// Please modify the corresponding derived classes in ./src/GUIDialogNuevaMalla.hh and./src/GUIDialogNuevaMalla.cc

#ifndef _GUIDIALOGNUEVAMALLA_GLADE_HH
#define _GUIDIALOGNUEVAMALLA_GLADE_HH

#ifndef GLADEMM_DATA
#define GLADEMM_DATA

#include <gtkmm/accelgroup.h>
#include "configreader.h"

class GlademmData
{

        Glib::RefPtr<Gtk::AccelGroup> accgrp;
public:

        GlademmData(Glib::RefPtr<Gtk::AccelGroup> ag) : accgrp(ag)
        {
        }

        Glib::RefPtr<Gtk::AccelGroup>  getAccelGroup()
        {  return accgrp;
        }
};
#endif //GLADEMM_DATA

#include <gtkmm/comboboxtext.h>
#include <gtkmm/dialog.h>
#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/treeview.h>
#include <gtkmm/combo.h>
#include <gtkmm/box.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/table.h>
#include <gtkmm/alignment.h>
#include <gtkmm/frame.h>

class GUIDialogNuevaMalla_glade : public Gtk::Dialog
{

        GlademmData *gmm_data;
public:
        class Gtk::Dialog * GUIDialogNuevaMalla;
        class Gtk::Button * cancelbutton2;
        class Gtk::Button * okbutton3;
        class Gtk::Label * label12;
        class Gtk::ComboBoxText * comboTipoFigura;
        class Gtk::HBox * hbox9;
        class Gtk::Label * label13;
        class Gtk::SpinButton * spinbuttonAltura;
        class Gtk::Label * label14;
        class Gtk::SpinButton * spinbuttonRadio;
        class Gtk::Label * label15;
        class Gtk::SpinButton * spinbuttonNumeroDeAnillos;
        class Gtk::Label * label16;
        class Gtk::SpinButton * spinbuttonPuntosPorAnillo;
        class Gtk::Label * label17;
        class Gtk::Combo * comboTipoMalla;
        class Gtk::Table * table3;
        class Gtk::Alignment * alignment10;
        class Gtk::Label * label45;
        class Gtk::Frame * frameCilindro;
        class Gtk::Label * label51;
        class Gtk::Label * label52;
        class Gtk::Label * label53;
        class Gtk::Label * label54;
        class Gtk::SpinButton * spinbuttonMedulaRadio;
        class Gtk::SpinButton * spinbuttonMedulaNumeroDeAnillos;
        class Gtk::SpinButton * spinbuttonMedulaPuntosPorAnillo;
        class Gtk::Entry * entryMedulaArchivo;
        class Gtk::Button * buttonMedulaExplorarArchivo;
        class Gtk::HBox * hbox10;
        class Gtk::Table * table10;
        class Gtk::Alignment * alignment12;
        class Gtk::Label * label50;
        class Gtk::Frame * frameMedula;
        class Gtk::VBox * vbox9;
protected:
        ConfigReader* cfg_reader;
        GUIDialogNuevaMalla_glade();
        ~GUIDialogNuevaMalla_glade();
private:
        virtual void on_combo_entryTipoFigura_changed() = 0;
        virtual void on_buttonMedulaExplorarArchivo_clicked() = 0;
};
#endif