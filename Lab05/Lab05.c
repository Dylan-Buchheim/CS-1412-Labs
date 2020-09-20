//Lab05

#include <stdio.h>
#include <stdlib.h>
#include "Lab05.h"

void BuildMenu(){
	//Print the menu options
	printf("2) Go to question 2\n");
	printf("3) Go to question 3\n");
	printf("4) Exit.\n");
	printf("Please type a number from 2 to 4 to select menu item:");
	//initialize the user input
	char selection;
	scanf("%c", &selection);
	getchar();
	//Open a switch statement to execute what the user selected
	switch(selection){
		//Solve Question 2
		case '2' :
			TypeSize();
			break;
		//Solve Question 3
		case '3' :
			NumberArray();
			break;
		//Terminate the Program
		case '4' :
			printf("Exiting...\n");
			exit(0);
		//If the input is not valid
		default:
			printf("Invalid input, please type a number from 2 to 4\n\n");
			BuildMenu();
	}

}

char SelectType(){
	//Print the options
	printf("\nPick the Type.\n");
	printf("0) int\n1) float\n2) double\n3) char\n...\nn) Exit.\n");
	printf("Please type a number and select a type:");
	//Initialize the selection
	char selection1;
	scanf("%c", &selection1);
	getchar();
	return selection1;
}

char SelectSign(){
	//Print the options
	printf("\nPick a modifier.\n");
	printf("0) Unsigned\n1) Signed\n...\nn) No Modifier\n");
	printf("Please type a number and select a modifier:");
	//Initialize the selection
	char selection2;
	scanf("%c", &selection2);
	getchar();
	return selection2;
}

char SelectSize(){
	//Print the options
	printf("\nPick the second modifier.\n");
	printf("0) Short\n1) Long\n...\nn) No Modifier\n");
	printf("Please type a number and select a modifier:");
	//Initialize the selection
	char selection3;
	scanf("%c", &selection3);
	getchar();
	return selection3;
}

void TypeSize(){
	char typeSelection = SelectType();
	char signSelection, lengthSelection;

	//Switch statement that does the correct action for the type
	switch(typeSelection){
		//Case Int
		case '0':
			signSelection = SelectSign();
			//if unsigned
			if(signSelection == '0'){
				lengthSelection = SelectSize();
				//if short
				if(lengthSelection == '0'){
					printf("The size of an unsigned short int is %lu\n", sizeof(unsigned short int));
				//if long
				}else if(lengthSelection == '1'){
					printf("The size of an unsigned long int is %lu\n", sizeof(unsigned long int));
				//if no modifier was selected
				}else if(lengthSelection == 'n'){
					printf("The size of an unsigned int is %lu\n", sizeof(unsigned int));
				//if none of the options was selected 
				}else{
					printf("Invalid input, restarting..\n");
					TypeSize();
				}
			//if signed
			}else if(signSelection == '1'){
				lengthSelection = SelectSize();
				//if short
				if(lengthSelection == '0'){
					printf("The size of an signed short int is %lu\n", sizeof(signed short int));
				//if long
				}else if(lengthSelection == '1'){
					printf("The size of an signed long int is %lu\n", sizeof(signed long int));
				//if no modifier was selected
				}else if(lengthSelection == 'n'){
					printf("The size of an signed int is %lu\n", sizeof(signed int));
				//if none of the options was selected
				}else{
					printf("Invalid input, restarting...\n");
					TypeSize();
				}
			//if there was no modifier selected
			}else if(signSelection == 'n'){
				lengthSelection = SelectSize();
				//if short
				if(lengthSelection == '0'){
					printf("The size of an short int is %lu\n", sizeof(short int));
				//if long
				}else if(lengthSelection == '1'){
					printf("The size of an long int is %lu\n", sizeof(long int));
				//if no modifier was selected
				}else if(lengthSelection == 'n'){
						printf("The size of an int is %lu\n", sizeof(int));
				//if none of the options was selected
				}else{
					printf("Invalid input, restarting...\n");
					TypeSize();
				}
			//if they didn't pick one of the options
			}else{
				printf("Invalid input, restarting...\n");
				TypeSize();
			}
			break;
		//Case Float
		case '1':
			//there are no modifiers for float, so just print the size of the float
			printf("The size of an float is %lu\n", sizeof(float));
			break;
		//Case Double
		case '2':
			lengthSelection = SelectSize();
			//if long
			if(lengthSelection == '1'){
				printf("The size of an long double is %lu\n", sizeof(long double));
			//if no modifier was selected
			}else if(lengthSelection == 'n'){
				printf("The size of an double is %lu\n", sizeof(double));
			//if one of the proper choices was not made
			}else{
				printf("Invalid input, restarting...\n");
				TypeSize();
			}
			break;
		//Case Char
		case '3':
			signSelection = SelectSign();
			//if unsigned
			if(signSelection == '0'){
				printf("The size of an unsigned char is %lu\n", sizeof(unsigned char));
			//if signed
			}else if(signSelection == '1'){
				printf("The size of an signed char is %lu\n", sizeof(signed char));
			//if no modifier was selected
			}else if(signSelection == 'n'){
				printf("The size of an char is %lu\n", sizeof(char));
			//if none of the choices was selected
			}else{
				printf("Invalid input, restarting...\n");
				TypeSize();
			}
			break;
		//Case Exiting back to menu
		case 'n':
			printf("Exiting...\n");
			BuildMenu();
			break;
		//if they did not chose one of the options
		default:
			printf("Invalid input, restarting...\n");
			TypeSize();
			break;
	}

	//After the user gets their response it restarts
	TypeSize();
}

void NumberArray(){
	printf("Please input a sequence of numbers ended by 0:\n");
	//Initialize numbers array with a size of 11
	int numbers[11];
	int min,numberOfEntries = 0;
	//Start a for loop to get the sequence of numbers
	for(int i = 0; i < 11; i++){
		scanf("%d", &numbers[i]);
		getchar();
		if(numbers[i] == 0){
			break;
		}
		numberOfEntries ++;
	}
	//Start a foor loop to print them in reverse and calculate the min
	min = numbers[0];
	printf("The numbers in the reverse order of your input are ");
	for(int i = numberOfEntries - 1; i >= 0; i--){
		printf("%d, ", numbers[i]);
		if(numbers[i] < min){
			min = numbers[i];
		}
	}
	printf("\nThe minimal number of them is %d.\n", min);
	//return to the main menu
	BuildMenu();
}

int main(void){
	BuildMenu();
}