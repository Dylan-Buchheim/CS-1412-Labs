// Dylan Buchheim
// Group N
// Lab 502/Lecture 004
// Lab09
// 4/4/2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StringComp(const char *s1, const char *s2){
	int comparisonValue = 0;
	
	//if they are the same
	if(*s1 == *s2 && *s1 != '\0'){
		StringComp((s1 + 1), (s2 + 1));
	}
	//if s1 is less than s2
	else if(*s1 < *s2 || *s1 == '\0'){
		comparisonValue = -1;
	}
	//if s1 is greater than s2
	else if(*s1 > *s2 || *s2 == '\0'){
		comparisonValue = 1;
	}

	return comparisonValue;
}

void FindGreatestString(FILE *fp){
	//initialize the strings and pointers
	char firstName[200] = "", lastName[200] = "", greatestLastName[200] = "", greatestFirstName[200] = "";
	char *s1, *s2;
	s1 = greatestLastName;
	s2 = lastName;
	for(;;){
		//scan the next line of names
		fscanf(fp, "%s %s", firstName, lastName);
		//if the current greatest last name is less than the new last name
		if(StringComp(s1,s2) == -1){
			strcpy(greatestLastName, lastName);
			strcpy(greatestFirstName, firstName);
		}
		//if we are at then end of the file break the loop
		if(feof(fp)){
			break;
		} 
	}
	//after comparing all the strings in the file print the full name of the greatest last name
	printf("The full name whose last name is the greatest in the file is %s %s. \n", greatestFirstName, greatestLastName );
}

int main(void){
	//initialize the file name and file pointer variables
	char FNAME[200];
	FILE *fp;

	//get input for the file name
	printf("Please input the file name: ");
	scanf("%s", FNAME);
	
	//open the file
	fp = fopen(FNAME, "r");
	//if the file name does not exist
	if(fp == NULL){
		printf("Can't open %s\n", FNAME);
		exit(EXIT_FAILURE);
	}
	//find the greatest last name in the file
	FindGreatestString(fp);
	//close the file
	fclose(fp);
}