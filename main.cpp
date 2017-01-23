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
    printf("c1 = %s\n", c1);
	String str3=String(c1); //test avec gdb (print str3) $1 = {size_ = 7, capacity_ = 14, tab_ = 0x602050 "abcdefg", static max_size = 100}
    
    //Test c_str pour pointeur 
    printf("c_str : %s ", str2.c_str()); 
    
    //Test size pour taille 
    printf("size : %zu", str2.size());    
    
	return EXIT_SUCCESS;
}


