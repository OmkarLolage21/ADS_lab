#include <stdio.h>
#define MAX 10

// Structure for Stack
struct Stack
{
    int arr[MAX];
    int top;
};
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to calculate factorial using stack
int factorial(int n)
{
    struct Stack stack;
    initialize(&stack);

    // Push numbers from 1 to n onto the stack
    for (int i = 1; i <= n; i++)
    {
        push(&stack, i);
    }

    // Multiply the numbers by popping them from the stack
    int result = 1;
    while (!isEmpty(&stack))
    {
        result *= pop(&stack);
    }

    return result;
}

int main()
{
    // Test the factorial function
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));

    return 0;
}
