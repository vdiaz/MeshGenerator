// generated 2006/8/2 16:01:43 CLT by chupacabrasx@amd64-3000.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to GUIDialogCambios.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "GUIDialogCambios.hh"

GUIDialogCambios::GUIDialogCambios(){
	//comboTipoVerificaciones->get_entry()->set_text("Verificacion por Nodos Vecinos");

	Setting & deformarMalla = cfg_reader->getDeformarMalla();

	if (deformarMalla.getType() == Setting::TypeGroup)
    {
        bool nodosVecinos, consLocal, sinVerificacion, setActive = true;
        deformarMalla.lookupValue("NodosVecinos", nodosVecinos);
        deformarMalla.lookupValue("ConsLocal", consLocal);
        deformarMalla.lookupValue("SinVerificacion", sinVerificacion);

        if (nodosVecinos) {
            comboTipoVerificaciones->set_active_text("Verificacion por Nodos Vecinos");
            setActive = false;
        }

        if (consLocal && setActive) {
            comboTipoVerificaciones->set_active_text("Consistencia local");
            setActive = false;
        }

        if (sinVerificacion && setActive) {
            comboTipoVerificaciones->set_active_text("Sin verificaciones");
        }
    }

	}

string GUIDialogCambios::getTipoVerificaciones(){
	return this->comboTipoVerificaciones->get_active_text();
	}

bool GUIDialogCambios::getHastaPrimeraInconsistencia(){
	return this->radiobuttonHastaPrimeraInconsistencia->get_active();
	}
bool GUIDialogCambios::getMoverLibremente(){
	return this->radiobuttonMoverLibremente->get_active();
	}

double GUIDialogCambios::getPorcentajeAMover(){
	return this->spinbuttonPorcenjateAMover->get_value();
	}

void GUIDialogCambios::on_comboTipoVerificaciones_changed(){
	if (comboTipoVerificaciones->get_active_text()=="Consistencia local"){
		this->spinbuttonPorcenjateAMover->set_sensitive(false);
		this->labelPorcentajeAMover->set_sensitive(false);
		this->radiobuttonHastaPrimeraInconsistencia->set_sensitive(true);
		this->radiobuttonMoverLibremente->set_sensitive(true);
		}
	else if (comboTipoVerificaciones->get_active_text()=="Sin verificaciones"){
		this->spinbuttonPorcenjateAMover->set_sensitive(true);
		this->labelPorcentajeAMover->set_sensitive(true);
		this->radiobuttonHastaPrimeraInconsistencia->set_sensitive(false);
		this->radiobuttonMoverLibremente->set_sensitive(false);
		}
	else if (comboTipoVerificaciones->get_active_text()=="Verificacion por Nodos Vecinos"){
		this->spinbuttonPorcenjateAMover->set_sensitive(true);
		this->labelPorcentajeAMover->set_sensitive(true);
		this->radiobuttonHastaPrimeraInconsistencia->set_sensitive(false);
		this->radiobuttonMoverLibremente->set_sensitive(false);
		}
	else
		return;
	}

void GUIDialogCambios::on_radiobuttonHastaPrimeraInconsistencia_toggled(){
	this->spinbuttonPorcenjateAMover->set_sensitive(false);
	this->labelPorcentajeAMover->set_sensitive(false);
	}

void GUIDialogCambios::on_radiobuttonMoverLibremente_toggled(){
	this->spinbuttonPorcenjateAMover->set_sensitive(true);
	this->labelPorcentajeAMover->set_sensitive(true);
	}
