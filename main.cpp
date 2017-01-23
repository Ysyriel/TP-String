#include <cstdio>
#include <cstdlib>
#include "string.h"

int main(){
	String str;  
	printf("a%sb", str);   //test avec gdb $1 = {size_ = 0, capacity_ = 0, static max_size = 100, tab_ = 0x602010 ""}
	
	return EXIT_SUCCESS;
}


