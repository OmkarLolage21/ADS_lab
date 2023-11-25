#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a student
struct Student
{
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

// Function to perform heapify operation in Heap Sort
void heapify(struct Student arr[], int n, int i, int *swapCount)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].student_roll_no > arr[largest].student_roll_no)
    {
        largest = left;
    }

    if (right < n && arr[right].student_roll_no > arr[largest].student_roll_no)
    {
        largest = right;
    }

    if (largest != i)
    {
        // Swap arr[i] and arr[largest]
        struct Student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*swapCount)++;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, swapCount);
    }
}

// Function to perform Heap Sort on an array of students
void heapSort(struct Student arr[], int n, int *swapCount)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, swapCount);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Swap the root (maximum element) with the last element
        struct Student temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        (*swapCount)++;

        // Heapify the reduced heap
        heapify(arr, i, 0, swapCount);
    }
}

// Function to partition the array for Quick Sort
int partition(struct Student arr[], int low, int high, int *swapCount)
{
    struct Student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].student_roll_no <= pivot.student_roll_no)
        {
            i++;
            // Swap arr[i] and arr[j]
            struct Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*swapCount)++;
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    struct Student temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    (*swapCount)++;

    return i + 1;
}

// Function to perform Quick Sort on an array of students
void quickSort(struct Student arr[], int low, int high, int *swapCount)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high, swapCount);

        // Recursively sort the elements before and after the pivot
        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

// Function to display the array of students
void displayArray(struct Student arr[], int n)
{
    printf("Roll No\t\tName\t\tTotal Marks\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%s\t\t%d\n", arr[i].student_roll_no, arr[i].student_name, arr[i].total_marks);
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    printf("Enter student details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].student_roll_no);
        printf("Name: ");
        scanf("%s", students[i].student_name);
        printf("Total Marks: ");
        scanf("%d", &students[i].total_marks);
    }

    // Make a copy of the original array for each sorting algorithm
    struct Student *heapSortArray = (struct Student *)malloc(n * sizeof(struct Student));
    struct Student *quickSortArray = (struct Student *)malloc(n * sizeof(struct Student));
    memcpy(heapSortArray, students, n * sizeof(struct Student));
    memcpy(quickSortArray, students, n * sizeof(struct Student));

    int heapSortSwapCount = 0;
    int quickSortSwapCount = 0;

    // Perform Heap Sort
    heapSort(heapSortArray, n, &heapSortSwapCount);
    printf("\nSorted array using Heap Sort:\n");
    displayArray(heapSortArray, n);
    printf("Number of swaps in Heap Sort: %d\n", heapSortSwapCount);

    // Perform Quick Sort
    quickSort(quickSortArray, 0, n - 1, &quickSortSwapCount);
    printf("\nSorted array using Quick Sort:\n");
    displayArray(quickSortArray, n);
    printf("Number of swaps in Quick Sort: %d\n", quickSortSwapCount);

    free(students);
    free(heapSortArray);
    free(quickSortArray);

    return 0;
}
