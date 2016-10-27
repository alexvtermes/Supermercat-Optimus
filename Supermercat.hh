/** @file Supermercat.hh
    @brief Especificació de la classe Supermercat
*/

#ifndef SUPERMERCAT_HH
#define SUPERMERCAT_HH

#include "Cjt_productes.hh"
#include "Cjt_clients.hh"
#ifndef NO_DIAGRAM           
#include <vector>
#include <iostream>
#include <set>
#include <stack>
#include <algorithm>
#endif

/** @class Supermercat

    @brief Representa un supermercat, emmagatzemant els paràmetres d'aquest.
    
    */

    
class Supermercat {

    // Tipus de modul: dades
    
private:
    
    /** @brief Variables que indiquen el nombre de files, columnes i caixes del supermercat*/
    int files, columnes, caixes;
    /** @brief Estructura de dades que representa físicament les seccions del supermercat */
    vector < vector<set<string> > > seccions;
    /** @brief Objecte de la classe Cjt_productes que conté tots els productes del supermercat */
    Cjt_productes conj_prod;
    /** @brief Objecte de la classe Cjt_clients que conté tots els clients carregats*/
    Cjt_clients conj_clients;
    /** @brief Estructura de dades que simbolitza el conjunt de caixes del supermercat*/
    vector<queue<Client> > vcaixes;
    /** @brief Atribut que indica el màxim nombre de caixes*/
    static const int MAX_caixes = 20;
    /** @brief Atribut que indica el màxim nombre de files*/
    static const int MAX_files = 26;
    /** @brief Atribut que indica el màxim nombre de columnes*/
    static const int MAX_columnes = 9;
    
    /*
        Invariant de la representació:
        -0 < files <= MAX_files
        -0 < columnes <= MAX_columnes
    */

public:
  
    //Constructores
    
    /** @brief Creadora per defecte
      \pre cert
      \post el resultat és un supermercat buit */
    Supermercat();
    
    //Destructores
    
    ~Supermercat();    
    
    //Modificadores
    
    /** @brief Operació que reseteja el supermercat
        @pre cert
        @post el supermercat passa a ser un supermercat buit
     */
    void reset_supermercat();
    
    /** @brief Operació que reseteja el conjunt de clients
        @pre cert
        @post el conjunt de clients passa a ser un conjunt de clients buit
     */
    void reset_clients();
    
    // Lectura
    
    /** @brief Inicialitza el supermercat amb les dades preparades al canal estàndard d'entrada
      \pre El paràmetre implícit és buit i hi ha tres enters que indiquen files, columnes i caixes del
      *supermercat al canal estàndard d'entrada
      \post El resultat és un supermercat super amb els seus atributs inicialitzats*/
    void inicialitzar_supermercat();
    
    /** @brief Operació que càrrega la informació de vendes
      \pre cert
      \post el supermercat conté la informació de vendes carregada*/
    void carregar_info_vendes();
    
    //Escriptura
    
    /** @brief Operació d'escriptura: \n
     * Escriu al canal estàndard de sortida el camí òptim del client amb comprador_id
      \pre Cert
      \post S'ha escrit el camí òptim al canal estàndard de sortida*/
    void escriure_cami_optim(int& comprador_id);
    
    /** @brief Operació d'escriptura: \n
     * Escriu un producte al canal estàndard de sortida
      \pre Existeix el producte amb nom = producte_id
      \post S'han escrit els atributs del paràmetre implícit al canal estàndard
            de sortida*/
    void s_escriure_producte(string& nom);
    
    /** @brief Operació d'escriptura: \n
     * Escriu una secció al canal estàndard de sortida
      \pre 0 <= i <= MAX_files, 0 <= j <= MAX_columnes
      \post s'han escrit els atributs del paràmetre implícit al canal estàndard
	    de sortida*/
    void escriure_seccio(int& i, int& j);
    
    /** @brief Operació d'escriptura: \n
     * Escriu els temps mitjans de pagament dels clients segons les diferents
     * simulacions introduides
      \pre S'introdueixen <b> M </b> configuracions de caixes
      \post S'han escrit <b> M </b> temps mitjans de pagament dels clients al canal estàndard
      de sortida*/
    void escriure_simulacio_pagament();
    
    /** @brief Escriu la simulació de pagament de tots els clients
        @pre El conjunt de clients no és buit
        @post s'han escrit al canal estàndard de sortida els atributs de tots els clients
     */
};
#endif
