/** @file Producte.hh
    @brief Especificació de la classe Producte
*/


#ifndef PRODUCTE_HH
#define PRODUCTE_HH

#ifndef NO_DIAGRAM       // això fa que el doxygen no inclogui      
#include <iostream>	 // aquestes classes als diagrames modulars,
#endif		

using namespace std;

/** @class Producte

    @brief Representa un producte. Es pot consultar l'atribut tems_cobrament,
           llegir i escriure els seus atributs
           */


class Producte{
  
    //Tipus de modul: dades
  
private:
  
    /** @brief Indica el preu del producte */
    double preu_producte;
    /** @brief Indica la secció on està localitzat el producte */
    string seccio;
    /** @brief Indica el temps de cobrament del producte */
    int temps_cobrament;
    
    /*
        Invariant de la representació:
        -el preu_producte és un nombre amb dos decimals
        -secció és una cadena de dos caracters
        -0 < temps_cobrament
    */
    
public:
  
    //Constructores
    
    /** @brief Creadora per defecte
    \pre Cert
    \post El resultat és un producte buit*/
    Producte();
    
    //Destructores
    
    ~Producte();
    
    //Consultores
    
    /** @brief Retorna el temps de cobrament;
    \pre Cert
    \post El resultat és el temps de cobrament del paràmetre implícit*/
    int consultar_temps_cobrament() const;
    
    /** @brief Operació que retorna la secció del del producte que representa el paràmetre implícit
        @pre cert
        @post Retorna la secció del del producte que representa el paràmetre implícit
     */
    string consultar_seccio() const;
    
    //Lectura
    
    /** @brief Operació de lectura\: \n Llegeix un producte del canal estàndard d'entrada
    \pre hi ha preparats al canal estàndard d'entrada una seqüència de caràcters,
           un double, un string i un enter no negatiu
    \post el paràmetre implícit passa a tenir els atributs llegits del canal 
            estàndard d'entrada*/
    void llegir_producte();
    
    //Escriptura
    
    /** @brief Operació d'escriptura\: \n S'escriu el producte al canal estàndard de sortida
    \pre cert
    \post s'han escrit els atributs del paràmetre implícit al canal estandard
            de sortida*/    
    void escriure_producte();
            
};
#endif
