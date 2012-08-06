/**
@author Nicolas Silva Herrera
 */

#include "config.h"
#include "GUIVentanaPrincipal.hh"

#ifdef CARGAR_MATLAB
#include "GUIDialogAbrirMatlab.hh"
#endif

#if defined(GENERAR_CILINDRO) || defined(GENERAR_MEDULA)
#include "GUIDialogNuevaMalla.hh"
#endif

#if defined(DEFORMAR_ALG_CONSLOCAL) || defined(DEFORMAR_ALG_NODOSVECINOS) || defined(DEFORMAR_ALG_SINVERIFICACION)
#include "GUIDialogCambios.hh"
#include "deformar.h"
#endif

#if defined(REFINAR_ALG_LEPPDELAUNAY) || defined(REFINAR_ALG_LONGESTEDGE)
#include "GUIDialogRefinar.hh"
#include "refinar.h"
#endif

#if defined(DESREFINAR_CRITERIO_AREAMIN) || defined(DESREFINAR_CRITERIO_LARGOMIN)
#include "GUIDialogDesrefinar.hh"
#include "desrefinar.h"
#endif

#include "GUIDialogInformacion.hh"

#ifdef DISTRIB_HORMONA
#include "GUIDialogDistribuirHormona.hh"
#include "distribuirhormona.h"
#endif

#include "comando.h"
#include "generar.h"

#ifdef MEJORAR
#include "mejorar.h"
#endif

#include "guardar.h"

#include "informar.h"

#include <gtkmm.h>
#include <string>
#include <list>
#include <sstream>
#include <fstream>

GUIVentanaPrincipal::GUIVentanaPrincipal(){
	this->malla=NULL;
	this->velocidadAnimacion=1000;
    set_position(Gtk::WIN_POS_CENTER_ALWAYS);
	//simpleglscene = Gtk::manage(new class SimpleGLScene());
	simpleglscene=new SimpleGLScene();
	simpleglscene->setMuestraCaras(this->mostrar_caras1->get_active());
	simpleglscene->setMuestraArcos(this->mostrar_arcos1->get_active());
	//simpleglscene->set_size_request(800, 400);
	vboxDrawingArea->add(*simpleglscene);
	simpleglscene->show();
	}

void GUIVentanaPrincipal::on_nuevo1_activate(){
	//Comando* comando=new Generar(20,"/home/chupacabrasx/Desktop/medulafinal.txt",20,100,20);
#if defined(GENERAR_CILINDRO) || defined(GENERAR_MEDULA)
	GUIDialogNuevaMalla dialog;
	dialog.set_transient_for(*this);
	int result=dialog.run();
	if (result==Gtk::RESPONSE_OK){
		Comando *comando=NULL;
		if (dialog.getTipoFigura()=="Cilindro"){
			int tipo=10;
			int altura=dialog.getAltura();
			int radio=dialog.getRadio();
			int num_anillos=dialog.getNumeroDeAnillos();
			int num_puntos=dialog.getPuntosPorAnillo();
			int tipoMalla;
			if (dialog.getTipoMalla()=="Triangulos")
				tipoMalla=0;
			else if (dialog.getTipoMalla()=="Cuadrilateros")
				tipoMalla=1;
			else
				return;
			comando=new Generar(tipo, altura, radio, num_anillos, num_puntos, tipoMalla);
			}
        else if (dialog.getTipoFigura()=="A partir de Medula"){
			int tipo=20;
			string archivo=dialog.getMedulaArchivo();
			ifstream in(archivo.c_str());
			if (!in.good()) return;
			in.close();
			int radio=dialog.getRadio();
			int num_anillos=dialog.getNumeroDeAnillos();
			int num_puntos=dialog.getPuntosPorAnillo();
			comando=new Generar(tipo,archivo,radio,num_anillos,num_puntos);
			}
		else
			return;

		comando->execute();
		delete this->malla;
		this->malla=comando->getMalla();
		delete comando;

		simpleglscene->clear();
		simpleglscene->updateMalla(malla);

		this->escribirEnLog("Malla generada correctamente.");
		}
	else
		return;
#endif
	}

void GUIVentanaPrincipal::on_abrir1_activate(){
	Gtk::FileChooserDialog dialog("Abrir malla", Gtk::FILE_CHOOSER_ACTION_OPEN);
  	dialog.set_transient_for(*this);
	dialog.set_select_multiple(true);

  	//Add response buttons the the dialog:
  	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
  	dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

    Setting & cargarMalla = cfg_reader->getCargarMalla();
    bool value;

  	//Add filters, so that only certain file types can be selected:

    Gtk::FileFilter filter_geomview;
    filter_geomview.set_name("off (Geomview)");
    filter_geomview.add_pattern("*.off");
  	cargarMalla.lookupValue("Off", value);
  	if (value) {
        dialog.add_filter(filter_geomview);
  	}

    Gtk::FileFilter filter_matlab;
    filter_matlab.set_name("txt (Matlab)");
    filter_matlab.add_pattern("*.txt");
    cargarMalla.lookupValue("Matlab", value);
    if (value) {
        dialog.add_filter(filter_matlab);
    }

    Gtk::FileFilter filter_nxnynzu;
    filter_nxnynzu.set_name("txt (nx,ny,nz,u)");
    filter_nxnynzu.add_pattern("*.txt");
    cargarMalla.lookupValue("Xyzu", value);
    if (value) {
        dialog.add_filter(filter_nxnynzu);
    }

    Gtk::FileFilter filter_comsol_1;
    filter_comsol_1.set_name("cms_1 (comsol_1)");
    filter_comsol_1.add_pattern("*.cms_1");
    cargarMalla.lookupValue("Comsol", value);
    if (value) {
        dialog.add_filter(filter_comsol_1);
    }

  	//Show the dialog and wait for a user response:
  	int result = dialog.run();

	if (result==Gtk::RESPONSE_OK){
		Gtk::FileFilter* filtro=dialog.get_filter();
		Comando *comando = NULL;

		if (filtro->get_name()=="off (Geomview)"){
			int tipofiltro=0;
			list<string> filenames=dialog.get_filenames();
			comando = new Generar(tipofiltro, filenames);
			}
		else if (filtro->get_name()=="txt (Matlab)"){
			int tipofiltro=1;
			list<string> filenames=dialog.get_filenames();
#ifdef CARGAR_MATLAB
			GUIDialogAbrirMatlab dialogMatlab;
			dialogMatlab.set_transient_for(dialog);
			int resultDialogMatlab=dialogMatlab.run();
			if (resultDialogMatlab==Gtk::RESPONSE_OK){
				int numeroDeAnillos=dialogMatlab.getNumeroDeAnillos();
				int puntosPorAnillo=dialogMatlab.getPuntosPorAnillo();
				string strTipoMalla=dialogMatlab.getTipoMalla();
				int tipoMalla;
				if (strTipoMalla=="Triangulos")
					tipoMalla=0;
				else if (strTipoMalla=="Cuadrilateros")
					tipoMalla=1;
				else
					return;
				comando=new Generar(tipofiltro,filenames,numeroDeAnillos,puntosPorAnillo,tipoMalla);
				}
			else
				return;
#endif
			}
		else if (filtro->get_name()=="txt (nx,ny,nz,u)"){
			int tipofiltro=2;
			list<string> filenames=dialog.get_filenames();
			if (filenames.size()!=4){
				this->escribirEnLog("Se deben seleccionar 4 archivos para el formato nxnynzu.");
				return;
				}
			comando = new Generar(tipofiltro, filenames);
			}
		else if (filtro->get_name()=="cms_1 (comsol_1)"){
			int tipofiltro=3;
			list<string> filenames=dialog.get_filenames();
			comando = new Generar(tipofiltro, filenames);
			}
		else
			return;

		comando->execute();

		delete this->malla;
		this->malla=comando->getMalla();
		delete comando;

		simpleglscene->clear();
		simpleglscene->updateMalla(malla);

		this->escribirEnLog("Malla cargada correctamente.");
		}

	else
		return;
	}

void GUIVentanaPrincipal::on_guardar1_activate(){
	this->on_guardar_como1_activate();
	}

void GUIVentanaPrincipal::on_guardar_como1_activate(){
	if(this->malla == NULL) {
		this->escribirEnLog("La malla aun no esta seteada.");
        return;
    	}

	Gtk::FileChooserDialog dialog("Guardar malla", Gtk::FILE_CHOOSER_ACTION_SAVE);
  	dialog.set_transient_for(*this);

	//Add response buttons the the dialog:
  	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
  	dialog.add_button(Gtk::Stock::SAVE, Gtk::RESPONSE_OK);

    Setting & formatos = cfg_reader->getGuardarMalla();
    bool value;

  	//Add filters, so that only certain file types ncan be selected:

    Gtk::FileFilter filter_geomview;
    filter_geomview.set_name("off (Geomview)");
    filter_geomview.add_pattern("*.off");
  	formatos.lookupValue("Off", value);
  	if (value) {
        dialog.add_filter(filter_geomview);
  	}

    Gtk::FileFilter filter_nxnynzu;
    filter_nxnynzu.set_name("txt (nx,ny,nz,u)");
    filter_nxnynzu.add_pattern("*.txt");
    formatos.lookupValue("Xyzu", value);
  	if (value) {
        dialog.add_filter(filter_nxnynzu);
  	}

    Gtk::FileFilter filter_comsol_1;
    filter_comsol_1.set_name("cms_1 (comsol_1)");
    filter_comsol_1.add_pattern("*.cms_1");
    formatos.lookupValue("Comsol", value);
    if (value) {
        dialog.add_filter(filter_comsol_1);
    }

//    Gtk::FileFilter filter_mll;
//    filter_mll.set_name("mll (Debug)");
//    filter_mll.add_pattern("*.mll");
//    formatos.lookupValue("Debug", value);
//    if (value) {
//        dialog.add_filter(filter_mll);
//    }

	int result=dialog.run();

	if (result==Gtk::RESPONSE_OK){
		Gtk::FileFilter* filtro=dialog.get_filter();
		int tipofiltro;
		string filename;
		if (filtro->get_name()=="off (Geomview)"){
			tipofiltro=0;
			filename=dialog.get_filename()+".off";
			}
		else if (filtro->get_name()=="txt (nx,ny,nz,u)"){
			tipofiltro=2;
			filename=dialog.get_filename()+".txt";
			}
		else if (filtro->get_name()=="cms_1 (comsol_1)"){
			tipofiltro=3;
			filename=dialog.get_filename()+".cms_1";
			}
//		else if (filtro->get_name()=="mll (Debug)"){
//			tipofiltro=4;
//			filename=dialog.get_filename()+".mll";
//			}
		else
			return;

		Comando* comando = new Guardar(malla, tipofiltro,filename);
		comando->execute();
		delete comando;
		this->escribirEnLog("Malla guardada.");
		}
	else
		return;
	}

void GUIVentanaPrincipal::on_salir1_activate(){
	this->hide();
	}

void GUIVentanaPrincipal::on_cortar1_activate()
{
}

void GUIVentanaPrincipal::on_copiar1_activate()
{
}

void GUIVentanaPrincipal::on_pegar1_activate()
{
}

void GUIVentanaPrincipal::on_borrar1_activate(){
	simpleglscene->clear();
	delete malla;
	malla=NULL;
	this->escribirEnLog("Malla borrada.");
	}

void GUIVentanaPrincipal::on_distribuir_hormona1_activate(){
#ifdef DISTRIB_HORMONA
    if(this->malla == NULL) {
		this->escribirEnLog("La malla aun no esta seteada.");
        return;
    	}

    GUIDialogDistribuirHormona dialog;
    Comando *comando=NULL;
	int result=dialog.run();
	if (result==Gtk::RESPONSE_OK){
	    double gravitacional=dialog.getGravitacional();
	    double longitudinal=dialog.getLongitudinal();
	    double tangencial=dialog.getTangencial();
        comando=new DistribuirHormona(malla,simpleglscene,gravitacional,longitudinal,tangencial);
        }
    else
        return;

    comando->execute();
    simpleglscene->updateMalla(malla,false);
    delete comando;
    this->escribirEnLog("Hormonas distribuidas.");
#endif
    }

void GUIVentanaPrincipal::on_deformar1_activate(){
#if defined(DEFORMAR_ALG_CONSLOCAL) || defined(DEFORMAR_ALG_NODOSVECINOS) || defined(DEFORMAR_ALG_SINVERIFICACION)
	if(this->malla == NULL) {
		this->escribirEnLog("La malla aun no esta seteada.");
        return;
    	}

	GUIDialogCambios dialog;
	int result=dialog.run();
	if (result==Gtk::RESPONSE_APPLY){
		Comando* comando=NULL;
		if (dialog.getTipoVerificaciones()=="Consistencia local"){
			if (dialog.getHastaPrimeraInconsistencia()==true)
				comando=new Deformar(malla,1,-1);
			else if (dialog.getMoverLibremente()==true)
				comando=new Deformar(malla,1,dialog.getPorcentajeAMover()/100);
			else
				return;
			}
		else if (dialog.getTipoVerificaciones()=="Sin verificaciones")
			comando=new Deformar(malla,0,dialog.getPorcentajeAMover()/100);
		else if (dialog.getTipoVerificaciones()=="Verificacion por Nodos Vecinos")
			comando=new Deformar(malla,2,dialog.getPorcentajeAMover()/100);
		else
			return;

		//Dibujo la animacion en el visualizador.
		simpleglscene->clear();
		for(int i=0;i<dialog.spinbuttonPasos->get_value();i++){
			if (i!=0)
				comando->execute();
			simpleglscene->updateAnimacion(i+2,malla);
			cout << "Dibujado frame " << i+2 << endl;
			}
		comando->execute();
		simpleglscene->updateMalla(malla,false);

		delete comando;

		this->escribirEnLog("Deformamiento aplicado.");
		}
	else
		return;
#endif
	}

void GUIVentanaPrincipal::on_refinar1_activate(){
#if defined(REFINAR_ALG_LEPPDELAUNAY) || defined(REFINAR_ALG_LONGESTEDGE)
	if(this->malla == NULL) {
		this->escribirEnLog("La malla aun no esta seteada.");
        return;
    	}
	GUIDialogRefinar dialog;
	int result=dialog.run();

	if (result==Gtk::RESPONSE_APPLY){
		int tipoAlgRefinamiento;
		int tipoCriterio;
		double valorCriterio;

		if (dialog.isLeppDelaunay())
			tipoAlgRefinamiento=0;
		else if (dialog.isDelaunayLongestEdgeBisection())
			tipoAlgRefinamiento=1;
		else
			return;

		if (dialog.isAnguloMinimo()){
			tipoCriterio=0;
			valorCriterio=dialog.anguloMinimo();
			}
		else if (dialog.isAreaCara()){
			tipoCriterio=1;
			valorCriterio=dialog.areaCara();
			}
		else if (dialog.isLargoArcos()){
			tipoCriterio=2;
			valorCriterio=dialog.largoArcos();
			}
		else
			return;

		Comando* comando=new Refinar(malla,tipoAlgRefinamiento,tipoCriterio,valorCriterio);
		comando->execute();
		delete comando;

		simpleglscene->updateMalla(malla, false);

		this->escribirEnLog("Algoritmo refinamiento aplicado.");
		}
	else
		return;
#endif
	}

void GUIVentanaPrincipal::on_desrefinar1_activate(){
#if defined(DESREFINAR_CRITERIO_AREAMIN) || defined(DESREFINAR_CRITERIO_LARGOMIN)
	if(this->malla == NULL) {
		this->escribirEnLog("La malla aun no esta seteada.");
        return;
    	}

	GUIDialogDesrefinar dialog;
	int result=dialog.run();

	if (result==Gtk::RESPONSE_APPLY){
		int tipoAlgDesrefinamiento=0;
		int tipoCriterio;
		double valorCriterio;

		if (dialog.isAreaCara()){
			tipoCriterio=1;
			valorCriterio=dialog.areaCara();
			}
		else if (dialog.isLargoArcos()){
			tipoCriterio=2;
			valorCriterio=dialog.largoArcos();
			}
		else
			return;

		Comando* comando=new Desrefinar(malla,tipoAlgDesrefinamiento,tipoCriterio,valorCriterio);
		comando->execute();
		delete comando;

		simpleglscene->updateMalla(malla, false);

		this->escribirEnLog("Algoritmo desrefinamiento aplicado.");
		}
	else
		return;
#endif
	}

void GUIVentanaPrincipal::on_mejorar1_activate(){
#ifdef MEJORAR
	if(this->malla == NULL) {
        this->escribirEnLog("La malla aun no esta seteada.");
        return;
    	}

	Comando *cmd=new Mejorar(malla);
	cmd->execute();
	delete cmd;

	simpleglscene->updateMalla(malla, false);

	this->escribirEnLog("Algoritmo mejoramiento aplicado.");
#endif
	}

void GUIVentanaPrincipal::on_informacion1_activate(){
	if(this->malla == NULL) {
        this->escribirEnLog("La malla aun no esta seteada.");
        return;
    	}

	Informar* informar=new Informar(malla);
	informar->execute();

	GUIDialogInformacion dialog(informar);
	Gtk::Main::run(dialog);

	delete informar;

	}

void GUIVentanaPrincipal::on_mostrar_caras1_activate(){
	simpleglscene->setMuestraCaras(this->mostrar_caras1->get_active());
	}

void GUIVentanaPrincipal::on_mostrar_arcos1_activate(){
	simpleglscene->setMuestraArcos(this->mostrar_arcos1->get_active());
	}

void GUIVentanaPrincipal::on_mostrar_colores_segun_concentracion1_activate(){
	simpleglscene->setMuestraConcentracion(this->mostrar_colores_segun_concentracion1->get_active());
	}

void GUIVentanaPrincipal::on_enlentecer_animacion1_activate(){
	velocidadAnimacion=velocidadAnimacion+50;
	simpleglscene->pauseAnimacion();
	simpleglscene->startAnimacion(velocidadAnimacion);
	}

void GUIVentanaPrincipal::on_detener_animacion1_activate(){
	simpleglscene->stopAnimacion();
	}

void GUIVentanaPrincipal::on_pausar_animacion1_activate(){
	simpleglscene->pauseAnimacion();
	}

void GUIVentanaPrincipal::on_iniciar_animacion1_activate(){
	simpleglscene->startAnimacion(velocidadAnimacion);
	}

void GUIVentanaPrincipal::on_apurar_animacion1_activate(){
	velocidadAnimacion=velocidadAnimacion-50;
	if (velocidadAnimacion<50)
		velocidadAnimacion=50;
	simpleglscene->pauseAnimacion();
	simpleglscene->startAnimacion(velocidadAnimacion);
	}

void GUIVentanaPrincipal::on_acerca_de1_activate(){
	Gtk::AboutDialog dialog;
	dialog.set_transient_for(*this);
	dialog.set_name("Tree Growth Simulator");
	dialog.set_version("3.1");
	list<string> autores;
	autores.push_back("Nicolás Silva");
	autores.push_back("Ricardo Medina (Version antigua)");
	dialog.set_authors(autores);
	dialog.set_comments("Software modelador del crecimiento de arboles usando mallas geometricas.");
	dialog.run();
	}

void GUIVentanaPrincipal::on_toolbuttonNuevo_clicked(){
	this->on_nuevo1_activate();
	}

void GUIVentanaPrincipal::on_toolbuttonAbrir_clicked(){
	this->on_abrir1_activate();
	}

void GUIVentanaPrincipal::on_toolbuttonGuardar_clicked(){
	this->on_guardar1_activate();
	}

void GUIVentanaPrincipal::escribirEnLog(string texto){
	time_t tim=time(NULL);
	tm *time=localtime(&tim);
	int hora=time->tm_hour;
	int minuto=time->tm_min;
	int segundo=time->tm_sec;

	string logviejo=textviewLog->get_buffer()->get_text();

	stringstream stream;
	stream << "[" << hora << ":" << minuto << ":" << segundo << "] " << texto << endl << logviejo;

	textviewLog->get_buffer()->set_text(stream.str());
	}

GUIVentanaPrincipal::~GUIVentanaPrincipal(){
	delete simpleglscene;
	delete malla;
	}
