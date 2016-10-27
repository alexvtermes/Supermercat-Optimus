/** @file Producte.cc
    @brief Codi de la classe Producte
*/

#include "Producte.hh"


Producte::Producte(){
    preu_producte = -1;
    seccio = "-1";
    temps_cobrament = -1;
}

Producte::~Producte(){}

int Producte::consultar_temps_cobrament() const{
    return temps_cobrament;
}

string Producte::consultar_seccio() const{
    return seccio;
}

void Producte::llegir_producte(){
    double preu;
    string sec;
    int temps;
    cin >> preu >> sec >> temps;
    preu_producte = preu;
    seccio = sec;
    temps_cobrament = temps;
}

void Producte::escriure_producte(){
    cout << preu_producte << ' ' << seccio << ' ' << temps_cobrament << endl;
}
