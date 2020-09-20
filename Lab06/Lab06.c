//Lab06

#include <stdio.h>

int GetSeries(int a[]){
	printf("Please input a sequence of numbers in increasing order ended by 0:\n");
	//Initialize numbers array with a size of 11
	int n = 0;
	//Start a for loop to get the sequence of numbers
	for(int i = 0; i < 11; i++){
		scanf("%d", &a[i]);
		getchar();
		if(a[i] == 0){
			break;
		}
		n ++;
	}
	//Return the number of entries in the given series
	return n;
	
}

int Search(int a[], int start, int end, int m){
	//Initialize the data
	int mid = (start + end)/2;
	int b;
	//if the start is bigger then the end
	if(start > end){
		b = 0;
		return b;
	}
	//if the midpoint is m
	if(a[mid] == m){
		b = 1;
		return b;
	}else if(m > a[mid]){
		b = Search(a,mid + 1,end,m);
	}else{
		b = Search(a,start,mid - 1,m);
	}

	return b;
}

int main(void){
	//Initialize the integers and arrays
	int a[11];
	int n = GetSeries(a);
	int m;
	//Get user input for a number to find in a given series
	printf("Input a number to find from the series: ");
	scanf("%d", &m);
	//If the given number is in the series 
	if(Search(a,0,n-1,m) == 1){
		printf("The number %d is in the series you gave.\n", m);
	//If the given number is not in the series
	}else{
		printf("The number %d is not in the series you gave.\n", m);
	}
}