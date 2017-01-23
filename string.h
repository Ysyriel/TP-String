#include <cstdio>
#include <cstdlib>

class String {
  protected :
	// Attributs
	size_t size_; //taille effective de la String
    size_t capacity_; //capacité du tableau
    char* tab_; //"valeur" de la String (contenu : chaine de caractères)
    static const size_t max_size; //taille maximale du tableau/chaîne
    
    //Méthodes
    size_t String::length(const char* c);
    size_t String::getCapacity(size_t size);
    
  public : 
	//Constructeurs
    String(); //Constructeur par défaut
	//String(char* str_in); //Constructeur à partir d'une c-string

	//Destructeurs
	//~String();
	

    

};
