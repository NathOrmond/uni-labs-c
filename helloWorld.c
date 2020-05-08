#include <stdio.h>

const char * helloWorld();

int main(int argc, char*argv[]){
	printf( "%s", helloWorld());
	return 0;
}

const char * helloWorld(){ 
        static const char *ptr= "Hello World!";
	return ptr;
}	
