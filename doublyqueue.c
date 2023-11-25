#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Structure for the queue
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initializeQueue(struct Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue *queue, int value)
{
    struct Node *newNode = createNode(value);
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", value);
}

// Function to dequeue (delete) an element from the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow. Cannot dequeue from an empty queue.\n");
        return -1;
    }

    struct Node *temp = queue->front;
    int dequeuedValue = temp->data;

    if (temp->next != NULL)
    {
        temp->next->prev = NULL;
    }

    queue->front = temp->next;

    free(temp);

    printf("Dequeued %d from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the elements of the queue
void displayQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node *temp = queue->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated for the queue
void freeQueue(struct Queue *queue)
{
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }
}

int main()
{
    struct Queue queue;
    initializeQueue(&queue);

    // Enqueue operations
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Display the queue
    displayQueue(&queue);

    // Dequeue operations
    dequeue(&queue);
    dequeue(&queue);

    // Display the queue after dequeuing
    displayQueue(&queue);

    // Free memory
    freeQueue(&queue);

    return 0;
}
