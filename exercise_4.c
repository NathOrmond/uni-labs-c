#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>


//Primitive Types 

int main(int argc, char*argv[]){
	int n;
    float f;	
	char c; 



	printf("Enter a character: ");
	scanf("%c", &c);

	printf("Enter a float: ");
	scanf("%f", &f);

	printf("Enter an Integer: ");
	scanf("%d", &n);

	printf("The character was %c \n", c);
	printf("The float was %f \n", f);
	printf("The integer was %d \n", n);
	return 0;
}
