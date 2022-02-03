#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int StackEntry;

typedef struct node
{
    StackEntry data;
    struct node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;


void CreateStack(Stack *s)
{
    s->top = NULL;
}

bool StackEmpty(Stack *s)
{
    return s->top == NULL;
}

void Push(Stack *s, int item)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = item;
    n->next = s->top;
    s->top = n;
}

int Pop(Stack *s)
{
    int item = s->top->data;
    Node *n = s->top;
    s->top = n->next;
    free(n);
    return item;
}

void TraverseStack(Stack *s, void Visit(int*))
{
    Node *n = s->top;
    while(n != NULL)
    {
        Visit(&n->data);
        n = n->next;
    }
}

void Double(int *item)
{
    *item = (*item) * 2; 
}

void Print(int *item)
{
    printf("%d \n", *item);
} 


int main() {
    Stack s;
    CreateStack(&s);
    Push(&s, 5);
    Push(&s, 10);
    Push(&s, 15);
    // while(!StackEmpty(&s))
    //     printf("%d \n", Pop(&s));

    TraverseStack(&s, Print);
    TraverseStack(&s, Double);
    TraverseStack(&s, Print);
}
