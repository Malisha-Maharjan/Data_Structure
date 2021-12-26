#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

#define SIZE 100

bool IsOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '(' || c == ')';
}

bool IsOperand(char c)
{
    return !IsOperator(c);
}

int PrecedenceLevel(char operator)
{
    switch (operator)
    {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        case '$':
            return 2;
        case '(':
        case ')':
            return 3;
        default:
            printf("Invalid operator: %c \n", operator);
            return -1;
    }
        
}

bool HasPrecedence(char operator1, char operator2)
{
    if(operator1 == '('|| operator2 == '(')
        return false;
    if(operator2 == ')')
        return true;
    if(operator1 == ')')
    {
        printf("Invalid use of operator1");
        return false;
    }

    int precedence1 = PrecedenceLevel(operator1);
    int precedence2 = PrecedenceLevel(operator2);
    return operator1 == '$' ? precedence1 > precedence2 : precedence1 >= precedence2;
}

void InfixToPostfix(char *infix, char *postfix)
{
    Stack operatorStack;
    CreateStack(&operatorStack);

    int i = 0;
    int j = 0;
    while(infix[i] != '\0')
    {
        char symbol = infix[i++];
        if(IsOperand(symbol))
        {
            postfix[j++] = symbol;
            continue;
        }

        while(!StackEmpty(&operatorStack) && HasPrecedence(Top(&operatorStack), symbol)) {
            char top = Pop(&operatorStack);
            postfix[j++] = top;
        }
        
        if(StackEmpty(&operatorStack) || symbol != ')')
            Push(&operatorStack, symbol);
        else
            Pop(&operatorStack);
    }
    
    while(!StackEmpty(&operatorStack))
        postfix[j++] = Pop(&operatorStack);

    postfix[j] = '\0';
}

int main() 
{
    char infix[SIZE];
    char postfix[SIZE];

    while(strcmp(infix, "exit") != 0)
    {
        printf("infix: ");
        scanf("%s", infix);
        InfixToPostfix(infix, postfix);
        printf("%s\n\n", postfix);
    }

    return 0;
}