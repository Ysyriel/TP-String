#include "string.h"
#include <cstdio>
#include <cstdlib>

const size_t String::max_size = 100; //Définition de l'attribut static

//Constructeur par défaut
String::String(){
	size_=0;
	capacity_=0;
	tab_=new char[capacity_+1];
	tab_[0]='\0';
}

//Constructeur par copie
String::String (const String& str){ 
    size_=str.size_;
    capacity_=str.capacity_;
    tab_= new char[capacity_+1];
    for(unsigned int i=0; i<size_;i++)
	tab_[i]=str.tab_[i];
    tab_[size_]='\0';
}

//Renvoie un pointeur sur la chaîne de caractère 
const char* String::c_str() const{
    return tab_;
}

//Retourne la longueur de la string, en terme de bytes.
size_t String::size()const {
    return size_;
}
