// generated 2007/4/6 16:01:19 CLT by chupacabrasx@amd64-3000.(none)
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/chupacabrasx/codeblocks/TreeGrowthSimulator/modeladorCambiosGL.glade
// for gtk 2.10.6 and gtkmm 2.10.6
//
// Please modify the corresponding derived classes in ./src/GUIDialogCambios.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
#include <gtkmmconfig.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
// #include <sigc++/compatibility.h>
// #include <sigc++-2.0/sigc++>
#define GMM_GTKMM_22_24(a,b) b
#else //gtkmm 2.2
#define GMM_GTKMM_22_24(a,b) a
#endif
#include "GUIDialogCambios_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/adjustment.h>

GUIDialogCambios_glade::GUIDialogCambios_glade(
)
{  GUIDialogCambios = this;
   gmm_data = new GlademmData(get_accel_group());
   cfg_reader = new ConfigReader();
   cancelbutton3 = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-cancel")));
   applybutton4 = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-apply")));
   label19 = Gtk::manage(new class Gtk::Label("Tipo de verificaciones: "));
   comboTipoVerificaciones = Gtk::manage(new class Gtk::ComboBoxText());
   hbox1 = Gtk::manage(new class Gtk::HBox(false, 0));

   Gtk::RadioButton::Group _RadioBGroup_radiobuttonHastaPrimeraInconsistencia;
   radiobuttonHastaPrimeraInconsistencia = Gtk::manage(new class Gtk::RadioButton(_RadioBGroup_radiobuttonHastaPrimeraInconsistencia, "Hasta primera inconsistencia"));
   radiobuttonMoverLibremente = Gtk::manage(new class Gtk::RadioButton(_RadioBGroup_radiobuttonHastaPrimeraInconsistencia, "Mover libremente"));
   labelPorcentajeAMover = Gtk::manage(new class Gtk::Label("% a mover por paso: "));

   Gtk::Adjustment *spinbuttonPorcenjateAMover_adj = Gtk::manage(new class Gtk::Adjustment(100, 0, 1000, 1, 10, 10));
   spinbuttonPorcenjateAMover = Gtk::manage(new class Gtk::SpinButton(*spinbuttonPorcenjateAMover_adj, 1, 0));
   label22 = Gtk::manage(new class Gtk::Label("Nº de pasos:"));

   Gtk::Adjustment *spinbuttonPasos_adj = Gtk::manage(new class Gtk::Adjustment(1, 1, 1000, 1, 10, 10));
   spinbuttonPasos = Gtk::manage(new class Gtk::SpinButton(*spinbuttonPasos_adj, 1, 0));
   table4 = Gtk::manage(new class Gtk::Table(2, 2, false));
   alignment3 = Gtk::manage(new class Gtk::Alignment(0.5, 0.5, 1, 1));
   label18 = Gtk::manage(new class Gtk::Label("<b>Propiedades</b>"));
   frame3 = Gtk::manage(new class Gtk::Frame());
   vbox2 = Gtk::manage(new class Gtk::VBox(false, 0));
   cancelbutton3->set_flags(Gtk::CAN_FOCUS);
   cancelbutton3->set_flags(Gtk::CAN_DEFAULT);
   cancelbutton3->set_relief(Gtk::RELIEF_NORMAL);
   applybutton4->set_flags(Gtk::CAN_FOCUS);
   applybutton4->set_flags(Gtk::CAN_DEFAULT);
   applybutton4->set_relief(Gtk::RELIEF_NORMAL);
   GUIDialogCambios->get_action_area()->property_layout_style().set_value(Gtk::BUTTONBOX_END);
   label19->set_alignment(0.5,0.5);
   label19->set_padding(0,0);
   label19->set_justify(Gtk::JUSTIFY_LEFT);
   label19->set_line_wrap(false);
   label19->set_use_markup(false);
   label19->set_selectable(false);
   {
      Setting & deformarMalla = cfg_reader->getDeformarMalla();

      if (deformarMalla.getType() == Setting::TypeGroup)
      {
         bool nodosVecinos, consLocal, sinVerificacion;
         deformarMalla.lookupValue("NodosVecinos", nodosVecinos);
         deformarMalla.lookupValue("ConsLocal", consLocal);
         deformarMalla.lookupValue("SinVerificacion", sinVerificacion);

         if (nodosVecinos)
            comboTipoVerificaciones->append("Verificacion por Nodos Vecinos");

         if (consLocal)
            comboTipoVerificaciones->append("Consistencia local");

         if (sinVerificacion)
            comboTipoVerificaciones->append("Sin verificaciones");
      }
   }
   hbox1->pack_start(*label19, Gtk::PACK_SHRINK, 0);
   hbox1->pack_start(*comboTipoVerificaciones);
   radiobuttonHastaPrimeraInconsistencia->set_sensitive(false);
   radiobuttonHastaPrimeraInconsistencia->set_flags(Gtk::CAN_FOCUS);
   radiobuttonHastaPrimeraInconsistencia->set_relief(Gtk::RELIEF_NORMAL);
   radiobuttonHastaPrimeraInconsistencia->set_mode(true);
   radiobuttonHastaPrimeraInconsistencia->set_active(false);
   radiobuttonMoverLibremente->set_sensitive(false);
   radiobuttonMoverLibremente->set_flags(Gtk::CAN_FOCUS);
   radiobuttonMoverLibremente->set_relief(Gtk::RELIEF_NORMAL);
   radiobuttonMoverLibremente->set_mode(true);
   radiobuttonMoverLibremente->set_active(false);
   labelPorcentajeAMover->set_alignment(0,0.5);
   labelPorcentajeAMover->set_padding(0,0);
   labelPorcentajeAMover->set_justify(Gtk::JUSTIFY_LEFT);
   labelPorcentajeAMover->set_line_wrap(false);
   labelPorcentajeAMover->set_use_markup(false);
   labelPorcentajeAMover->set_selectable(false);
   spinbuttonPorcenjateAMover->set_flags(Gtk::CAN_FOCUS);
   spinbuttonPorcenjateAMover->set_update_policy(Gtk::UPDATE_ALWAYS);
   spinbuttonPorcenjateAMover->set_numeric(true);
   spinbuttonPorcenjateAMover->set_digits(0);
   spinbuttonPorcenjateAMover->set_wrap(false);
   label22->set_alignment(0,0.5);
   label22->set_padding(0,0);
   label22->set_justify(Gtk::JUSTIFY_LEFT);
   label22->set_line_wrap(false);
   label22->set_use_markup(false);
   label22->set_selectable(false);
   spinbuttonPasos->set_flags(Gtk::CAN_FOCUS);
   spinbuttonPasos->set_update_policy(Gtk::UPDATE_ALWAYS);
   spinbuttonPasos->set_numeric(false);
   spinbuttonPasos->set_digits(0);
   spinbuttonPasos->set_wrap(false);
   table4->set_row_spacings(0);
   table4->set_col_spacings(10);
   table4->attach(*radiobuttonHastaPrimeraInconsistencia, 0, 1, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table4->attach(*radiobuttonMoverLibremente, 0, 1, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table4->attach(*labelPorcentajeAMover, 1, 2, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table4->attach(*spinbuttonPorcenjateAMover, 2, 3, 0, 1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table4->attach(*label22, 1, 2, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table4->attach(*spinbuttonPasos, 2, 3, 1, 2, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   alignment3->add(*table4);
   label18->set_alignment(0.5,0.5);
   label18->set_padding(0,0);
   label18->set_justify(Gtk::JUSTIFY_LEFT);
   label18->set_line_wrap(false);
   label18->set_use_markup(true);
   label18->set_selectable(false);
   frame3->set_shadow_type(Gtk::SHADOW_NONE);
   frame3->set_label_align(0,0.5);
   frame3->add(*alignment3);
   frame3->set_label_widget(*label18);
   vbox2->pack_start(*hbox1);
   vbox2->pack_start(*frame3);
   GUIDialogCambios->get_vbox()->set_homogeneous(false);
   GUIDialogCambios->get_vbox()->set_spacing(0);
   GUIDialogCambios->get_vbox()->pack_start(*vbox2);
   GUIDialogCambios->set_title("Cambios");
   GUIDialogCambios->set_modal(false);
   GUIDialogCambios->property_window_position().set_value(Gtk::WIN_POS_NONE);
   GUIDialogCambios->set_resizable(true);
   GUIDialogCambios->property_destroy_with_parent().set_value(false);
   GUIDialogCambios->set_has_separator(true);
   GUIDialogCambios->add_action_widget(*cancelbutton3, -6);
   GUIDialogCambios->add_action_widget(*applybutton4, -10);
   cancelbutton3->show();
   applybutton4->show();
   label19->show();
   comboTipoVerificaciones->show();
   hbox1->show();
   radiobuttonHastaPrimeraInconsistencia->show();
   radiobuttonMoverLibremente->show();
   labelPorcentajeAMover->show();
   spinbuttonPorcenjateAMover->show();
   label22->show();
   spinbuttonPasos->show();
   table4->show();
   alignment3->show();
   label18->show();
   frame3->show();
   vbox2->show();
   GUIDialogCambios->show();
   //comboTipoVerificaciones->get_entry()->signal_changed().connect(sigc::mem_fun(*this, &GUIDialogCambios_glade::on_comboTipoVerificaciones_changed), false);
   comboTipoVerificaciones->signal_changed().connect(sigc::mem_fun(*this, &GUIDialogCambios_glade::on_comboTipoVerificaciones_changed), false);
   radiobuttonHastaPrimeraInconsistencia->signal_toggled().connect(sigc::mem_fun(*this, &GUIDialogCambios_glade::on_radiobuttonHastaPrimeraInconsistencia_toggled), false);
   radiobuttonMoverLibremente->signal_toggled().connect(sigc::mem_fun(*this, &GUIDialogCambios_glade::on_radiobuttonMoverLibremente_toggled), false);
}

GUIDialogCambios_glade::~GUIDialogCambios_glade()
{  delete gmm_data;
}
