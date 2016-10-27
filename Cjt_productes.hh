/** @file Cjt_productes.hh
    @brief Especificació de la classe Cjt_productes
*/


#ifndef SECCIO_HH
#define SECCIO_HH

#include "Producte.hh"
#ifndef NO_DIAGRAM       // això fa que el doxygen no inclogui      
#include <vector>	 // aquestes classes als diagrames modulars,
#include <map>
#include <set>
#endif	


/** @class Cjt_productes

    @brief Representa un conjunt de productes. Es poden consultar
    elements en particular(de tipus Producte) o escriure seccions,
    donats el nom de l'element o la secció corresponent
    */


class Cjt_productes {
  
    //Tipus de modul: dades
  
private:
  
    /** @brief Representa el conjunt dels productes de tot el supermercat */
    map<string, Producte> conjunt_productes;
    
     /*
        Invariant de la representació:
        -cada clau del map ha d'estar en alguna llista de strings del vector seccio
     */
     
public:

    //Constructores
    
    /** @brief Creadora per defecte
     \pre Cert
     \post El resultat es un Cjt de productes buit */
    Cjt_productes();
    
    //Destructores
    
    ~Cjt_productes();
    
    //Modificadores
    
    /** @brief Operació que reseteja el conjunt de productes
    \pre Cert
    \post El paràmetre implícit passa a ser buit */
    void reset_conjunt_productes();
    
    /** @brief Afegeix un producte al conjunt de productes
    \pre Cert
    \post S'ha afegit el producte p al paràmetre implícit */
    void afegir_producte(const Producte& p, string& producte_id);
    
    //Consultores
    
     /** @brief Retorna el temps de cobrament del producte amb producte_id = nom
     \pre existeix un producte al paràmetre implícit amb producte_id = nom
     \post el resultat és el temps de cobrament del producte_id = nom que conté
            el paràmetre implícit */    
    int cp_consultar_temps_cobrament_producte(const string& nom);
    
    /** @brief Operació que retorna la seccio d'un producte amb nom s
        @pre hi ha un producte amb nom s al conjunt de productes
        @post Retorna la secció del producte amb nom s
     */
    string consultar_seccio_producte(string& s);
    
    //Escriptura
    
    /** @brief Operació que escriu un producte amb nom s
        @pre hi ha un producte amb nom s al conjunt de productes
        @post Imprimeix els atributs del producte amb nom s pel canal estàndard de sortida
     */
    void cp_escriure_producte(string& nom);
    
};
#endif
