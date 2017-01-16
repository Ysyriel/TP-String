#include "string.h"
#include <cstdio>
#include <cstdlib>

string::string(){
	tab = new char[50];
	capacite = 50;
	longueur = 0;
}


