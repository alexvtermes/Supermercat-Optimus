/** @file Cjt_clients.cc
    @brief Codi de la classe Cjt_clients
*/

#include "Cjt_clients.hh"


Cjt_clients::Cjt_clients(){}

Cjt_clients::~Cjt_clients(){}

bool compara(Client c1, Client c2) {
    if (c1.consultar_comprador_id() < c2.consultar_comprador_id()) return true;
    return false;
}

void ordenar_vector(vector<Client>& vclient) {
    sort(vclient.begin(), vclient.end(), compara);
}

void Cjt_clients::reset_conjunt_clients() {
    vclient.clear();
    num_clients = 0;
}

int passar_a_int(string& hhmmss) {
    int hora, minuts, segons;
    hora = ((hhmmss[0]) - '0')*10 + (hhmmss[1] - '0');
    minuts = ((hhmmss[3]) - '0')*10 + (hhmmss[4] - '0');
    segons = ((hhmmss[6]) - '0')*10 + (hhmmss[7] - '0');
    return hora*3600 + minuts*60 + segons;
}

void Cjt_clients::carregar_info_vendes(Cjt_productes& conj_prod){
    cin >> num_clients;
    vclient = vector<Client>(num_clients);
    for (int i = 0; i < num_clients; ++i){
        vclient[i].llegir_client(conj_prod);
        string s = vclient[i].consultar_instant_tiquet();
        int n = passar_a_int(s);
        vclient[i].actualitzar_temps_inici_caixer(n);
        n += vclient[i].consultar_temps_caixer();
        vclient[i].actualitzar_temps_fi_caixer(n);
    }
    ordenar_vector(vclient);
}

void actualitzar_clients(vector<queue<Client> >& vcaixes, int& hora_actual, int& caixes_tancades) {
    int m = vcaixes.size();
    for (int i = m - 1; i >= caixes_tancades; --i) {
        if (not vcaixes[i].empty()) {
            bool fi = false;
            while (not fi and vcaixes[i].front().consultar_temps_fi_caixer() < hora_actual){
                 if (not fi) vcaixes[i].pop();
                 fi = vcaixes[i].empty();
            }
        }
    }
}

void Cjt_clients::assignacio_caixes_i_temps(vector<queue<Client> >& vcaixes, int& x, int& y) {
    int mida_caixes = vcaixes.size();
    int caixes_tancades = mida_caixes - x - y;
    for (int i = 0; i < num_clients; ++i) {
        int mida_compra = vclient[i].consultar_nombre_total_productes();
        int i_min = mida_caixes - 1;
        string s = vclient[i].consultar_instant_tiquet();
        int hora_actual = passar_a_int(s);
        actualitzar_clients(vcaixes, hora_actual, caixes_tancades);
        if (mida_compra <= 10) {
            for (int j = mida_caixes - 1; j >= caixes_tancades; --j) {
                if (vcaixes[j].size() < vcaixes[i_min].size()) i_min = j;   
            }
        }
        else {
            for (int j = mida_caixes - 1; j >= caixes_tancades + y; --j) {
                if (vcaixes[j].size() < vcaixes[i_min].size()) i_min = j;
            }
        }
        int caixa = i_min + 1;
        vclient[i].assignar_num_caixa(caixa);
        int temps_desp = mida_caixes - caixa;
        if (vcaixes[i_min].empty()) {
            vclient[i].actualitzar_temps_inici_caixer(temps_desp);
            int hora_sortida = temps_desp - 1;
            vclient[i].actualitzar_temps_fi_caixer(hora_sortida);
        }
        else {
            int hora_sortida = vcaixes[i_min].back().consultar_temps_fi_caixer();
            int hora_entrada = hora_sortida + 1;
            vclient[i].assignar_temps_inici_caixer(hora_entrada);
            hora_sortida = vclient[i].consultar_temps_caixer() + vcaixes[i_min].back().consultar_temps_fi_caixer();
            vclient[i].assignar_temps_fi_caixer(hora_sortida);
            
        }
        vcaixes[i_min].push(vclient[i]);
    }
}

void Cjt_clients::calcular_temps_total(int& temps_total) {
    for (int i = 0; i < num_clients; ++i) {
        string s1 = vclient[i].consultar_instant_tiquet();
        int n = passar_a_int(s1);
        int s2 = vclient[i].consultar_temps_fi_caixer();
        temps_total += (s2 - n + 1);
    }
}

void Cjt_clients::escriure_simulacio_pagament_client() {
    vector<Client> vclientaux = vclient;
    for (int i = 0; i < num_clients; ++i) vclient[i].escriure_client();
    vclient = vclientaux;
}

bool Cjt_clients::hiha_clients() const{
    return vclient.size();
}

int Cjt_clients::consultar_num_clients() const{
    return num_clients;
}

vector<pair<string, int> > Cjt_clients::retornar_llista_compra(int& comprador_id) const{
    return vclient[comprador_id - 1].retornar_compra();
}

vector<Client> Cjt_clients::consultar_vclient() const{
    return vclient;
}

void Cjt_clients::assignar_vclient(vector<Client> vclient_aux) {
    vclient = vclient_aux;
}
