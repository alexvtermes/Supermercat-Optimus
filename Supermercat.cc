/** @file Supermercat.cc
    @brief Codi de la classe Supermercat
*/


#include "Supermercat.hh"
#include <vector>
#include <list>


Supermercat::Supermercat(){
    files = 0;
    columnes = 0;
    caixes = 1;
}

Supermercat::~Supermercat(){}

void Supermercat::reset_supermercat() {
    conj_prod.reset_conjunt_productes();
}

void Supermercat::reset_clients() {
    conj_clients.reset_conjunt_clients();
}

void Supermercat::inicialitzar_supermercat(){
    int f, c, ca;
    cin >> f >> c >> ca;
    this->files = f;
    this->columnes = c;
    this->caixes = ca;
    vcaixes = vector<queue<Client> >(caixes);
    seccions = vector<vector<set<string> > >(f, vector<set<string> > (c)); 
    int n;
    cin >> n;
    string producte_id;
    for (int i = 0; i < n; ++i) {
	    cin >> producte_id;
	    Producte p;
	    p.llegir_producte();
	    conj_prod.afegir_producte(p, producte_id);
	    string s = p.consultar_seccio();
	    int x = s[0] - 'A';
	    int y = s[1] - '1';
	    seccions[x][y].insert(producte_id);
    }
}

void Supermercat::carregar_info_vendes(){
    conj_clients.carregar_info_vendes(conj_prod);
}

int calcular_distancia(const string& s1, const string& s2) {
    return abs(s1[0] - s2[0]) + abs(s1[1] - s2[1]);
}

void permutacions_rec(int n, int l, vector<string>& v, vector<string>& v_min, int& min, string& ultima_seccio, int dist) {
  if (dist > min) return;
  if(l == n) {
    dist += calcular_distancia(v[n - 1] , ultima_seccio);
    if (dist < min) {
        min = dist;
        v_min = v;
    }
    else if (dist == min and v < v_min) v_min = v;
    return;
  }
    for(int i = l; i < n; i++) {
        int aux;
      swap(v[l], v[i]);
      if (l == 0) aux = calcular_distancia("A1", v[0]);
      else aux = calcular_distancia(v[l], v[l - 1]);
      permutacions_rec(n, l + 1, v, v_min, min, ultima_seccio, dist + aux);
      swap(v[l], v[i]);
    }
}

void permutacions(vector<string> v, vector<string>& v_min, int& min, string& ultima_seccio) {
  permutacions_rec(v.size(), 0, v, v_min, min, ultima_seccio, 0);
}

void Supermercat::escriure_cami_optim(int& comprador_id){
    if (comprador_id > conj_clients.consultar_num_clients() or not conj_clients.hiha_clients()) cout << "error" << endl;
    else {
        vector<pair<string, int> > compra = conj_clients.retornar_llista_compra(comprador_id);
        int size = compra.size();
        set<string> sseccions;
        string s;
        for(int i = 0; i < size; i++) {
	        s = conj_prod.consultar_seccio_producte(compra[i].first);
	        sseccions.insert(s);
        }
        set<string>::iterator it = sseccions.begin();
        string ultima_seccio(2, '0');
        ultima_seccio[0] = 'A';
        ultima_seccio[1] = columnes + '0';
        sseccions.erase("A1");
        sseccions.erase(ultima_seccio);
        it = sseccions.begin();
        int mida = sseccions.size();
        vector<string> v_act(mida);
        for (int i = 0; i < mida; ++i) {
            v_act[i] = *it;
            ++it;
        }
        vector<string> v_min(mida);
        int min = MAX_files*MAX_columnes + 1;
        if (not v_act.empty()) permutacions(v_act, v_min, min, ultima_seccio);
        else min = columnes - 1;
        cout << min << endl;
        cout << "A1" << ' ';
        if (min > 0) {
            for (int i = 0; i < v_min.size(); ++i) cout << v_min[i] << ' ';
            cout << ultima_seccio << ' ' << endl;
        }
        else cout << endl;
    }
}

void Supermercat::s_escriure_producte(string& nom){
    conj_prod.cp_escriure_producte(nom);
}

void Supermercat::escriure_seccio(int& i, int& j){
    if (i >= files or j >= columnes) cout << "error" << endl;
    else {
        set<string>::iterator it = seccions[i][j].begin();
        if (it == seccions[i][j].end()) cout << "seccio buida" << endl;
        else {
            while (it != seccions[i][j].end()) {
	            cout << *it << endl;
	            ++it;
            }
        }
    }
}

void escriure_temps_total(int& temps_total) {
    cout << (temps_total/3600)/10 << (temps_total/3600)%10 << ':';
    temps_total %= 3600;
    cout << (temps_total/60)/10 << (temps_total/60)%10 << ':';
    temps_total%= 60;
    cout << temps_total/10 << temps_total%10 << endl;
}


void Supermercat::escriure_simulacio_pagament(){
    int n, x, y;
    cin >> n;
    if (not conj_clients.hiha_clients()) cout << "error" << endl;
    else {
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            int temps_total = 0;
            vector<queue<Client> > vcaixes_aux = vcaixes;
            vector<Client> vclient_aux = conj_clients.consultar_vclient();
            conj_clients.assignacio_caixes_i_temps(vcaixes, x, y);
            conj_clients.escriure_simulacio_pagament_client();
            conj_clients.calcular_temps_total(temps_total);
            escriure_temps_total(temps_total);
            vcaixes = vcaixes_aux;
            conj_clients.assignar_vclient(vclient_aux);
        }
    }
}
