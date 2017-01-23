#include "string.h"
#include <cstdio>
#include <cstdlib>

const size_t String::max_size = 100; //Définition de l'attribut static

String::String(){
	size_=0;
	capacity_=0;
	tab_=new char[capacity_+1];
	tab_[0]='\0';
}

String::~String()
{
    delete[] tab_;
    tab_=nullptr;
}
