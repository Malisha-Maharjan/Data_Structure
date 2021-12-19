#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int capacity;
    int count; 
} Array;

Array* create_array(int capacity)
{
    Array *array = (Array*)malloc(sizeof(Array));

    array->capacity = capacity;
    array->count = 0;
    array->data = (int*)malloc(sizeof(int) * array->capacity);
    
    return array;
}

void double_capacity_if_full(Array *array)
{
    if (array->count == array->capacity)
    {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity);
    }
}a

void insert(Array* array, int index, int data)
{
    if(index > array->count)
    {
        printf("Invalid index \n");
        return;
    }

    double_capacity_if_full(array);

    for(int i = array->count; i > index; i--)
    {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = data;
    array->count++;
}

void delete(Array* array, int index)
{
    if(index >= array->count)
    {
        printf("Invalid index \n");
        return;
    }

    for(int i = index; i < array->count; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->count--;
}

void update(Array* array, int index, int data)
{
    if(index >= array->count)
    {
        printf("Invalid index \n");
        return;
    }

    array->data[index] = data;
}

Array* merge(Array* a, Array* b)
{
    Array* c = create_array(a->count + b->count);

    for(int i = 0; i < a->count; i++)
    {
        insert(c, i, a->data[i]);
    }

    for(int i = 0; i < b->count; i++)
    {
        insert(c, a->count + i, b->data[i]);
    }

    return c;
}

void traverse(Array *array, void Visit(int*))
{
    for(int i = 0; i < array->count; i++)
    {
        Visit(&array->data[i]);   
    }
}

void print(int *data)
{
    printf("%d ", *data);
}

void destroy(Array *array)
{
    free(array->data);
    free(array);
}

int main() 
{
    Array *a = create_array(2);
    Array *b = create_array(2);

    insert(a, 0, 2);
    insert(a, 1, 5);
    insert(a, 0, 9);
    insert(a, 3, 10);
    traverse(a, print);
    printf("\n");

    delete(a, 1);
    traverse(a, print);
    printf("\n");

    update(a, 2, 19);
    traverse(a, print);
    printf("\n");
    
    insert(b, 0, 13);
    insert(b, 1, 98);
    traverse(b, print);
    printf("\n");
    Array *c = merge(a, b);
    traverse(c, print);
    printf("\n");

    destroy(a);
    destroy(b);
    destroy(c);
}