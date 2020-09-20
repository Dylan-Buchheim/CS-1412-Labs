// Dylan Buchheim
// Group N
// Lab 502/Lecture 004
// Lab09
// 4/4/2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char name[200];
	struct Node *next;
};

struct Node *head; 
struct Node *tail;

void WriteMenu(){
	printf("------------------\n");
	printf("0) Call a customer\n");
	printf("1) Add a customer\n");
	printf("2) Quit\n");
	printf("Please input your selection (0-2): ");
}

struct Node *find(char *name, struct Node *head, struct Node *tail){
	struct Node *currentNode = head;
	for(;;){
		if(strcmp(currentNode->name,name) == 0){
			return currentNode;
		}else if(currentNode == tail){
			return NULL;
		}else{
			currentNode = currentNode->next;
		}
	}
}

void deleteFirstName(char *name){
	struct Node *tempNode;
	//copy the head name into the name parameter
	strcpy(name, head->name);
	//set the nextNode to the node after the head
	tempNode = head;
	head = head->next;
	free(tempNode);
	
}

void insert(char name[]){
	//set the starting node to the head node
	struct Node *current = tail;
	//if the current tail node is the head node
	if(current == head){
		//copy the name into head, and create a new node for its next value
		strcpy(head->name, name);
		head->next =malloc(sizeof(struct Node));
		tail = head->next;
	}
	//if the current tail node is not the head node
	else{
		strcpy(current->name, name);
		//create the new node at the next address
		current->next = malloc(sizeof(struct Node));
		//set the tail node to the newly created node and make it empty
		tail = current->next;
		strcpy(tail->name, ""); 
		tail->next = NULL; 
	}
}
	

void MenuSelect(){
	char selection;
	//get user input for selection
	WriteMenu();
	scanf("%c", &selection);
	getchar();
	//variables for the names
	char firstName[200];
	char name[200];
	switch(selection){
		case '0':
			if(find("Dylan",head,tail) != NULL){
				printf("The search was a success\n");
			}else{
				printf("The search was not a success\n");
			}
			/*if(strcmp(head->name,"") == 0){
				printf("There is nobody in line for now.\n\n");
			}else{
				deleteFirstName(firstName);
				printf("The first person in line is %s.\n\n", firstName);
			}
			MenuSelect(); */
		case '1':
			printf("Please insert a name: ");
			scanf("%s", name);
			getchar();
			//insert this node into the list
			insert(name);
			printf("%s is now at the end of the line!\n\n", name);
			MenuSelect();
		case '2':
			printf("Exiting...\n");
			exit(EXIT_FAILURE);
		default:
			printf("Invalid input, restarting...\n\n");
			MenuSelect();
	}
}

int main(void){
	head = malloc(sizeof(*head));
	strcpy(head->name, ""); 
	head->next = NULL;
	tail = head;
	
	MenuSelect();
}