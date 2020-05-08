#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
////////////////////////////////////////////////////////////////////////////////////////////
/**
 * PRISONERS' DILEMMA
 **/
////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Declarations
 **/
int runAgain();
void printRules(); 
int choosePlayerStrategy(int playerNum);
int runInteraction(int player1Staretegy, int player2Strategy);
void printOutcome(int interactionOutcome);

/**
 * Main
 **/
int main(int argc, char*argv[]){
	while(runAgain()){ 
		printRules();
		printOutcome(runInteraction(choosePlayerStrategy(1), choosePlayerStrategy(2)));
	}
	return 0;
}

/**
 * Methods
 **/
int runAgain(){ 
	char input;
	printf("# Run Programme? : y/n : \n");
	scanf("%s", &input);
	int outcome = ( input == 'y') ? 1 : 0;

	printf("input %c , returning %d \n", input, outcome);

	return outcome;
}

void printRules(){ 
	printf("Prisoners' Dilemma : \nTwo prisoners in seperate cells are asked if they are guilty for committing a crime.\n");
	printf("If you confess guilt and your partner betrays you then you get the maximum sentence.\n");
	printf("If you both confess then you will both get a reduced sentence.\n");
	printf("If you betray your partner, saying you are innocent, and they confess guilt, they will take the full sentence,\nbut you will go free. \n##########\n");
}

int choosePlayerStrategy(int playerNum){ 
	printf("Choose strategy for Player %d \n", playerNum);
	int choice;
	printf("# 0 | Plead Innocence\n");
	printf("# 1 | Confess Guilt\n");
	scanf("%d", &choice);
	return choice;
}

int runInteraction(int player1Guilt, int player2Guilt){ 
	if(player1Guilt && player2Guilt){ 
		return 1;
	} else if(player1Guilt && !player2Guilt){ 
		return 2;
	} else if(!player1Guilt && !player2Guilt){ 
		return 3;
	} else if(!player1Guilt && player2Guilt){ 
		return 4;
	}
	return 0;
}

void printOutcome(int interactionOutcome){ 
	switch(interactionOutcome){ 
		case 1:
			printf("Both players guilty, Both receive 2 year sentence");
			break; 
		case 2:
			printf("Player 1 Guilty and receives 5 year sentence, Player 2 goes free");
			break;
		case 3:
			printf("Both players plead innocence and both receive a 5 year sentence");
			break;
		case 4:
			printf("Player 1 goes free but Player 2 receives a 5 year sentence");
			break;
		default:
		printf("INVALID INPUT");
			break;	
	}
	printf("\n\n##########\n\n");
}
////////////////////////////////////////////////////////////////////////////////////////////EOF