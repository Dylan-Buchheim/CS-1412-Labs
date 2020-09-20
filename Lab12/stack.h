// Dylan Buchheim
// Group N
// Lab 502/Lecture 004
// Lab12
// 4/25/2018

//Stack Header -----------------

#ifndef STACKADT_H
#define STACKADT_H
//defines the stackhead type
typedef struct stackHead *Stack;
//defines all the functions for the stack type
Stack Create(void);
int IsEmpty(Stack s);
void Push(Stack s, int n);
int Pop(Stack s);
#endif