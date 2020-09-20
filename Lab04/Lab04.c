//Lab04

#include <stdio.h>
#include <stdlib.h>

//stty -icanon min 1

void TaxDue(){
	//Initializing the income float
	float income, tax;
	printf("Enter your taxable income: ");
	scanf("%f", &income);

	//If statements that check which range the income is in, then calculates the tax accordingly
	//Not over $750
	if(income <= 750 && income > 0){
		tax = (income * 0.01);
	}
	//$750-$2250
	if(income <= 2250 && income > 750){
		tax = 7.50 + ((income - 750) * 0.02);
	}
	//$2250-$3750
	if(income <= 3750 && income > 2250){
		tax = 37.50 + ((income - 2250) * 0.03);
	}
	//$3750-$5250
	if(income <= 5250 && income > 3750){
		tax = 82.50 + ((income - 3750) * 0.04);
	}
	//$5250-7000
	if(income <= 7000 && income > 5250){
		tax = 142.50 + ((income - 5250) * 0.05);
	}
	//Over $7000
	if(income > 7000){
		tax = 230.0 + ((income - 7000) * 0.06);
	}
	//Invalid income
	if(income < 0){
		printf("Invalid income, please input a proper income.\n");
			TaxDue();
	}
	
	//Print the amount of tax due on the given income
	printf("The amount of tax due on an income of $%.2f is $%.2f \n\n", income, tax);
}

void PrintMenu(){
	//Print statements for all the menu options
	printf("0) Check Balance. \n");
	printf("1) Deposit. \n");
	printf("2) Change Password. \n");
	printf("3) Transfer Money. \n");
	printf("4) Exit. \n");
}

void BuildMenu(){
	
	//Printing the menu options
	PrintMenu();
	//Use a do while loop to check if the input is valid
	char selection;
	do{
		printf("Please type a number from 0 to 4 to select a menu item: ");
		scanf("%c", &selection);
	}while(selection != '0' && selection != '1' && selection != '2' && selection != '3' && selection != '4');
	
	//Open the switch statement for the different options
	switch(selection){
		case '0' :
			printf("Check Balance.\nPress any key to continue your transactions...");
			break;
		case '1' :
			printf("Deposit.\nPress any key to continue your transactions...");
			break;
		case '2' :
			printf("Change Password.\nPress any key to continue your transactions...");
			break;
		case '3' :
			printf("Transfer Money.\nPress any key to continue your transactions...");
			break;
		case '4' :
			printf("Exiting...\n");
			exit(0);
			
	}

	//Waiting for the user to press a key
	char c;
	c = getchar();
	c = getchar();
	printf("\n");
	//Restart the menu process after the user presses a key
	BuildMenu();

}


int main(void){
	TaxDue();
	BuildMenu();
}

