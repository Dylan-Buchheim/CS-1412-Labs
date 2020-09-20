// Dylan Buchheim
// Group N
// Lab 502/Lecture 004
// Lab12
// 4/25/2018


//Lab12 Main Implementation -----------------
#include <stdio.h>
#include "stack.h"

//GetSeries function, a function which gets user input for a series of integers and stores it in a stack
void GetSeries(Stack s){
	printf("\nInput a series of integers (ended with zero):\n");
	for(;;){
		//get user input for a number
		int n;
		scanf("%d", &n);
		//push that number into the given stack if the integer is not 0
		if(n != 0){
			Push(s,n);
		}else{
			break;
		}
	}
}

//PrintSeries function, a function which prints the numbers in the stack in reverse order
void PrintSeries(Stack s){
	printf("----------\nThe series of integers you gave is:\n");
	for(;;){
		if(IsEmpty(s) != 1){
			printf("%d ", Pop(s));
		}else{
			printf("\n");
			break;
		}
	}
}

int main(void){
	//creates the stack s
	Stack s;
	s = Create();

	//get user input for a series to put into stack s
	GetSeries(s);

	//print the integers in the stack s in reverse order
	PrintSeries(s);
}