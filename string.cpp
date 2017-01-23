#include "string.h"
#include <cstdio>
#include <cstdlib>

const size_t String::max_size = 100; //Définition de l'attribut static

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
	for (unsigned int i=0; i<size_; i++){
			tab_[i]=c_string[i];
	}	
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

//Méthodes protégées
size_t String::length(const char* s){ //Renvoie la longueur du tableau
	size_t len=0;
	while (s[len] != '\0'){
		if (len>= max_size){
			printf("Attention : la longueur dépasse max_size, le tableau sera raccourci à max_size valant %lu \n", max_size);
			break;
		}
		len++;
	}
	return len;
}

size_t String::capacity(size_t size){ //Renvoie la capacité du tableau
	size=size*2;
	if (size>(max_size/2))
		return max_size;
	else
		return size;
}

//Méthodes publiques
const char* String::c_str() const{ //Renvoie un pointeur sur la chaîne de caractère 
    return tab_;
}

size_t String::size() const{ //Retourne la longueur de la string, en terme de bytes
    return size_;
}

bool String :: empty() const{ //Teste si la chaine de caractères est vide
    if (size_==0){
	return true;
    }
    else {
	return false;
    }
}
