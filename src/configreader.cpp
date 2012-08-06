#include "configreader.h"
#define CONFIG_FILENAME "./config.cfg"

ConfigReader::ConfigReader() {
	cfg.readFile(CONFIG_FILENAME);
}

Setting & ConfigReader::getTreeGrowth() {
	Setting &root = cfg.getRoot();
	return root["TreeGrowthSimulator"];
}

Setting & ConfigReader::getGenerarMalla() {
	Setting &root = cfg.getRoot();
	return root["GenerarMalla"];
}

Setting & ConfigReader::getGuardarMalla() {
	Setting &root = cfg.getRoot();
	return root["GuardarMalla"];
}

Setting & ConfigReader::getCargarMalla() {
	Setting &root = cfg.getRoot();
	return root["CargarMalla"];
}

Setting & ConfigReader::getMejorarMalla() {
	Setting &root = cfg.getRoot();
	return root["MejorarMalla"];
}

Setting & ConfigReader::getRefinarMalla() {
	Setting &root = cfg.getRoot();
	return root["RefinarMalla"];
}

Setting & ConfigReader::getDesrefinarMalla() {
	Setting &root = cfg.getRoot();
	return root["DesrefinarMalla"];
}

Setting & ConfigReader::getDistribuirHormona() {
	Setting &root = cfg.getRoot();
	return root["DistribuirHormona"];
}

Setting & ConfigReader::getDeformarMalla() {
	Setting &root = cfg.getRoot();
	return root["DeformarMalla"];
}
