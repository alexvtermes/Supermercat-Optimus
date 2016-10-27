/** @file Client.hh
    @brief Especificació de la classe Client
*/

#ifndef CLIENT_HH
#define CLIENT_HH

#ifndef NO_DIAGRAM       
#include <iostream>  
#include <vector>

#include "Cjt_productes.hh"
#include <string>
#include <queue>
#endif	

using namespace std;

/** @class Client

    @brief Representa un client. Es poden llegir i escriure els 
    seus atributs(del client)
    */


class Client {
    
    // Tipus de modul: dades
  
private:
  
    /** @brief Número de torn */
    int comprador_id; // = a num_torn;
    /** @brief Instant en què recull el tiquet */
    string instant_tiquet;
    /** @brief Nombre de productes diferents del client */
    int nombre_productes;
    /** @brief LLista de la compra del client*/
    vector<pair<string, int> > compra;
    /** @brief Número de caixa assignada del client*/
    int num_caixa;
    /** @brief Nombre total de productes que conté el client*/
    int nombre_total_productes;
    /** @brief Temps que el client està sent atès al caixer */
    int temps_caixer;
    /** @brief Últim instant en què el client ha acabat de ser atès */
    int temps_fi_caixer;
    /** @brief Primer instant en qué el client és atès */
    int temps_inici_caixer;
    
    /*
      Invariant de la representacio:
      -1 <= comprador_id <= L, on L és el nombre de clients que hi ha emmagatzemats al
      conjunt de clients
      -Un producte no pot apareixer més d'un cop en la llista de productes d'un client 
    */
    
public:
    
    //Constructores
    
    /** @brief Creadora per defecte
      \pre Cert
      \post El resultat és un client buit*/
    Client();
    
    //Destructores
    
    ~Client();

    //Consultores
    
    /** @brief Consultora que indica el número de torn(identificador de client)
        @pre cert
        @post Retorna el número de torn(identificador de client)
     */
    int consultar_comprador_id() const;

    /** @brief Consultora que indica el temps de caixer
        @pre cert
        @post Retorna el temps de caixer
     */
    int consultar_temps_caixer() const;
    
    /** @brief Consultora que indica el nombre total de productes del client
        @pre cert
        @post Retorna el nombre total de productes del client
     */
    int consultar_nombre_total_productes() const;
    
    /** @brief Consultora que indica l'últim instant en què el client està sent atès
        @pre cert
        @post Retorna l'últim instant en què el client està sent atès
     */
    int consultar_temps_fi_caixer() const;
    
    /** @brief Consultora que indica l'instant marcat pel tiquet
        @pre cert
        @post Retorna l'instant marcat pel tiquet
     */    
    string consultar_instant_tiquet() const;

     /** @brief Consultora que indica el nom dels productes amb les respectives quantitats de cada client
        @pre cert
        @post Retorna un vector de pair de string i int amb el nom dels productes i les respectives quantitats de cada client
     */   
    vector<pair<string, int> > retornar_compra() const;

    //Modificadores
    
    /** @brief Modificadora que assigna el número de caixa
        @pre cert
        @post Assigna al paràmetre implícit el número de caixa num
     */   
    void assignar_num_caixa(int& num);
    
    /** @brief Modificadora que actualitza el temps de fi de caixer
        @pre cert
        @post el paràmetre implícit és igual que abans però havent-li sumat n
     */   
    void actualitzar_temps_fi_caixer(int& n);

    /** @brief Modificadora que actualitza el temps de inici de caixer
        @pre cert
        @post el paràmetre implícit és igual que abans però havent-li sumat n
     */   
    void actualitzar_temps_inici_caixer(int& n);
        
    /** @brief Modificadora que assigna el temps de fi de caixer
        @pre cert
        @post Assigna n al temps de fi de caixer
     */   
    void assignar_temps_fi_caixer(int& n);
       
    /** @brief Modificadora que assigna el temps de inici de caixer
        @pre cert
        @post Assigna n al temps de inici de caixer
     */    
    void assignar_temps_inici_caixer(int& n);
    
    //Lectura

    /** @brief Operació de lectura\: \n
    Guarda els atributs del canal estàndard d'entrada al client
     \pre Hi ha preparats al canal estàndard d'entrada un enter comprador_id, una
     * seqüència de caràcters que indica l'instant de recollida del tiquet, un enter
     * <b> n </b> que indica el nombre de productes, i els <b> n </b> productes que ha comprat
     \post El paràmetre implícit passa a tenir els atributs llegits del canal estàndard d'entrada*/
    void llegir_client(Cjt_productes& conj_prod);
    
    //Escriptura
    
    /** @brief Operació d'escriptura\: \n
     * Escriu el client al canal estàndard de sortida  
     \pre Cert
     \post S'han escrit els atributs del paràmetre implícit al canal estàndard de sortida.*/
    void escriure_client();
    
};
#endif
