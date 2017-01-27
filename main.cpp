#include <cstdio>
#include <cstdlib>
#include "string.h"

int main(){
	//Test des constructeurs
	//Test du constructeur par défaut
	String str;  //test avec gdb (print str) $1 = {size_ = 0, capacity_ = 0,tab_ = 0x602010 "", static max_size = 100}
    //Test du constructeur par copie
    String str2(str); //test avec gdb (print str2) $1 = {size_ = 0, capacity_ = 0, tab_ = 0x602030 "", static max_size = 100}
	//Test du constructeur par c-string
	char c1[]= "abcdefg";
	String str3=String(c1); //test avec gdb (print str3) $1 = {size_ = 7, capacity_ = 14, tab_ = 0x602050 "abcdefg", static max_size = 100}
	
	//Test des getters
	//Test capacity pour capacité
	int a=str3.capacity(); //test avec gdb (print a) $1 = 14 
	printf("capacité de str3: %d \n",a);
    //Test c_str pour pointeur 
    printf("c_str de str3 : %s\n", str3.c_str()); 
    //Test size pour taille 
    printf("size de str3: %zu\n", str3.size());    
	//Test length pour longueur
    printf("length de str3: %zu\n", str3.length()); 
    //Test max_size pour max_size
	printf("max_size (de tous les objets String): %zu\n", str3.max_size()); 
      
    //Test des méthodes
    //Test de empty
    bool b=str.empty();
	printf("%d",b); //retourne 1 (VRAI : la chaine str est vide car créée par le constructeur par défaut)
    if (b==1) printf(" : True\n");
    //Test de reserve
    //Test avec gdb (p str3) $1 = {size_ = 7, capacity_ = 14, tab_ = 0x603050 "abcdefg", static max_size_ = 100}  
	str3.reserve(50);
	//Test avec gdb (p str3) $2 = {size_ = 7, capacity_ = 50, tab_ = 0x603070 "abcdefg", static max_size_ = 100}
	//On note l'adresse pour tab_  qui differe, montrant la creation du nouveau tableau de la taille adaptee
    //Test clear pour une chaîne de caractère 
    str3.clear();
    printf("Lorsque la chaine str3 est effacée,c_str: %s \n",str3.c_str());
    //Test resize
    str3.resize(20);
    printf("Après resize la c_string de str3 est : %s \n",str3.c_str());
    //Test avec gdb (p str3) $1 = {size_ = 20, capacity_ = 50, tab_ = 0x603070 ' ' <se r\377\377\377\377\377\377\377\377p\377\377\377\377\377\377\377\377te 20 fois>, static max_size_ = 100}
	str3.resize(25,'m');
	printf("Après resize la c_string de str3 est : %s \n",str3.c_str());
	// Test avec gdb (p str3) $1 = {size_ = 25, capacity_ = 50, tab_ = 0x603070 ' ' <se r\377\377\377\377\377\377\377\377p\377\377\377\377\377\377\377\377te 20 fois>, "mmmmm", static max_size_ = 100}

	
	return EXIT_SUCCESS;
}


