// Dylan Buchheim
// Group N
// Lab 502/Lecture 004
// Lab03
// 2/14/2018

#import <stdio.h>

//Reverse Number Function
void ReverseNumber(int n){
	//Initialize the Integers
	int lastDigit, remainingDigits;
	lastDigit = n % 10;
	remainingDigits = n / 10;

	//Print the last digit in the integer n
	printf("%d", lastDigit);
	//If there are still more digits to be printed, call ReverseNumber with the remaining digits 
	if(remainingDigits > 0){
		ReverseNumber(remainingDigits);
	}
	//Otherwise just print a newline after the reversed number
	else{
		printf("\n");
	}
	
}

//Check Digit Function
void CheckDigit(){
	//Initialize the integers
	int n, x1,x2,x3,x4,x5,y1,y2,y3,y4,y5, sum1, sum2, combinedSum;
	//Print prompts and get user input for all the numbers in the UPC
	printf("Enter the first digit: ");
	scanf("%1d", &n);
	printf("Enter the first 5 digits: ");
	scanf("%1d%1d%1d%1d%1d", &x1, &x2, &x3, &x4, &x5);
	printf("Enter the second 5 digits: ");
	scanf("%1d%1d%1d%1d%1d", &y1, &y2, &y3, &y4, &y5);
	
	//Set sum1, sum2, and the combined sum equal to their corresponding values
	sum1 = n + x2 + x4 + y1 + y3 + y5;
	sum2 = x1 + x3 + x5 + y2 + y4;
	combinedSum = (3 * sum1) + sum2;

	//Print what the check digit should be according to the numbers that were input
	printf("The Check Digit is: %d \n", 9 - (combinedSum - 1) % 10);
}

int main(void){
	//Call the CheckDigit function
	CheckDigit();

	int numberToReverse;
	//Print the prompt and set the number the user wants reversed
	printf("Input a number to reverse: ");
	scanf("%d", &numberToReverse);
	printf("Your number reversed is: ");
	//Call the ReverseNumber function passing in the user input
	ReverseNumber(numberToReverse);

}