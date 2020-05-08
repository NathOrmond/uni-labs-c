#include<stdio.h>

int menu_opt();
void print_table();
int run_prg();

int main(){ 
	while(run_prg()){ 

	}
	printf("\n\n### TERMINATING PROGRAMME\n\n");
	return 0;
}


int menu_opt(){ 

}


void print_table(){ 

}


int run_prg(){
	char input_char; 
	printf("Contunue to run programme? [y/n] :\n");
	scanf("%s", &input_char);
	return (input_char == 'y') ? 1 : 0;
}