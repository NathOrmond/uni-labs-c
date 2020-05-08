#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>

// average calc 

float calculateAverage(int a, int b, int c);

float calculateAverage(int a, int b, int c){ 
	float sum;
	float ave;
	sum = a + b + c;
	ave = sum/3;
	return ave;
}


int main(int argc, char*argv[]){

	int a;
	int b;
	int c;

	printf("Enter three numbers to calculate the average \n");
	
	printf("Num 1 \n");
	scanf("%d", &a);

	printf("Num 2 \n");
	scanf("%d", &b);

	printf("Num 3 \n");
	scanf("%d", &c);

	printf("Average is %f \n ## END ##\n", calculateAverage(a,b,c));

	return 0;
}
