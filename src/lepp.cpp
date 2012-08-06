#include "lepp.h"

vector<int> Lepp::findLepp(Malla *malla, int ind_cara){
	//asserts
    vector<int> lepp;
    int ind_cara_actual = ind_cara;
    int ind_arco_mas_largo_actual = malla->getArcoMasLargo(ind_cara_actual);
    lepp.push_back(ind_cara_actual);
    int ind_cara_siguiente, ind_arco_mas_largo_siguiente;
    while(true) {
        ind_cara_siguiente = malla->getSiguienteCara(ind_arco_mas_largo_actual,ind_cara_actual);
        if(ind_cara_siguiente == -1) {
            return lepp;
        }
        lepp.push_back(ind_cara_siguiente);
        ind_arco_mas_largo_siguiente = malla->getArcoMasLargo(ind_cara_siguiente);
        if(ind_arco_mas_largo_actual == ind_arco_mas_largo_siguiente) {
            return lepp;
        }
        ind_cara_actual = ind_cara_siguiente;
        ind_arco_mas_largo_actual = ind_arco_mas_largo_siguiente;
    }
    return lepp;
	}
