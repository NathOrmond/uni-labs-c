#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]){

	char name[80];
	char dob[80];
	char mob[80];

	strcpy(name, "NAME : ");
	strcpy(dob , "DOB  : ");
	strcpy(mob , "MOB  : ");

    strcat(name, "Nathan Ormond \n");
    strcat(dob , "11 Oct 1996   \n");
    strcat(mob , "+447984577333 \n");


	printf("%s",name );
	printf("%s", dob);
	printf("%s", mob);

	return 0;
}
