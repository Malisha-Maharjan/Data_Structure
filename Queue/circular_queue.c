#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 5

typedef struct 
{
    int front;
    int rear;
    int data[SIZE];
} Queue;

void CreateQueue(Queue *q)
{
    q->front = SIZE - 1;
    q->rear = SIZE - 1;
}

bool IsEmpty(Queue *q)
{
    return q->rear == q->front;
}

bool IsFull(Queue *q)
{
    return q->front == (q->rear + 1) % SIZE;
}

void Enqueue(Queue *q, int data)
{
    if(IsFull(q))
    {
        printf("Queue is full.\n");
    }
    q->rear = (q->rear + 1) % SIZE;
    q->data[q->rear] = data;  
}

int Dequeue(Queue *q)
{
    if(IsEmpty(q))
    {
        printf("Queue is empty.\n");
        return false;
    }
    q->front = (q->front + 1) % SIZE;
    int result = q->data[q->front];
    return result;
}

void Display(Queue *q)
{
    for (int i = (q->front +  1) % SIZE; i != q->rear; i = (i + 1) % SIZE)
        printf("%d", q->data[i]);
    printf("%d", q->data[q->rear]);
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
