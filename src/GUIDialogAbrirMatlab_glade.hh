// generated 2006/11/5 8:06:31 CLST by chupacabrasx@amd64-3000.(none)
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/chupacabrasx/Projects/modeladorCambiosGL/modeladorCambiosGL.glade
// for gtk 2.8.20 and gtkmm 2.8.8
//
// Please modify the corresponding derived classes in ./src/GUIDialogAbrirMatlab.hh and./src/GUIDialogAbrirMatlab.cc

#ifndef _GUIDIALOGABRIRMATLAB_GLADE_HH
#  define _GUIDIALOGABRIRMATLAB_GLADE_HH


#if !defined(GLADEMM_DATA)
#define GLADEMM_DATA 
#include <gtkmm.h>

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

#include <gtkmm/dialog.h>
#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gtkmm/treeview.h>
#include <gtkmm/combo.h>
#include <gtkmm/table.h>
#include <gtkmm/box.h>

class GUIDialogAbrirMatlab_glade : public Gtk::Dialog
{  
        
        GlademmData *gmm_data;
public:
        class Gtk::Dialog * GUIDialogAbrirMatlab;
        class Gtk::Button * okbutton1;
        class Gtk::SpinButton * spinbuttonNumeroDeAnillos;
        class Gtk::SpinButton * spinbuttonPuntosPorAnillo;
        class Gtk::Label * label3;
        class Gtk::Label * label4;
        class Gtk::Label * label5;
        class Gtk::Combo * comboTipoMalla;
        class Gtk::Table * table1;
protected:
        
        GUIDialogAbrirMatlab_glade();
        
        ~GUIDialogAbrirMatlab_glade();
};
#endif
