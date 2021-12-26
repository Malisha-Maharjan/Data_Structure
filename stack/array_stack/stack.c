#include "stack.h"

void CreateStack(Stack *s)
{
    s->top = -1;
}

bool StackEmpty(Stack *s)
{
    return s->top == -1;
}

bool StackFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void Push(Stack *s, char data)
{
    if(StackFull(s))
        printf("Stack is full \n");
    else 
        s->data[++s->top] = data;
}

char Pop(Stack *s)
{
    if(StackEmpty(s))
    {
        printf("Stack is empty \n");
        return 0;
    }
    return s->data[s->top--];
}

char Top(Stack *s)
{
    if(StackEmpty(s))
    {
        printf("Stack is empty \n");
        return 0;
    }
    return s->data[s->top];
}

void TraverseStack(Stack *s, void Visit(char*))
{
    for(char i = s->top; i >= 0; i--)
        Visit(&s->data[i]);
}