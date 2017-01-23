#include <cstdio>
#include <cstdlib>
#include "string.h"

int main(){
	String str;  //test avec gdb (print str) $1 = {size_ = 0, capacity_ = 0, static max_size = 100, tab_ = 0x602010 ""}  
    String str2(str); // test avec gdb (print str2) $3 = {size_ = 0, capacity_ = 0, tab_ = 0x602030 "", static max_size = 100}
    printf("c_str : %s ", str2.c_str());
    printf("size : %zu", str2.size());    
	return EXIT_SUCCESS;
}


