#include "string.h"
#include <cstdio>
#include <cstdlib>

const size_t String::max_size_ = 100; //Définition de l'attribut static

//Constructeurs
String::String(){ //Constructeur par défaut
	size_=0;
	capacity_=0;
	tab_=new char[capacity_+1];
	tab_[0]='\0';
}

String::String (const String& str){ //Constructeur par copie
    size_=str.size_;
    capacity_=str.capacity_;
    tab_= new char[capacity_+1];
    for(unsigned int i=0; i<size_;i++)
		tab_[i]=str.tab_[i];
	tab_[size_]='\0';
}

String::String(char* c_string){ //Constructeur par c-string
	size_=length(c_string);
	capacity_=capacity(size_);
	tab_=new char[capacity_+1];
	for (unsigned int i=0; i<size_; i++)
		tab_[i]=c_string[i];	
	tab_[size_]='\0';
}	

//Destructeurs
String::~String()
{
    delete[] tab_;
    tab_=nullptr;
}

//Getters
size_t String::capacity(){ 
	return capacity_;
}

size_t String::length(){
    return size_;
}

size_t String::max_size(){
    return max_size_;
}

size_t String::size(){
    return size_;
}

const char* String::c_str() const{ //Renvoie un pointeur sur la chaîne de caractère 
    return tab_;
}

//Méthodes protégées
size_t String::length(const char* s){ //Renvoie la longueur du tableau
	size_t len=0;
	while (s[len] != '\0'){
		if (len>= max_size_){
			printf("Attention : la longueur dépasse max_size, le tableau sera raccourci à max_size valant %lu \n", max_size_);
			break;
		}
		len++;
	}
	return len;
}

size_t String::capacity(size_t size){ //Renvoie la capacité du tableau
	size=size*2;
	if (size>(max_size_/2)) return max_size_;
	else return size;
}

//Méthodes publiques

bool String :: empty() const{ //Teste si la chaine de caractères est vide
    if (size_==0) return true;
    else return false;
	
}

void String::resize(size_t n, char c){ //Change la taille de la string en n caractères
    if (n > max_size_){ //Si la taille demandee excede celle de max_size, on la diminue a max_size
		n = max_size_;
		printf("Attention : la taille demandée dépasse max_size donc est raccourcie a max_size valant %lu\n", max_size_);
		n=max_size_;
    }
    if (n > size_){
		if (n < capacity_) { //Si la taille est inférieure a la capacité : pas de probleme on ajoute autant d'espaces qu'il le faut
			for (size_t i = size_; i<n; i++)
				tab_[i] = c;
			tab_[n+1] = '\0';
			size_ = n;
		} 
		else { //Sinon on declare un nouveau tableau (temporaire puisqu'il deviendra l'attribut tab_ de notre classe) de la taille adequate, on recopie les anciennes valeurs puis on supprime l'ancien tableau
			char* tmp = new char [capacity(n)+1];
			for (unsigned int i = 0; i<size_; i++) 
				tmp[i] = tab_[i];
			for (size_t i = size_; i<n; i++) 
				tmp[i]=c;
			tmp[n+1]='\0';
			delete[] tab_;
			tab_=tmp;
			size_=n;
			capacity_=n;
		}
	}
    else {   //On gère le cas ou n est plus petit que la taille actuelle de la chaine, en supprimant les caractères après n
		tab_[n+1]='\0';
		size_=n;
    }
}

void String::clear() { //Efface le contenu  de la string 
    tab_[0]='\0';
    size_=0;
}

void String::reserve (size_t n){ //Modifie la capacity_ d'un objet
    if (n>size_){ //ne fais rien si n<size
		if (n>max_size_){
			printf("Attention(reserve): ne peux pas allouer la capacité demandée. Rappel : max_size vaut %lu \n", max_size_);
			//Ne fais rien si la taille demandée est supérieure a max_size
		} 
		else { //On declare un nouveau tableau (temporaire puisqu'il deviendra l'attribut tab_ de notre classe) de la taille adequate, on recopie les anciennes valeurs puis on supprime l'ancien tableau
			char* tmp = new char[n+1];
			for (unsigned int i =0; i<=size_; i++) 
				tmp[i]=tab_[i];
			delete[] tab_;
			tab_=tmp;
			capacity_=n;
		}
    }
}

//Opérateurs =

String& String::operator=(const char* s){ //Change la valeur de la chaine (objet) a partir d'une chaine de caractères (non objet : suite de caracteres)
	size_=length(s);
	capacity_=capacity(size_);
	tab_=new char[capacity_+1];
	for (unsigned int i=0; i<size_; i++)
		tab_[i]=s[i];	
	tab_[size_]='\0';
	return *this;
}

String& String::operator=(const String str){ //Change la valeur de la chaine (objet) a partir d'une autre chaine de caractères (objet)
    size_=str.size_;
    capacity_=str.capacity_;
    tab_= new char[capacity_+1];
    for(unsigned int i=0; i<size_;i++)
		tab_[i]=str.tab_[i];
	tab_[size_]='\0';
	return *this;
}

String& String::operator=(char c){ //Change la valeur de la chaine (objet) a partir d'un caractere
	size_=1;
	capacity_=capacity(size_);
	tab_=new char[capacity_+1]; 
	tab_[0]=c;
	tab_[size_]='\0';
	return *this;
}

//Opérateurs +

String operator+(const String& s, char c){ //Recrée un nouvel objet, concatenation de l'ancien objet et d'un caractere a la suite de celui-ci
    String res;
    if(s.size_==s.max_size_){
		printf("Attention(operateur +) : l'ajout d'un caractere est impossible\n");
		res=s;
    }
    else{
		res.size_=s.size_+1;
		res.capacity_=res.capacity(res.size_);
		res.tab_=new char[res.capacity_+1];
	for(unsigned int i=0; i<s.size_; i++)
	    res.tab_[i]=s.tab_[i];
	res.tab_[s.size_]=c;
	res.tab_[s.size_+1]='\0';
    }
    return res;
}

String operator+(const String& s, const char* str){ //Recrée un nouvel objet, concatenation de l'ancien objet et d'une chaine de caractere (non objet) a la suite de celui-ci
//On traite ce cas de la meme facon que plus haut : on verifie que la chaine que l'on souhaite creer ne depasse pas la taille maximale tout d'abord   
    String res;
    int strlongueur = res.length(str); 
    if(s.size_+strlongueur>s.max_size_){
		printf("Attention (operateur +) : l'ajout de la chaine de caractere est impossible. Seul le membre de gauche est conserve.\n");
		res=s;
    } 
    else{
		res.size_=s.size_+strlongueur;
		res.capacity_=res.capacity(res.size_);
		res.tab_= new char[res.capacity_+1];
		for(unsigned int i=0; i<s.size_; i++)
			res.tab_[i]=s.tab_[i];
		for(int i=0; i<strlongueur; i++)
			res.tab_[i+s.size_]=str[i];
		res.tab_[res.size_+1]='\0';
	}
	return res;
}

String operator+(const String& gauche, const String& droite){ //Recrée un nouvel objet, concatenation de l'ancien objet et d'une chaine de caractere (objet) a la suite de celui-ci
//On traite ce cas de la meme facon que plus haut : on verifie que la chaine que l'on souhaite creer ne depasse pas la taille maximale tout d'abord   
    String res;
    if(gauche.size_+droite.size_>gauche.max_size_){
		printf("Attention (operateur +) : l'ajout de la chaine de caractere est impossible. Seul le membre de gauche est conserve.\n");
		res=gauche;
    } 
    else{
		res.size_=gauche.size_+droite.size_;
		res.capacity_=res.capacity(res.size_);
		res.tab_= new char[res.capacity_+1];
		for(unsigned int i=0; i<gauche.size_; i++)
			res.tab_[i]=gauche.tab_[i];
		for(unsigned int i=0; i<droite.size_; i++)
			res.tab_[i+gauche.size_]=droite.tab_[i];
		res.tab_[res.size_+1]='\0';
	}
	return res;
}
