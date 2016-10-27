/** @file Cjt_clients.hh 
    @brief Especificació de la classe Cjt_clients
*/

#ifndef CJT_CLIENTS_HH
#define CJT_CLIENTS_HH

#include "Client.hh"
#ifndef NO_DIAGRAM       // això fa que el doxygen no inclogui      
#include <vector>	 // aquestes classes als diagrames modulars,
#include <algorithm>
#endif	

/** @class  Cjt_clients
 
      @brief Representa un conjunt de clients. Es poden consultar
      els seus elements, si ha estat inicialitzat.
*/

class Cjt_clients {
  
    // Tipus de modul: dades
  
private:
    
    /** @brief Conté el conjunt de clients */
    vector<Client> vclient;
    /** @brief Indica quin és el nombre de clients que hi ha al conjunt de clients */
    int num_clients;
    
    /*
        Invariant de la representacio: 
        - Un mateix client sols pot apareixer un cop en la càrrega
    */
    
public:

    //Constructores
    
    /** @brief Constructora per defecte
     \pre Cert
     \post El resultat és un Cjt_clients buit
      */
    Cjt_clients();
    
    //Destructores
    
    ~Cjt_clients();

     //Consultores

    /** @brief Operació que indica quants clients hi ha
        @pre cert
        @post Retorna el nombre de clients que hi ha
     */
    int consultar_num_clients() const;
    
    /** @brief Operació que indica si hi ha clients
        @pre cert
        @post Retorna cert si hi ha clients, si no, retorna fals
     */
    bool hiha_clients() const;
    
    /** @brief Operació que retorna el conjunt de clients
        @pre cert
        @post Retorna el conjunt de clients
     */
    vector<Client> consultar_vclient() const;
    
    /** @brief Operació que retorna la llista de la compra d'un client amb id comprador_id;
        @pre hi ha un client amb comprador_id al conjunt de clients
        @post Retorna la llista de la compra del client amb id comprador_id;
     */
    vector<pair<string, int> > retornar_llista_compra(int& comprador_id) const;
    
    /** @brief Calcula el temps de pagament de tots els clients
        @pre cert
        @post temps_total és la suma dels temps de pagament de tots els clients
    */
    void calcular_temps_total(int& temps_total);
    
    //Modificadores
    
    /** @brief Carrega la informació de vendes
     \pre Cert
     \post El paràmetre implícit conté la informació de vendes*/
    void carregar_info_vendes(Cjt_productes& conj_prod);
    
    /** @brief Operació per restaurar el vector de clients amb la última càrrega realitzada
        @pre cert
        @post el paràmetre implícit passa a ser vclient_aux
     */
    void assignar_vclient(vector<Client> vclient_aux);
    
    /** @brief Operació per resetejar el conjunt de clients
        @pre cert
        @post els atributs del paràmetre implícit estan buits (el vector de clients és buit, i el nombre de clients és 0)
     */
    void reset_conjunt_clients();
    
    /** @brief Operació per assignar les caixes i tractar el temps de cada client
        @pre x + y <= MAX_caixes
        @post tots els clients del conjunt tenen una caixa assignada i el seu temps tractat
     */
    void assignacio_caixes_i_temps(vector<queue<Client> >& vcaixes, int& x, int& y);
    
    //Escriptura
    
    /** @brief Operació que escriu la simulació de pagament de tots els clients del conjunt
        @pre cert
        @post s'ha escrit pel canal estàndard de sortida la simulació de pagament dels clients
    */
    void escriure_simulacio_pagament_client();
    
};
#endif
