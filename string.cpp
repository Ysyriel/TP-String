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

String::String(char* c_string){ // Constructeur par c-string
	size_=length(c_string);
	capacity_=getCapacity(size_);
	tab_=new char[capacity_+1];
	for (unsigned int i=0; i<size_; i++){
			tab_[i]=c_string[i];
	}	
	tab_[size_]='\0';
}	
//Destructeurs

//Méthodes protégées
size_t String::length(const char* c){
	size_t len=0;
	while (c[len] != '\0' || len <= max_size){
		if (len=max_size){
			printf("Attention : la chaîne en paramètre est trop longue, et sera réduite à une longueur max_size valant %lu \n", max_size);
		}
		len++;
	}
	return len;
}

size_t String::getCapacity(size_t size){
	size=size*2;
	if (size>(max_size/2))
		return max_size;
	else
		return size;
}
