// Dylan Buchheim
// Group N
// Lab 502/Lecture 004
// Lab08
// 3/28/2018

#include <stdio.h>

int GetSeries(int *a){
	printf("Please input a sequence of numbers ended by 0:\n");
	//Initialize numbers array with a size of 11
	int n = 0;
	//Start a for loop to get the sequence of numbers
	for(int i = 0; i < 11; i++){
		scanf("%d", (a+i));
		getchar();
		//If the input number is 0
		if(*(a+i) == 0){
			break;
		}
		n ++;
	}
	//Return the number of entries in the given series
	return n;
	
}

void ReverseArray(int n, int *a){
	printf("The numbers in the reverse order of your input are\n");
	//Start a for loop that itterates through all the values stored in a
	for(int i = n - 1; i >= 0; i--){
		//If it is the last number in the list, format it with a period
		if(i == 0){
			printf("%d.\n", *(a+i));
		}
		//Otherwise format it with a comma
		else{
			printf("%d, ", *(a+i));
		}
		
	}
}

int CalculateMax(int n, int *a){
	//Initialize the min integer that will be returned at the end
	int max = *a;
	//Start a for loop that itterates through all the values stored in a
	for(int i = n - 1; i >= 0; i--){
		//If the current value is less than the current min, set the min to the current value
		if(*(a+i) > max){
			max = *(a+i);
		}
	}

	return max;
}


int main(void){
	//Initialize the integers and arrays
	int a[11], *p;
	//Set p = to the address of the first element in the array
	p = &a[0];
	int n = GetSeries(p);
	
	ReverseArray(n,p);
	
	printf("The maximal number of them is %d.\n", CalculateMax(n,p));
	
	
}