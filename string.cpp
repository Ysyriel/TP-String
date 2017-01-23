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
	if (size>(max_size_/2))
		return max_size_;
	else
		return size;
}

//Méthodes publiques

bool String :: empty() const{ //Teste si la chaine de caractères est vide
    if (size_==0){
	return true;
    }
    else {
	return false;
	}
}

void String::resize(size_t n){ //Change la string en n caractères
    if (n > max_size_){
	printf("Warning (String::resize): requied size exceed MAX_SIZE "
	       "and it will be shortened to MAX_SIZE which is %zu\n",
	       max_size_);
	n = max_size_;
	printf("Attention : la taille du tableau dépasse max_size donc il est raccourci a la taille max_size valant %d", max_size_);
	n=max_size_;
    }
    if (n > size_){
	if (n < capacity_) {
	    for (size_t i = size_; i<n; i++)
		tab_[i] = ' ';
	    tab_[n] = '\0';
	    size_ = n;
	} else {
	    char* nptr = new char [capacity(n)+1];
	    for (unsigned int i = 0; i<size_; i++)
		nptr[i] = tab_[i];
	    for (size_t i = size_; i<n; i++)
		nptr[i]=' ';
	    nptr[n]='\0';
	    delete[] tab_;
	    tab_=nptr;
	    size_=n;
	}
    } else {
		tab_[n]='\0';
		size_=n;
    }

}

void String::clear() {
    tab_[0]='\0';
    size_=0;
}

void String::reserve (size_t n){ 
    if (n>size_){//ne fais rien sinon
		if (n>max_size_){
			printf("Attention(reserve): ne peux pas allouer la capacité demandée\n");
			//Ne fais rien si la taille demandée est supérieure a max_size
		} 
		else {
			capacity_=n;
		}
    }
}

//Opérateurs
String operator=(char c){ //Opérateur=(char)
	size_= 1;
	capacity_= capacity(size_);
	data_= new char[capacity_+1]; 
	data_[0]= c;
	data_[size_] = '\0';
	return *this;
}

String operator+(const String& lhs, const char* rhs){ //Opérateur+(char*) à droite
    String result;
    int rhs_length = result.length(rhs); 
    //In case that string is super long 
    if (lhs.length()+rhs_length > String::max_size_) {
	printf("Attention : strings concatenation size "
	       "out of range, taking only left hand side\n");
	result=lhs;
	return result;
    } else {
	result.size_=lhs.length()+rhs_length;
	result.capacity_=result.capacity(result.size_);
	result.tab_= new char[result.capacity_ + 1];
	for (unsigned int i=0; i < lhs.length(); i++)
	    result.tab_[i]=lhs.tab_[i];
	for (int i=0; i < rhs_length; i++)
	    result.tab_[i+lhs.length()]=rhs[i];
	result.tab_[result.size_]='\0';
	return result;
    }
}




