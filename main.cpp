#include <cstdio>
#include <cstdlib>
#include "string.h"

int main(){
	//Test des constructeurs
	//Test du constructeur par défaut
	String str;  //test avec gdb (print str) $1 = {size_ = 0, capacity_ = 0, static max_size = 100, tab_ = 0x602010 ""}
    //Test du constructeur par copie
    String str2(str); //test avec gdb (print str2) $1 = {size_ = 0, capacity_ = 0, tab_ = 0x602030 "", static max_size = 100}
	//Test du constructeur par c-string
	char c1[]= "abcdefg";
	String str3=String(c1); //test avec gdb (print str3) $1 = {size_ = 7, capacity_ = 14, tab_ = 0x602050 "abcdefg", static max_size = 100}
	
	//Test des getters
	//Test capacity pour capacité
	int a=str3.capacity(); //test avec gdb (print a) $1 = 14 
    //Test c_str pour pointeur 
    printf("c_str : %s\n", str3.c_str()); 
    //Test size pour taille 
    printf("size : %zu\n", str3.size());    
	//Test length pour longueur
    printf("length : %zu\n", str2.length()); 
    //Test max_size pour max_size
	printf("max_size : %zu\n", str2.max_size()); 
      
    //Test des méthodes
    //Test de empty
    bool b=str.empty();
	printf("%d\n",b); //retourne 1 (VRAI : la chaine str est vide car créée par le constructeur par défaut)
    //Test de reserve
	printf("capacity : %zu\n", str3.capacity());    
	str3.reserve(50);
	printf("capacity après reserve : %zu\n", str3.capacity());  
    //Test clear pour une chaîne de caractère 
    str3.clear();
    printf("Lorsque la chaine str3 est effacée :");
    printf("c_str: %s \n",str3.c_str());

	return EXIT_SUCCESS;
}


