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

 	
	printf("\n############### Ordering Nums\n");
	int j;

 	for(i = 0 ; i < (sizeof(arr)/sizeof(int)); i++){

 		for(j =i; j < (sizeof(arr)/sizeof(int)); j++){
 			 if(*(p_arr+j)>*(p_arr+i)){ 
                int temp=*(p_arr+j); 
                *(p_arr+j)=*(p_arr+i); 
                *(p_arr+i)=temp; 
                } 
 		}

 	}

	printf("\n############### Addresses\n");

	for(i = 0 ; i < (sizeof(arr)/sizeof(int)); i++){
 		printf("num %d | %d \n", i, *(p_arr + i)); 
 	}

 	printf("\n############### END\n");
    return 0;
}
