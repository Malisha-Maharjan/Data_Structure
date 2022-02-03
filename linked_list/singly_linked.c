#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node *next;   
    int data;
} Node;

Node* getNode()
{
    return (Node*)malloc(sizeof(struct Node));
}

void InsertAtBeginning(Node** head, int data) 
{
    Node* new_node = getNode();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insertAtTheEnd(Node** head, int data)
{
    Node *new_node = getNode();
    new_node->data = data;
    new_node->next = NULL;

    Node *temp;
    temp = *head;
    while(temp->next != NULL)
        temp = temp->next; 
    temp->next = new_node;
}

void insertAtTheSpecificLocation(Node** head, int data)
{
    int position;
    printf("\nEnter the position of the node where you want to insert: ");
    scanf("%d", &position);

    Node *new_node = getNode();
    Node *temp;

    new_node->data = data;
    temp = *head;

    for(int i = 1; i < position - 1; i++)
        temp = temp->next;
    new_node->next = temp->next;
    temp->next = new_node;
}

void DeletingFirstNode(Node** head)
{
    Node *temp;
    temp = *head;
    if(temp == NULL)
    {
        printf("\nEmpty list \n");
        return;
    }
    printf("Deleted data: %d", temp->data);
    *head = temp->next;
    free(temp);
}

void DeletingEndNode(Node** head)
{
    Node *temp;
    temp = *head;

    if(temp == NULL)
    {
        printf("Empty list \n");
        return;
    }

    else if(temp->next == NULL)
    {
        head = NULL;
        printf("Deleted data: %d", temp->data);
        printf("\n");
        free(temp);
        return;
    }

    while(temp->next->next != NULL)
        temp = temp->next;
    printf("Deleted data: %d", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    printf("\n");
}

void DeletingAtTheSpecificLocation(Node **head)
{
    Node *temp, *p;
    int position;
    temp = *head;

    if(temp == NULL)
        printf("Empty List \n");
    else
    {
        printf("Enter the position of the node to be deleted: ");
        scanf("%d", &position);

        for(int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        } 
        p = temp->next;
        printf("Deleted data: %d", p->data);
        temp->next = p->next;
        free(p);
    }
}

void Display(Node* node) 
{
    if (node == NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;

    int choice, data;
    do
    {
        printf("1. Insertion at the Beginning. \n");
        printf("2. Insertion at the End. \n");
        printf("3. Insertion at the Specific location. \n");
        printf("4. Deletion at the Beginning. \n");
        printf("5. Deletion at the End. \n");
        printf("6. Deletion at the Specific location. \n");
        printf("7. Display the List \n");
        printf("8. Exit \n");
        scanf("%d", &choice);
        int data;
        switch (choice)
        {
        case 1:
            printf("enter data to be inserted: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data); 
            printf("\n");   
            break;

        case 2:
            printf("enter data to be inserted: ");
            scanf("%d", &data);
            insertAtTheEnd(&head, data);  
            printf("\n");    
            break;

        case 3:
            printf("enter data to be inserted: ");
            scanf("%d", &data);
            insertAtTheSpecificLocation(&head, data);  
            printf("\n");    
            break;

        case 4:
            DeletingFirstNode(&head);
            printf("\n");  
            break;

        case 5:
            DeletingEndNode(&head);
            printf("\n");   
            break;

        case 6:
            DeletingAtTheSpecificLocation(&head);
            printf("\n");  
            break;
        
        case 7:
            Display(head);
            printf("\n");  
            break;
        
        case 8:
            exit(0);

        default:
            printf("Invalid Choice \n");
            break;
        }
    } while (choice != 8);
    

    // InsertAtBeginning(&head, 2);
    // insertAtTheEnd(&head, 1);
    // InsertAtBeginning(&head, 3);
    // insertAtTheSpecificLocation(&head, 5);

    // printf("Linked list: ");
    // Display(head);

    // // DeletingFirstNode(&head);
    // // printf("\n Linked list: ");
    // // Display(head);

    // // DeletingEndNode(&head);
    // // // printf("\n Linked list: ");
    // // // Display(head);

    // DeletingAtTheSpecificLocation(&head);
    // printf("Linked list: ");
    // Display(head);
}