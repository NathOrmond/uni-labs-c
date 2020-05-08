#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>

int main() {
 	int arr[5], i; 
 	int *p_arr;

 	p_arr = arr;

 	for(i = 0 ; i < (sizeof(arr)/sizeof(int)); i++){
 		printf("Enter number : %d\n", i); 
 		scanf("%d", &arr[i]);
 	}

 	
	printf("\n############### Values\n");

 	for(i = 0 ; i < (sizeof(arr)/sizeof(int)); i++){
 		printf("%d \n", arr[i]); 
 	}

	printf("\n############### Addresses\n");

 	for(i = 0 ; i < (sizeof(arr)/sizeof(int)); i++){
 		printf("%p \n", (p_arr + i)); 
 		printf("%d \n", *(p_arr + i)); 
 	}

 	printf("\n############### Reverse Ptr print\n");

 	for(i = (sizeof(arr)/sizeof(int)) ; i >= 0 ; i--){
 		printf("%d \n", *(p_arr + i)); 
 	}

 	printf("\n############### END\n");
    return 0;
}
