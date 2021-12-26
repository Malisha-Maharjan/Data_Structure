#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100
typedef struct
{
    char data[MAX_SIZE];
    char top;
} Stack;

void CreateStack(Stack *s);

bool StackEmpty(Stack *s);
bool StackFull(Stack *s);

void Push(Stack *s, char data);
char Pop(Stack *s);
char Top(Stack *s);


void TraverseStack(Stack *s, void Visit(char*));

#endif