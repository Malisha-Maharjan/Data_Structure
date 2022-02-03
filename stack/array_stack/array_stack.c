#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 2

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

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

void Push(Stack *s, int data)
{
    if(StackFull(s))
        printf("Stack is full \n");
    else 
        s->data[++s->top] = data;
}

int Pop(Stack *s)
{
    if(StackEmpty(s))
    {
        printf("Stack is empty \n");
        return 0;
    }
    else
        return s->data[s->top--];
}

void TraverseStack(Stack *s, void Visit(int*))
{
    for(int i = s->top; i >= 0; i--)
        Visit(&s->data[i]);
}

void Double(int *item)
{
    *item = (*item) * 2; 
}

void Print(int *item)
{
    printf("%d \n", *item);
} 


int main() 
{
    Stack s;
    CreateStack(&s);
    Push(&s, 3);
    Push(&s, 4);
    //Push(&s, 5);
    // while(!StackEmpty(&s))
    //     printf("%d \n", Pop(&s));

    TraverseStack(&s, Print);
    TraverseStack(&s, Double);
    TraverseStack(&s, Print);

    return 0;
}