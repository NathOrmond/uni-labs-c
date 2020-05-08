#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
////////////////////////////////////////////////////////////////////////////////////////////

char chars[];

/**
 * Main
 **/
int main(int argc, char*argv[]){
	int i;
	int num;

	i = 1;
	while(i){ 
		printf("Enter character %d \n", i);
		scanf("%c%*c",&chars[i]);
		if(chars[i] == 'q'){
			num = i;
			i = 0; //exit while loop 
			break;
		}
		i++;
	}


	printf("%d",num);
	for(i = 0; i < num; i++){ 
		printf("This is character %c \n", chars[i]);
	}


	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////EOF