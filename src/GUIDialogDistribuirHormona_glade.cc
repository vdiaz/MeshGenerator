// generated 2007/4/27 18:35:14 CLT by chupacabrasx@amd64-3000.(none)
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/chupacabrasx/codeblocks/TreeGrowthSimulator/TreeGrowthSimulator.glade
// for gtk 2.10.11 and gtkmm 2.10.8
//
// Please modify the corresponding derived classes in ./src/GUIDialogDistribuirHormona.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
#include <gtkmmconfig.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#define GMM_GTKMM_22_24(a,b) b
#else //gtkmm 2.2
#define GMM_GTKMM_22_24(a,b) a
#endif //
#include "GUIDialogDistribuirHormona_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/adjustment.h>

GUIDialogDistribuirHormona_glade::GUIDialogDistribuirHormona_glade(
)
{  GUIDialogDistribuirHormona = this;
   gmm_data = new GlademmData(get_accel_group());
   cancelbutton6 = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-cancel")));
   okbutton6 = Gtk::manage(new class Gtk::Button(Gtk::StockID("gtk-ok")));
   label47 = Gtk::manage(new class Gtk::Label("Factor Gravitacional "));
   label48 = Gtk::manage(new class Gtk::Label("Factor Longitudinal"));
   label49 = Gtk::manage(new class Gtk::Label("Factor Tangencial"));
   
   Gtk::Adjustment *spinbuttonGravitacional_adj = Gtk::manage(new class Gtk::Adjustment(0.5, 0, 100, 0.0500000007451, 10, 10));
   spinbuttonGravitacional = Gtk::manage(new class Gtk::SpinButton(*spinbuttonGravitacional_adj, 1, 2));
   
   Gtk::Adjustment *spinbuttonLongitudinal_adj = Gtk::manage(new class Gtk::Adjustment(0.300000011921, 0, 100, 0.0500000007451, 10, 10));
   spinbuttonLongitudinal = Gtk::manage(new class Gtk::SpinButton(*spinbuttonLongitudinal_adj, 1, 2));
   
   Gtk::Adjustment *spinbuttonTangencial_adj = Gtk::manage(new class Gtk::Adjustment(0.20000000298, 0, 100, 0.0500000007451, 10, 10));
   spinbuttonTangencial = Gtk::manage(new class Gtk::SpinButton(*spinbuttonTangencial_adj, 1, 2));
   table9 = Gtk::manage(new class Gtk::Table(2, 2, false));
   alignment11 = Gtk::manage(new class Gtk::Alignment(0.5, 0.5, 1, 1));
   label46 = Gtk::manage(new class Gtk::Label("Factores de Distribucion"));
   frame11 = Gtk::manage(new class Gtk::Frame());
   cancelbutton6->set_flags(Gtk::CAN_FOCUS);
   cancelbutton6->set_flags(Gtk::CAN_DEFAULT);
   cancelbutton6->set_relief(Gtk::RELIEF_NORMAL);
   okbutton6->set_flags(Gtk::CAN_FOCUS);
   okbutton6->set_flags(Gtk::CAN_DEFAULT);
   okbutton6->set_relief(Gtk::RELIEF_NORMAL);
   GUIDialogDistribuirHormona->get_action_area()->property_layout_style().set_value(Gtk::BUTTONBOX_END);
   label47->set_alignment(0,0.5);
   label47->set_padding(0,0);
   label47->set_justify(Gtk::JUSTIFY_LEFT);
   label47->set_line_wrap(false);
   label47->set_use_markup(false);
   label47->set_selectable(false);
   label48->set_alignment(0,0.5);
   label48->set_padding(0,0);
   label48->set_justify(Gtk::JUSTIFY_LEFT);
   label48->set_line_wrap(false);
   label48->set_use_markup(false);
   label48->set_selectable(false);
   label49->set_alignment(0,0.5);
   label49->set_padding(0,0);
   label49->set_justify(Gtk::JUSTIFY_LEFT);
   label49->set_line_wrap(false);
   label49->set_use_markup(false);
   label49->set_selectable(false);
   spinbuttonGravitacional->set_flags(Gtk::CAN_FOCUS);
   spinbuttonGravitacional->set_update_policy(Gtk::UPDATE_ALWAYS);
   spinbuttonGravitacional->set_numeric(true);
   spinbuttonGravitacional->set_digits(2);
   spinbuttonGravitacional->set_wrap(false);
   spinbuttonLongitudinal->set_flags(Gtk::CAN_FOCUS);
   spinbuttonLongitudinal->set_update_policy(Gtk::UPDATE_ALWAYS);
   spinbuttonLongitudinal->set_numeric(true);
   spinbuttonLongitudinal->set_digits(2);
   spinbuttonLongitudinal->set_wrap(false);
   spinbuttonTangencial->set_flags(Gtk::CAN_FOCUS);
   spinbuttonTangencial->set_update_policy(Gtk::UPDATE_ALWAYS);
   spinbuttonTangencial->set_numeric(true);
   spinbuttonTangencial->set_digits(2);
   spinbuttonTangencial->set_wrap(false);
   table9->set_row_spacings(0);
   table9->set_col_spacings(0);
   table9->attach(*label47, 0, 1, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table9->attach(*label48, 0, 1, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table9->attach(*label49, 0, 1, 2, 3, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table9->attach(*spinbuttonGravitacional, 1, 2, 0, 1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table9->attach(*spinbuttonLongitudinal, 1, 2, 1, 2, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table9->attach(*spinbuttonTangencial, 1, 2, 2, 3, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   alignment11->add(*table9);
   label46->set_alignment(0.5,0.5);
   label46->set_padding(0,0);
   label46->set_justify(Gtk::JUSTIFY_LEFT);
   label46->set_line_wrap(false);
   label46->set_use_markup(true);
   label46->set_selectable(false);
   frame11->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
   frame11->set_label_align(0,0.5);
   frame11->add(*alignment11);
   frame11->set_label_widget(*label46);
   GUIDialogDistribuirHormona->get_vbox()->set_homogeneous(false);
   GUIDialogDistribuirHormona->get_vbox()->set_spacing(0);
   GUIDialogDistribuirHormona->get_vbox()->pack_start(*frame11);
   GUIDialogDistribuirHormona->set_title("Distribuir Hormona");
   GUIDialogDistribuirHormona->set_modal(false);
   GUIDialogDistribuirHormona->property_window_position().set_value(Gtk::WIN_POS_NONE);
   GUIDialogDistribuirHormona->set_resizable(true);
   GUIDialogDistribuirHormona->property_destroy_with_parent().set_value(false);
   GUIDialogDistribuirHormona->set_has_separator(true);
   GUIDialogDistribuirHormona->add_action_widget(*cancelbutton6, -6);
   GUIDialogDistribuirHormona->add_action_widget(*okbutton6, -5);
   cancelbutton6->show();
   okbutton6->show();
   label47->show();
   label48->show();
   label49->show();
   spinbuttonGravitacional->show();
   spinbuttonLongitudinal->show();
   spinbuttonTangencial->show();
   table9->show();
   alignment11->show();
   label46->show();
   frame11->show();
   GUIDialogDistribuirHormona->show();
}

GUIDialogDistribuirHormona_glade::~GUIDialogDistribuirHormona_glade()
{  delete gmm_data;
}
