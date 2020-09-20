// Dylan Buchheim
// Group N
// Lab 502/Lecture 004
// Lab12
// 4/25/2018


//Stack Abstract Data Type -----------------
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//defining the Node data type using a struct
typedef struct node{
	int n;
	struct node *next;
}Node;
//defining the *Stack data type using the stackhead struct
struct stackHead{
	Node *head;
};

typedef struct stackHead *Stack;

//Create function, a function which will allocate memory for a new stack and return that stack
Stack Create(){
	//create a stack s and allocate the memory for it and pass the adress to s
	Stack s = malloc(sizeof(struct stackHead));
	//initialize the head of the new stack to null
	s->head = NULL;

	return s;
}
//IsEmpty function, a function which checks if the passed stack is empty
int IsEmpty(Stack s){
	//if the passed in stack has an empty head, return 1, meaning the stack is empty
	if(s->head == NULL){
		return 1;
	}else{
		return 0;
	}
}
//Push function, pushes the number n into the top of the stack s
void Push(Stack s, int n){
	//create a temporary node
	Node *tempNode = malloc(sizeof(Node));
	//set the temp n to n
	tempNode->n = n;
	//insert the new node to the head of s
	tempNode->next = s->head;
	//set the head of s to the new node
	s->head = tempNode;
}
//Pop function, a function which pops the top number of the stack and returns it
int Pop(Stack s){
	//create a node h and set it equal to the first node in the passed stack
	Node *h = s->head;
	//create an int n and set it equal to the n value of the head node
	int n = h->n;
	//move the head of the stack to the next element in the stack
	s->head = h->next;
	//release the memory being held by the old head
	free(h);
	//return the value 
	return n;
}



