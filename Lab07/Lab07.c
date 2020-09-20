//Lab07

#include <stdio.h>

//Function MoveDiscs which is used to print the instructions on how to move the dics
void MoveDiscs(int n, char startRod, char endRod, char tempRod){
	//If on the last move, n = 1
	if(n == 1){
		printf("\n Move disc 1 from rod %c to rod %c \n", startRod, endRod);
        return;
	}
	
	//Otherwise print the instructions to move n-1 discs from the start rod to the temp rod
	MoveDiscs(n-1, startRod, tempRod, endRod);
    
    //Print the instruction to move the bottom disc to the end rod
    printf("\n Move disc %d from rod %c to rod %c", n, startRod, endRod);
    
    //Then print the instructions to move the n-1 discs from the temp rod to the end rod
    MoveDiscs(n-1, tempRod, endRod, startRod);

}

int main(void){
	int n;
	printf("Please enter the amount of discs you would like to move: ");
	
	//Get the input the amount discs the user wants to move
	scanf("%d", &n);
	
	//Call the move discs function with the given value of n
	MoveDiscs(n,'A','C','B');
}