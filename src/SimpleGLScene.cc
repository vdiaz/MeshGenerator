// generated 2006/7/27 1:06:45 CLT by chupacabrasx@amd64-3000.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to SimpleGLScene.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "SimpleGLScene.hh"


///////////////////////////////////////////////////////////////////////////////
//
// OpenGL frame buffer configuration utilities.
//
///////////////////////////////////////////////////////////////////////////////

struct GLConfigUtil
{
  static void print_gl_attrib(const Glib::RefPtr<const Gdk::GL::Config>& glconfig,
                              const char* attrib_str,
                              int attrib,
                              bool is_boolean);

  static void examine_gl_attrib(const Glib::RefPtr<const Gdk::GL::Config>& glconfig);
};

//
// Print a configuration attribute.
//
void GLConfigUtil::print_gl_attrib(const Glib::RefPtr<const Gdk::GL::Config>& glconfig,
                                   const char* attrib_str,
                                   int attrib,
                                   bool is_boolean)
{
  int value;

  if (glconfig->get_attrib(attrib, value))
    {
      std::cout << attrib_str << " = ";
      if (is_boolean)
        std::cout << (value == true ? "true" : "false") << std::endl;
      else
        std::cout << value << std::endl;
    }
  else
    {
      std::cout << "*** Cannot get "
                << attrib_str
                << " attribute value\n";
    }
}

//
// Print configuration attributes.
//
void GLConfigUtil::examine_gl_attrib(const Glib::RefPtr<const Gdk::GL::Config>& glconfig)
{
  std::cout << "\nOpenGL visual configurations :\n\n";

  std::cout << "glconfig->is_rgba() = "
            << (glconfig->is_rgba() ? "true" : "false")
            << std::endl;
  std::cout << "glconfig->is_double_buffered() = "
            << (glconfig->is_double_buffered() ? "true" : "false")
            << std::endl;
  std::cout << "glconfig->is_stereo() = "
            << (glconfig->is_stereo() ? "true" : "false")
            << std::endl;
  std::cout << "glconfig->has_alpha() = "
            << (glconfig->has_alpha() ? "true" : "false")
            << std::endl;
  std::cout << "glconfig->has_depth_buffer() = "
            << (glconfig->has_depth_buffer() ? "true" : "false")
            << std::endl;
  std::cout << "glconfig->has_stencil_buffer() = "
            << (glconfig->has_stencil_buffer() ? "true" : "false")
            << std::endl;
  std::cout << "glconfig->has_accum_buffer() = "
            << (glconfig->has_accum_buffer() ? "true" : "false")
            << std::endl;

  std::cout << std::endl;

  print_gl_attrib(glconfig, "Gdk::GL::USE_GL",           Gdk::GL::USE_GL,           true);
  print_gl_attrib(glconfig, "Gdk::GL::BUFFER_SIZE",      Gdk::GL::BUFFER_SIZE,      false);
  print_gl_attrib(glconfig, "Gdk::GL::LEVEL",            Gdk::GL::LEVEL,            false);
  print_gl_attrib(glconfig, "Gdk::GL::RGBA",             Gdk::GL::RGBA,             true);
  print_gl_attrib(glconfig, "Gdk::GL::DOUBLEBUFFER",     Gdk::GL::DOUBLEBUFFER,     true);
  print_gl_attrib(glconfig, "Gdk::GL::STEREO",           Gdk::GL::STEREO,           true);
  print_gl_attrib(glconfig, "Gdk::GL::AUX_BUFFERS",      Gdk::GL::AUX_BUFFERS,      false);
  print_gl_attrib(glconfig, "Gdk::GL::RED_SIZE",         Gdk::GL::RED_SIZE,         false);
  print_gl_attrib(glconfig, "Gdk::GL::GREEN_SIZE",       Gdk::GL::GREEN_SIZE,       false);
  print_gl_attrib(glconfig, "Gdk::GL::BLUE_SIZE",        Gdk::GL::BLUE_SIZE,        false);
  print_gl_attrib(glconfig, "Gdk::GL::ALPHA_SIZE",       Gdk::GL::ALPHA_SIZE,       false);
  print_gl_attrib(glconfig, "Gdk::GL::DEPTH_SIZE",       Gdk::GL::DEPTH_SIZE,       false);
  print_gl_attrib(glconfig, "Gdk::GL::STENCIL_SIZE",     Gdk::GL::STENCIL_SIZE,     false);
  print_gl_attrib(glconfig, "Gdk::GL::ACCUM_RED_SIZE",   Gdk::GL::ACCUM_RED_SIZE,   false);
  print_gl_attrib(glconfig, "Gdk::GL::ACCUM_GREEN_SIZE", Gdk::GL::ACCUM_GREEN_SIZE, false);
  print_gl_attrib(glconfig, "Gdk::GL::ACCUM_BLUE_SIZE",  Gdk::GL::ACCUM_BLUE_SIZE,  false);
  print_gl_attrib(glconfig, "Gdk::GL::ACCUM_ALPHA_SIZE", Gdk::GL::ACCUM_ALPHA_SIZE, false);

  std::cout << std::endl;
}














SimpleGLScene::SimpleGLScene()
{
	this->frameActual=1;

	this->muestraArcos=false;
	this->muestraCaras=true;
	this->muestraConcentracion=true;
	this->muestraNodosDestacados=true;

	this-> xVentana=0;
	this-> yVentana=0;

	//Eventos para mover el modelo.
	add_events(Gdk::BUTTON1_MOTION_MASK    |
               Gdk::BUTTON3_MOTION_MASK    |
               Gdk::BUTTON_PRESS_MASK      |
               Gdk::BUTTON_RELEASE_MASK    |
               Gdk::VISIBILITY_NOTIFY_MASK);
	signal_motion_notify_event().connect(sigc::mem_fun(*this, &SimpleGLScene::on_motion_notify_event) );
	signal_button_press_event().connect(sigc::mem_fun(*this, &SimpleGLScene::on_button_press_event) );

  //
  // Configure OpenGL-capable visual.
  //

  Glib::RefPtr<Gdk::GL::Config> glconfig;

  // Try double-buffered visual
  glconfig = Gdk::GL::Config::create(Gdk::GL::MODE_RGB    |
                                     Gdk::GL::MODE_DEPTH  |
                                     Gdk::GL::MODE_DOUBLE);
  if (!glconfig)
    {
      std::cerr << "*** Cannot find the double-buffered visual.\n"
                << "*** Trying single-buffered visual.\n";

      // Try single-buffered visual
      glconfig = Gdk::GL::Config::create(Gdk::GL::MODE_RGB   |
                                         Gdk::GL::MODE_DEPTH);
      if (!glconfig)
        {
          std::cerr << "*** Cannot find any OpenGL-capable visual.\n";
          std::exit(1);
        }
    }

  // print frame buffer attributes.
  GLConfigUtil::examine_gl_attrib(glconfig);

  //
  // Set OpenGL-capability to the widget.
  //

  set_gl_capability(glconfig);
}

SimpleGLScene::~SimpleGLScene()
{
}

void SimpleGLScene::on_realize()
{
  // We need to call the base on_realize()
  Gtk::DrawingArea::on_realize();

  //
  // Get GL::Window.
  //

  Glib::RefPtr<Gdk::GL::Window> glwindow = get_gl_window();

  //
  // GL calls.
  //

  // *** OpenGL BEGIN ***
  if (!glwindow->gl_begin(get_gl_context()))
    return;

  static GLfloat light_position[] = {0.0, 0.0, 0.0, 1.0};
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_COLOR_MATERIAL);

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClearDepth(1.0);

  glViewport(0, 0, get_width(), get_height());

  /*glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, 1.0, 1.0, 100.0);*/

  /*glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 20.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);*/


  glwindow->gl_end();
  // *** OpenGL END ***
}

bool SimpleGLScene::on_configure_event(GdkEventConfigure* event)
{
  //
  // Get GL::Window.
  //

  Glib::RefPtr<Gdk::GL::Window> glwindow = get_gl_window();

  //
  // GL calls.
  //

  // *** OpenGL BEGIN ***
  if (!glwindow->gl_begin(get_gl_context()))
    return false;

  glViewport(0, 0, get_width(), get_height());

  glwindow->gl_end();
  // *** OpenGL END ***

  return true;
}

bool SimpleGLScene::on_expose_event(GdkEventExpose* event)
{
  //
  // Get GL::Window.
  //

  Glib::RefPtr<Gdk::GL::Window> glwindow = get_gl_window();

  //
  // GL calls.
  //

  // *** OpenGL BEGIN ***
  if (!glwindow->gl_begin(get_gl_context()))
    return false;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  	float camy=centrox+radioCamara*cos(phiCamara);
  	float camx=centroy+radioCamara*cos(thetaCamara)*sin(phiCamara);
  	float camz=centroz-radioCamara*sin(thetaCamara)*sin(phiCamara);

  	//cerr << "radio=" << radioCamara << " theta=" << thetaCamara << " phi=" << phiCamara << endl;
  	//cerr << "x=" << camx << " y=" << camy << " z=" << camz << endl;

	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
  	gluLookAt(camx, camy, camz,
            centrox, centroy, centroz,
            0.0, 1.0, 0.0);

  	glEnable (GL_POLYGON_OFFSET_FILL); 	//Necesario para permitir dibujar 2 poligonos
    glPolygonOffset (1.0, 1.0); 		//coplanares (Wireframe y poligono solido)

	if (this->muestraCaras==true)
		glCallList(frameActual);

	if (this->muestraArcos==true)
		glCallList(-1*frameActual);


  // Swap buffers.
  if (glwindow->is_double_buffered())
    glwindow->swap_buffers();
  else
    glFlush();

  glwindow->gl_end();
  // *** OpenGL END ***

  return true;
}


bool SimpleGLScene::redibujar()
{
    // force our program to redraw the entire clock.
    Glib::RefPtr<Gdk::Window> win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}

void SimpleGLScene::updateMalla(Malla* malla, bool updatePosCamara){
	assert(malla);

	vector<int>* nodosADestacar;
	if (muestraNodosDestacados && malla->getNodosDestacados()->size()>0)
		nodosADestacar=malla->getNodosDestacados();
	else
		nodosADestacar=NULL;

	float minx=numeric_limits<float>::max();
	float miny=numeric_limits<float>::max();
	float minz=numeric_limits<float>::max();
	float maxx=numeric_limits<float>::min();
	float maxy=numeric_limits<float>::min();
	float maxz=numeric_limits<float>::min();

  	Nodos *nds = malla->getNodos();
    Caras *crs = malla->getCaras();

  	Cara* c;
  	Nodo* n;

  	vector<int> ind_arcos;
  	vector<int> ind_nodos;
	glNewList(1, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.0,1.0,0.0);
	for (int i=0; i< crs->getNumCaras(); i++){
		c=crs->getCara(i);
		if (c!=NULL){
			ind_nodos=c->getNodos();
			glBegin(GL_POLYGON);
				for (int j=0; j<(int)ind_nodos.size(); j++){
					n=nds->getNodo(ind_nodos[j]);
					float x=n->getPunto()->getX();
					float y=n->getPunto()->getY();
					float z=n->getPunto()->getZ();
					if (x>maxx) maxx=x;
					if (y>maxy) maxy=y;
					if (z>maxz) maxz=z;
					if (x<minx) minx=x;
					if (y<miny) miny=y;
					if (z<minz) minz=z;
					if(muestraConcentracion)
						glColor3f(0.0,n->getConcentracion()/malla->getConcentracionMax(),1.0-n->getConcentracion()/malla->getConcentracionMax());
					else if(nodosADestacar!=NULL && find(nodosADestacar->begin(),nodosADestacar->end(),ind_nodos[j])!=nodosADestacar->end())
						glColor3f(0.0,0.0,1.0);
					else
						glColor3f(0.0,1.0,0.0);
					glNormal3f(n->getNormal()->getPunto().getX(),n->getNormal()->getPunto().getY(),n->getNormal()->getPunto().getZ());
					glVertex3f(x,y,z);
					}
  			glEnd();
			}
		}
  	glEndList();

	//Ahora hago la list del wireframe
	glNewList((unsigned int)-1, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0,0.0,0.0);
	for (int i=0; i< crs->getNumCaras(); i++){
		c=crs->getCara(i);
		if (c!=NULL){
			ind_nodos=c->getNodos();
			glBegin(GL_POLYGON);
				for (int j=0; j<(int)ind_nodos.size(); j++){
					n=nds->getNodo(ind_nodos[j]);
					float x=n->getPunto()->getX();
					float y=n->getPunto()->getY();
					float z=n->getPunto()->getZ();
					glNormal3f(n->getNormal()->getPunto().getX(),n->getNormal()->getPunto().getY(),n->getNormal()->getPunto().getZ());
					glVertex3f(x,y,z);
					}
  			glEnd();
			}
		}
  	glEndList();

	centrox=(minx+maxx)/2;
	centroy=(miny+maxy)/2;
	centroz=(minz+maxz)/2;

	float diametrox=maxx-minx;
	float diametroy=maxy-miny;
	float diametroz=maxz-minz;

	float diam=diametrox;
	if (diametroy>diam)
		diam=diametroy;
	if (diametroz>diam)
		diam=diametroz;

	float zNear = 1.0;
	float zFar = zNear+(4*diam);
	float aspectRatio=(float)get_width()/get_height();
	float anguloCamara=45.0;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(anguloCamara, aspectRatio, zNear, zFar);

	if (updatePosCamara){
		this->radioCamara=2*diam;
		this->thetaCamara=3 * PI/2;
		this->phiCamara= PI/2;
		}

	this->redibujar();
	}

void SimpleGLScene::updateAnimacion(int frame, Malla* malla){
	assert(frame>=2 && malla!=NULL);

	vector<int>* nodosADestacar;
	if (muestraNodosDestacados && malla->getNodosDestacados()->size()>0)
		nodosADestacar=malla->getNodosDestacados();
	else
		nodosADestacar=NULL;

	Nodos *nds = malla->getNodos();
    Caras *crs = malla->getCaras();

	vector<int> ind_nodos;

  	Cara* c;
  	Nodo* n;

	glNewList(frame, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.0,1.0,0.0);
	for (int i=0; i< crs->getNumCaras(); i++){
		c=crs->getCara(i);
		if (c!=NULL){
			ind_nodos=c->getNodos();
			glBegin(GL_POLYGON);
				for (int j=0; j<(int)ind_nodos.size(); j++){
					n=nds->getNodo(ind_nodos[j]);
					float x=n->getPunto()->getX();
					float y=n->getPunto()->getY();
					float z=n->getPunto()->getZ();
					if(muestraConcentracion)
						glColor3f(0.0,n->getConcentracion()/malla->getConcentracionMax(),1.0-n->getConcentracion()/malla->getConcentracionMax());
					else if(nodosADestacar!=NULL && find(nodosADestacar->begin(),nodosADestacar->end(),ind_nodos[j])!=nodosADestacar->end())
						glColor3f(0.0,0.0,1.0);
					else
						glColor3f(0.0,1.0,0.0);
					glNormal3f(n->getNormal()->getPunto().getX(),n->getNormal()->getPunto().getY(),n->getNormal()->getPunto().getZ());
					glVertex3f(x,y,z);
					}
  			glEnd();
			}
		}
  	glEndList();

	//Ahora hago la list del wireframe
	glNewList(-1*frame, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0,0.0,0.0);
	for (int i=0; i< crs->getNumCaras(); i++){
		c=crs->getCara(i);
		if (c!=NULL){
			ind_nodos=c->getNodos();
			glBegin(GL_POLYGON);
				for (int j=0; j<(int)ind_nodos.size(); j++){
					n=nds->getNodo(ind_nodos[j]);
					float x=n->getPunto()->getX();
					float y=n->getPunto()->getY();
					float z=n->getPunto()->getZ();
					glNormal3f(n->getNormal()->getPunto().getX(),n->getNormal()->getPunto().getY(),n->getNormal()->getPunto().getZ());
					glVertex3f(x,y,z);
					}
  			glEnd();
			}
		}
  	glEndList();

	}

void SimpleGLScene::startAnimacion(int milisegundos){
	signalTimeout= Glib::signal_timeout().connect(sigc::mem_fun(*this, &SimpleGLScene::updateFrame), milisegundos);
	}

void SimpleGLScene::stopAnimacion(){
	signalTimeout.disconnect();
	frameActual=1;
	this->redibujar();
	}

void SimpleGLScene::pauseAnimacion(){
	signalTimeout.disconnect();
	}

bool SimpleGLScene::updateFrame(){
	frameActual++;
	if (!glIsList(frameActual))
		frameActual=1;
	this->redibujar();
	return true;
	}

void SimpleGLScene::setMuestraArcos(bool valor){
	this->muestraArcos=valor;
	this->redibujar();
	}
void SimpleGLScene::setMuestraCaras(bool valor){
	this->muestraCaras=valor;
	this->redibujar();
	}
void SimpleGLScene::setMuestraConcentracion(bool valor){
	this->muestraConcentracion=valor;
	}

void SimpleGLScene::clear(){
	int frame=1;
	while (true){
		glDeleteLists(frame,1);
		frame++;
		if (!glIsList(frame))
			break;
		}
	this->redibujar();
	}

bool SimpleGLScene::on_button_press_event(GdkEventButton* event){
	this->xVentana=event->x;
	this->yVentana=event->y;
	return true;
	}

bool SimpleGLScene::on_motion_notify_event(GdkEventMotion* event){
	if (event->state & GDK_BUTTON3_MASK){
		this->radioCamara=this->radioCamara + (event->y - this->yVentana)/this->get_height();
		if (this->radioCamara < 0)
			this->radioCamara=0;
		}
	else if (event->state & GDK_BUTTON1_MASK){
		this->thetaCamara=this->thetaCamara - (event->x - this->xVentana)/this->get_width();
		this->phiCamara=this->phiCamara - (event->y - this->yVentana)/this->get_height();
		if (this->phiCamara >= PI)
			this->phiCamara = PI-0.000001;
		else if (this->phiCamara <= 0)
			this->phiCamara = 0.000001;
		}
	this->redibujar();
	return true;
	}
