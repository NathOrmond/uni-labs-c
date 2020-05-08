#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>

int chooseOperation();
float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);
float indicy(float num1, float num2);
float root(float num1, float num2);

int chooseOperation(){
	int rv;	
	printf("# 1 | Add\n");
	printf("# 2 | Subtract\n");
	printf("# 3 | Multiply\n");
	printf("# 4 | Divide\n");
	printf("# 5 | Indicy\n");
	printf("# 6 | Root\n");
	scanf("%d", &rv);
	return rv;
}

float add(float num1, float num2){ 
	printf("Attempting to add %f and %f \n", num1, num2);
	float ans = num1 + num2;
	printf("Answer is %f \n", ans);
	return ans;
}

float subtract(float num1, float num2){ 
	return (num1 - num2);
}

float multiply(float num1, float num2){ 
	return (num1 * num2);
}

float divide(float num1, float num2){ 
	return (num1/num2);
}

float indicy(float num1, float num2){
	int i;
	float ans;
	ans = num1;
	for(i=1; i < num2; i++){ 
		ans = (ans * num1);
	}	
	return ans;
}

float root(float num1, float num2){ 
	return 0;
}


int main(int argc, char*argv[]){
	while(1){
		float num1, num2;

		printf("Enter num1 :\n");
		scanf("%f",&num1);

		printf("Enter num2 :\n");
		scanf("%f",&num2);

		printf("num1 is %f \n", num1);
		printf("num2 is %f \n", num2);

		float ans;
		switch(chooseOperation()){ 
			case 1:
			ans = add(num1,num2);
			break;
			case 2:
			ans = subtract(num1,num2);
			break;
			case 3:
			ans = multiply(num1,num2);
			break;
			case 4:
			ans = divide(num1,num2);
			break;
			case 5:
			ans = indicy(num1,num2);
			break;
			case 6:
			ans = root(num1,num2);
			break;
			default:
			ans = printf("INVALID INPUT \n");
			break;
		}

		printf("##### \n\nANSWER = %f \n\n#####\n\n", ans);
	}
	return 0;
}
