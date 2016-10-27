/** @file Client.cc
    @brief Codi de la classe Client
*/


#include "Client.hh"


Client::Client(){
    comprador_id = -1;
    instant_tiquet = "no inicialitzat";
    nombre_productes = 0;
    num_caixa = -1;
    nombre_total_productes = 0;
    temps_caixer = 0;
    temps_fi_caixer = 0;
    temps_inici_caixer = 0;
}

Client::~Client(){}

int passar_a_int_client(string& hhmmss) {
    int hora, minuts, segons;
    hora = ((hhmmss[0]) - '0')*10 + (hhmmss[1] - '0');
    minuts = ((hhmmss[3]) - '0')*10 + (hhmmss[4] - '0');
    segons = ((hhmmss[6]) - '0')*10 + (hhmmss[7] - '0');
    return hora*3600 + minuts*60 + segons;
}

void Client::llegir_client(Cjt_productes& conj_prod){
    cin >> comprador_id >> instant_tiquet >> nombre_productes;
    compra = vector<pair<string, int> >(nombre_productes);
    pair<string, int> p;
    int aux;
    for (int i = 0; i < nombre_productes; ++i) {
	    cin >> p.first >> p.second;
	    compra[i] = p;
	    aux = conj_prod.cp_consultar_temps_cobrament_producte(p.first);
	    temps_caixer += (aux*p.second);
	    nombre_total_productes += p.second;
    }
}

int Client::consultar_nombre_total_productes() const{
    return nombre_total_productes;
}

int Client::consultar_comprador_id() const{
    return comprador_id;
}

void Client::assignar_num_caixa(int& num) {
    num_caixa = num;
}

void Client::assignar_temps_inici_caixer(int& n) {
    temps_inici_caixer = n;
}

void Client::actualitzar_temps_fi_caixer(int& n) {
    temps_fi_caixer += n;
}

int Client::consultar_temps_caixer() const{
    return temps_caixer;
}

void Client::assignar_temps_fi_caixer(int& n) {
    temps_fi_caixer = n;
}

string Client::consultar_instant_tiquet() const{
    return instant_tiquet;
}

void Client::actualitzar_temps_inici_caixer(int& n) {
    temps_inici_caixer += n;
}

int Client::consultar_temps_fi_caixer() const{
    return temps_fi_caixer;
}

void escriure_temps(int& temps) {
    if (temps < 60) {
        cout << "00:00:";
        if (temps < 10) cout << '0';
        cout << temps;
    }
    else if (temps < 3600) {
        cout << "00:";
        int res = temps%60;
        temps /= 60;
        if (temps < 10) cout << '0';
        cout << temps << ':';
        if (res < 10) cout << '0';
        cout << res;
    }
    else {
        int res_h = temps%3600;
        temps /= 3600;
        int res_min = res_h%60;
        if (temps < 10) cout << '0';
        cout << temps << ':';
        if (res_h/60 < 10) cout << '0';
        cout << res_h/60 << ':';
        if (res_min < 10) cout << '0';
        cout << res_min;
    }
}

vector<pair<string, int> > Client::retornar_compra() const{
    return compra;
}

void Client::escriure_client(){
    cout << comprador_id << ' ' << num_caixa << ' ';
    escriure_temps(temps_inici_caixer);
    cout << ' ';
    escriure_temps(temps_fi_caixer);
    cout << endl;
}
