// Dylan Buchheim
// Group N
// Lab 502/Lecture 004
// Lab02
// 2/7/2018

#import <stdio.h>

void DateConversion(){
	//Variables
	int m,d,y;
	//User Input
	printf("Input a date to be converted mm/dd/yyyy: ");
	scanf("%d/%d/%d", &m, &d, &y);

	//Print with formatting
	printf("Your date in the new format is: %d%02d%02d \n", y,m,d);

}

void PrintMessage(int m, int n){
	//If the message needs to be printed more than once
	if(m > 1){
		printf("The important message needs to be repeated %d times\n" , n);
		printf("The important message needs to be repeated %d times\n" , n);
		printf("\n");
		//Call PrintMessage m-2 times
		PrintMessage(m - 2,n);
	//If the message only needs to be printed once
	}else if(m==1){
		printf("The important message needs to be repeated %d times\n" , n);
	//If the message no longer needs to be printed
	}else{
		return;
	}
}

void ImportantMessage(){

	//Variables
	int m;
	//User Input
	printf("How many times should the message be printed? ");
	scanf("%d", &m);

	//Calling the PrintMessage function to print it m times
	PrintMessage(m , m);
}


int main(void){
	//Calling the function for problem one
	DateConversion();
	//Calling the function for problem two
	ImportantMessage();
}