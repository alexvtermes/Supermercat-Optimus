/** @file program.cc
    @brief Implementació del programa principal
*/

#include "Supermercat.hh"
//#include "Cjt_clients.hh"

#ifndef NO_DIAGRAM       // això fa que el doxygen no inclogui      
#include <iostream>	 // aquestes classes als diagrames modulars,
#endif		

using namespace std;

int main() {
    Supermercat super;
    string s;
    cin >> s;
    while (s != "sortir") {
	    if (s == "inicialitzar") {
	        super.reset_supermercat();
	        super.reset_clients();
	        super.inicialitzar_supermercat();
	    }
	    else if (s == "carregar") {
	        super.reset_clients();
	        super.carregar_info_vendes();
	    }
	    else if (s == "informacio") {
	        string nom;
	        cin >> nom;
	        cout << "informacio " << nom << ':' << endl;
	        super.s_escriure_producte(nom);
	        cout << endl;
	    }
	    else if (s == "productes") {
	        cin >> s;
	        int primer = s[0] - 'A';
	        int segon = s[1] - '1';
	        cout << "productes " << s << ':' << endl;
	        super.escriure_seccio(primer, segon);
	        cout << endl;
	    }
	    else if (s == "millor") {
	        cin >> s;
	        int comprador_id;
	        cin >> comprador_id;
	        cout << "millor cami " << comprador_id << ':' << endl;
	        super.escriure_cami_optim(comprador_id);
	        cout << endl;
	    }
	    else if (s == "simular") {
	        cin >> s;
	        cout << "simular pagament:" << endl;
	        super.escriure_simulacio_pagament();
	        cout << endl;
	    }
	    cin >> s;
	}
}
