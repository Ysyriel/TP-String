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
    size_t length(const char* c);
    size_t getCapacity(size_t size);
    
    
  public : 
	//Constructeurs
    String(); //Constructeur par défaut
    String(const String& str); //Constructeur par copie 
	String(char* c_string); //Constructeur à partir d'une c-string

	//Destructeur
	~String();

	//Méthodes
	void resize(size_t n); //Retaille la chaîne en n caractères

	//Méthodes publiques 
    const char* c_str() const; //Retourne un pointeur sur la string 
    size_t size() const; //Retourne la longueur de la string en terme de bytes 
    
};
