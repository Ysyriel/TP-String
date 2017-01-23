#include <cstdio>
#include <cstdlib>

class String {
  protected :
	size_t size_; //taille effective de la String
    size_t capacity_; //capacité du tableau
    char* tab_; //"valeur" de la String (contenu : chaine de caractères)
    static const size_t max_size; //taille maximale du tableau/chaîne
    
  public : 
	//Constructeurs
    String(); //Constructeur par défaut
    String(const String& str); //Constructeur par copie 
	//String(size_t n, char t); //Constructeur à partir d'une c-string

	//Destructeurs
	//~String();
	
	//Méthodes publiques 
    const char* c_str() const; //Retourne un pointeur sur la string 
    size_t size() const; //Retourne la longueur de la string en terme de bytes 
    

};
