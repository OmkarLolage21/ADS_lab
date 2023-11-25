#include <stdio.h>

#define MAX_SIZE 10

struct TwoStacks
{
    int arr[MAX_SIZE];
    int top1; // Top pointer for Stack 1
    int top2; // Top pointer for Stack 2
};

// Initialize two stacks
void initialize(struct TwoStacks *stacks)
{
    stacks->top1 = -1;       // Initialize top pointer for Stack 1
    stacks->top2 = MAX_SIZE; // Initialize top pointer for Stack 2
}

// Check if Stack 1 is full
int isStack1Full(struct TwoStacks *stacks)
{
    return stacks->top1 + 1 == stacks->top2;
}

// Check if Stack 2 is full
int isStack2Full(struct TwoStacks *stacks)
{
    return stacks->top2 - 1 == stacks->top1;
}

// Check if Stack 1 is empty
int isStack1Empty(struct TwoStacks *stacks)
{
    return stacks->top1 == -1;
}

// Check if Stack 2 is empty
int isStack2Empty(struct TwoStacks *stacks)
{
    return stacks->top2 == MAX_SIZE;
}

// Push an element to Stack 1
void pushStack1(struct TwoStacks *stacks, int value)
{
    if (isStack1Full(stacks))
    {
        printf("Stack 1 is full. Cannot push.\n");
    }
    else
    {
        stacks->arr[++stacks->top1] = value;
    }
}

// Push an element to Stack 2
void pushStack2(struct TwoStacks *stacks, int value)
{
    if (isStack2Full(stacks))
    {
        printf("Stack 2 is full. Cannot push.\n");
    }
    else
    {
        stacks->arr[--stacks->top2] = value;
    }
}

// Pop an element from Stack 1
int popStack1(struct TwoStacks *stacks)
{
    if (isStack1Empty(stacks))
    {
        printf("Stack 1 is empty. Cannot pop.\n");
        return -1; // Indicates an error
    }
    else
    {
        return stacks->arr[stacks->top1--];
    }
}

// Pop an element from Stack 2
int popStack2(struct TwoStacks *stacks)
{
    if (isStack2Empty(stacks))
    {
        printf("Stack 2 is empty. Cannot pop.\n");
        return -1; // Indicates an error
    }
    else
    {
        return stacks->arr[stacks->top2--];
    }
}

// Display Stack 1
void displayStack1(struct TwoStacks *stacks)
{
    printf("Stack 1: ");
    for (int i = 0; i <= stacks->top1; i++)
    {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");
}

// Display Stack 2
void displayStack2(struct TwoStacks *stacks)
{
    printf("Stack 2: ");
    for (int i = MAX_SIZE - 1; i >= stacks->top2; i--)
    {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct TwoStacks stacks;
    initialize(&stacks);

    pushStack1(&stacks, 1);
    pushStack1(&stacks, 2);
    pushStack2(&stacks, 3);
    pushStack2(&stacks, 4);

    displayStack1(&stacks);
    displayStack2(&stacks);

    printf("Popped from Stack 1: %d\n", popStack1(&stacks));
    printf("Popped from Stack 2: %d\n", popStack2(&stacks));

    displayStack1(&stacks);
    displayStack2(&stacks);

    return 0;
}
