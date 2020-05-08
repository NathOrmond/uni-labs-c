#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>

/**
 * Lab 0:  
 * 2D Shape Areas 
 **/

int menuChoice();
int rectArea(int width, int height);
int circleArea1(int radius); 
int circleArea2(int diameter);
static int pi = 3.141592;


/**
 * Switch to select shape
 * */
int menuChoice(){ 
	int out;
	printf("# 1 | Rectangle \n");
    printf("# 2 | Circle \n");
	out = scanf("%d", &out);
        return out;	
}

/**
 * Rectangle
 **/
int rectArea(int width, int height){ 
	return width * height;
}

/**
 * Circle
 */
int circleArea1(int radius){
       //Pi * r ^ 2	
	return pi * radius * radius;
}

int circleArea2(int diameter){
	int radius;
	radius = diameter/2;
	return circleArea1(radius);
}


/**
 *Main method 
 *
 **/ 
int main(int argc, char*argv[]){
	
	int height;
	int width;
	int opt;
	int circleLen;

	switch(menuChoice()){
		case 1:
			printf("Enter width : ");
			fflush(stdout);
			width = scanf("%d", &width);
			printf("Enter height : ");
        		fflush(stdout);	
			height = scanf("%d", &height); 
			printf("The area is %d \n", rectArea(width,height));
			break;
		case 2: 
			printf("# 1 | Enter Radius  ");
			printf("# 2 | Enter Diameter");
			fflush(stdout);
			opt = scanf("%d", &opt); 
			
			if(opt == 1){ 
				printf("Enter Radius : \n");
				fflush(stdout);
				circleLen = scanf("%d",&circleLen);
				printf("The area is : %d", circleArea1(circleLen));
			} else if (opt == 2){ 
				printf("Enter Diameter : \n");
				fflush(stdout);
				circleLen = scanf("%d", &circleLen);
				printf("The area is : %d", circleArea2(circleLen));
			} else { 
				printf("INVALID OPTION");
			}
			break;
		default:
			printf("INVALID MENU CHOICE");
			break;
		}

	return 0;
}
