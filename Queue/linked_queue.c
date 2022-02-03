#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct 
{
    Node *front;
    Node *rear;
} Queue;

void CreateQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

bool IsEmpty(Queue *q)
{
    return q->front == NULL;
}

void Enqueue(Queue *q, int data)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    if(IsEmpty(q))
        q->front = n;
    else
        q->rear->next = n;
    q->rear = n;
}

int Dequeue(Queue *q)
{
    if(IsEmpty(q))
    {
        printf("Queue is empty.\n");
        exit(2);
    }
    
    Node *n = q->front;
    int result = n->data;
    q->front = n->next;
    n->next = NULL;
    if(q->front == NULL)
        q->rear = NULL;
    free(n);
    return result;
}

void Display(Queue *q)
{
    //Node *n = q->front;
    // while(n != NULL)
    // {
    //     printf("%d ", n->data);
    //     n = n->next;
    // }

    for(Node *n = q->front; n != NULL; n = n->next)
        printf("%d ", n->data);
    printf("\n");
}

void Menu(Queue *q)
{   
    printf("1. Enqueue \n");
    printf("2. Dequeue \n");
    printf("3. Display \n");
    printf("4. Exit \n\n");

    int choice;
    printf("Choice: ");
    scanf("%d", &choice);

    int data;
    switch (choice)
    {
    case 1:
        printf("Data: ");
        scanf("%d", &data);
        Enqueue(q, data);
        printf("Enqueued data: %d\n", data);
        break;
    
    case 2:
        printf("Dequeued data: %d \n", Dequeue(q));
        break;
    
    case 3:
        Display(q);
        break;

    case 4:
        exit(0);

    default:
        printf("Invalid choice.\n");
        break;
    }

    printf("\n");
}

int main()
{
    Queue q;
    CreateQueue(&q);

    while(true)
        Menu(&q);
}
