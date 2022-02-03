#include <stdio.h>
#include "stack.h"

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
    Push(&s, 5);
    Push(&s, 10);
    //Push(&s, 5);
    // while(!StackEmpty(&s))
    //     printf("%d \n", Pop(&s));

    TraverseStack(&s, Print);
    TraverseStack(&s, Double);
    TraverseStack(&s, Print);

    return 0;
}