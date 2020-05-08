#include<stdio.h>

/**
 * Print Conversion table
 */


int main(){ 
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("\n\nFAR | CELS\n-----------\n");
    
    for(fahr=300;fahr>=lower;fahr-=step){ 
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f |%6.1f\n", fahr, celsius);
        }

    return 0;
}
