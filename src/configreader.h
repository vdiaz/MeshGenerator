#ifndef CFGREADER_H
#define CFGREADER_H

#include <libconfig.h++>

using namespace libconfig;
using namespace std;

class ConfigReader {

	public:
        	Config cfg;
		ConfigReader();
		Setting & getTreeGrowth();
		Setting & getGenerarMalla();
		Setting & getGuardarMalla();
		Setting & getCargarMalla();
		Setting & getMejorarMalla();
		Setting & getRefinarMalla();
		Setting & getDesrefinarMalla();
		Setting & getDistribuirHormona();
		Setting & getDeformarMalla();

};

#endif
