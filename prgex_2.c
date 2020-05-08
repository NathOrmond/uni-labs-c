#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define EXIT_CODE 0

typedef int bool;
#define true 1
#define false 0

int menu_opt();
void print_table();
int run_prg();
int prg();

int main(){ 
	while(run_prg()){ 
		prg();
	}
	printf("\n\n### Terminating with exit code: %d\n\n", EXIT_CODE);
	return EXIT_CODE;
}

int prg(){ 

	size_t len = 4;
    char *buf = malloc(len * sizeof *buf);

    if(buf == NULL) {     // check for NULL        
        printf("Not enough memory to allocate.\n");
        return 1;
    }

    size_t i = 0;
    float *temp; // to save buf in case realloc fails


    printf("ENTER CHARS : \n");
    // read until EOF or matching failure occurs
    // signal the end of input(EOF) by pressing Ctrl+D on *nix

    while(scanf("%s", buf+i) == 1) { 
        i++;
        if(i == len) {               // buf is full
            temp = buf;
            len *= 2;
            buf = realloc(buf, len * sizeof *buf);  // reallocate buf
            if(buf == NULL) {
                printf("Not enough memory to reallocate.\n");
                buf = temp;
                break;
            }
        }
    }

    if(i == 0) {
        printf("No input read\n");
        return 1;
    }


    printf("PALLINDROME :");

    for(size_t j = i; j >= 0; j--) {
        printf("%c", buf[j]);
    }

    free(buf);
    buf = NULL;

    return 0;
}

int menu_opt(){ 

}

void print_table(){ 

}

int run_prg(){
	char input_char; 
	printf("\n\nContunue to run programme? [y/n] : \n");
	scanf("%s", &input_char);
	return (input_char == 'y') ? 1 : 0;
}