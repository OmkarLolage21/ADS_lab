#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max 100
struct stack
{
    int v;
    struct stack *next;
};
struct stack *top = NULL;
int adj[max][max];
int n;
void BFS(int G[][max], int n);
void enqueue(int v);
int dequeue();
int emptyqueue();
int front = -1;
int rear = -1;
int queue[40];
void push(int);
int pop();
int notemptystack();
void dfs(int G[][max], int n);
int main()
{
    int maxE, i, j, origin, destin, ch;
    printf("Enter total number of vertices: ");
    scanf("%d", &n);
    maxE = n * (n - 1) / 2;
    for (i = 1; i <= maxE; i++)
    {
        printf("\nEnter Edge [ %d ] (-1 -1 to quit) : ", i);
        scanf("%d %d", &origin, &destin);
        if (origin == -1 && destin == -1)
        {
            break;
        }
        if (origin >= n || origin < 0 || destin >= n || destin < 0)
        {
            printf("\nInvalid vertex");
            i--;
        }
        else
        {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1;
        }
    }
    printf("\n BFS : ");
    BFS(adj, n);
    printf("\n DFS : ");
    dfs(adj, n);

    return 0;
}
void push(int n)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->v = n;
    temp->next = top;
    top = temp;
}
int pop()
{
    struct stack *temp = top;
    top = temp->next;
    int n = temp->v;
    free(temp);
    return n;
}
int notemptystack()
{
    return top != NULL;
}
void enqueue(int v)
{
    if (rear == -1 && front == -1)
    {
        rear = front = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = v;
}
int dequeue()
{
    int current_vertex = queue[front];
    front = front + 1;
    return current_vertex;
}
int emptyqueue()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    else
    {
        // printf("I am in returning true");
        return 0;
    }
}
void BFS(int G[][max], int n)
{
    int vis[10], v, i;
    for (i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    printf("Enter start vertex : ");
    scanf("%d", &v);
    vis[v] = 1;
    enqueue(v);
    while (!emptyqueue())
    {
        v = dequeue();
        printf("%d", v);
        for (i = 0; i < n; i++)
        {
            if (vis[i] == 0 && G[v][i] == 1)
            {
                enqueue(i);
                vis[i] = 1;
            }
        }
    }
}
void dfs(int G[][max], int n)
{
    int visited[10];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int v;
    printf("Enter start vertex :");
    scanf("%d", &v);
    push(v);
    visited[v] = 1;
    printf("%d - ", v);
    do
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (G[v][i] && visited[i] == 0)
            {
                printf("%d - ", i);
                push(i);
                visited[i] = 1;
                v = i;
                break;
            }
        }
        if (i == n)
        {
            pop();
            if (notemptystack())
                v = top->v;
        }

    } while (notemptystack());
}