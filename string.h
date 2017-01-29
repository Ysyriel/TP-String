#include <cstdio>
#include <cstdlib>

class String {
  protected :
	// Attributs
	size_t size_; //taille effective de la String
    size_t capacity_; //capacité du tableau
    char* tab_; //"valeur" de la String (contenu : chaine de caractères)
    static const size_t max_size_; //taille maximale du tableau/chaîne
    
    //Méthodes
    size_t length(const char* c);
    size_t capacity(size_t size);
    
    
  public : 
	//Constructeurs
    String(); //Constructeur par défaut
    String(const String& str); //Constructeur par copie 
	String(char* c_string); //Constructeur à partir d'une c-string

	//Destructeur
	~String();

	//Getters
	size_t capacity();
	size_t size();
	size_t length();
	size_t max_size();
	const char* c_str() const; //Retourne un pointeur sur la string 
	
	//Méthodes
	void resize(size_t n, char c=' '); //Change la taille de la string en n caractères, avec un caractere "par defaut" pour la surcharge des methodes quand il n'est pas spécifié
	bool empty() const; //Teste si la chaine de caractere est vide
    void clear (); //Efface le contenu  de la string 
    void reserve(size_t n); //Modifie la capacity_ d'un objet
    
    //Opérateurs
	String& operator=(const char* s); //Change la valeur de la chaine (objet) a partir d'une chaine de caractère (non objet : suite de caracteres) 
	//Finalement l'operateur =(char*) est très semblable au constructeur par c_string, sauf qu'il ne crée pas de nouvel objet.
	String& operator=(const String s); //Change la valeur de la chaine (objet) a partir d'une autre chaine de caractère (objet) 
	//De meme =(string) est très semblable au constructeur par copie à l'exception qu'il ne crée pas de nouvel objet.
	String& operator=(char c); //Change la valeur de la chaine (objet) a partir d'un caractere

	friend String operator+(const String& s, const char c); //Recrée un nouvel objet, concatenation de l'ancien objet et d'un caractere a la suite de celui-ci

};
