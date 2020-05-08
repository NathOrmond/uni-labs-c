#include <stdio.h>

int main() {
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char *pvowels = &vowels;
    
    int i;
    
    printf("\n\n");

    // Print the addresses
     for (i = 0; i < 5; i++) {
         printf("&vowels[%d]: %u, pvowels + %d: %u, vowels + %d: %u\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
     }

     printf("\n\n");

    // Print the values
    for (i = 0; i < 5; i++) {
         printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }

    printf("\n\n");

    return 0;
}
