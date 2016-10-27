/** @file Cjt_productes.cc
    @brief Codi de la classe Cjt_productes
*/
#include "Cjt_productes.hh"


Cjt_productes::Cjt_productes(){}

Cjt_productes::~Cjt_productes(){}

void Cjt_productes::reset_conjunt_productes() {
    conjunt_productes.clear();
}

void Cjt_productes::afegir_producte(const Producte& p, string& producte_id){
    conjunt_productes.insert(make_pair(producte_id, p));
}

void Cjt_productes::cp_escriure_producte(string& nom) {
    map<string, Producte>::iterator it = conjunt_productes.find(nom);
    if (it == conjunt_productes.end()) cout << "error" << endl;
    else {
        cout << nom << ' ';
        conjunt_productes[nom].escriure_producte();
    }
}

int Cjt_productes::cp_consultar_temps_cobrament_producte(const string& nom){
    return conjunt_productes[nom].consultar_temps_cobrament();
}

string Cjt_productes::consultar_seccio_producte(string& s){
    return conjunt_productes[s].consultar_seccio();
}
