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

// Function to merge two subarrays in Merge Sort
void merge(struct Student arr[], int left, int middle, int right, int *swapCount)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    struct Student *leftArray = (struct Student *)malloc(n1 * sizeof(struct Student));
    struct Student *rightArray = (struct Student *)malloc(n2 * sizeof(struct Student));

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (i = 0; i < n1; i++)
    {
        leftArray[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        rightArray[j] = arr[middle + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (leftArray[i].student_roll_no <= rightArray[j].student_roll_no)
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
            (*swapCount) += (middle - left + 1 - i); // Count swaps for inversion count
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(leftArray);
    free(rightArray);
}

// Function to perform Merge Sort on an array of students
void mergeSort(struct Student arr[], int left, int right, int *swapCount)
{
    if (left < right)
    {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, middle, swapCount);
        mergeSort(arr, middle + 1, right, swapCount);

        // Merge the sorted halves
        merge(arr, left, middle, right, swapCount);
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
    struct Student *mergeSortArray = (struct Student *)malloc(n * sizeof(struct Student));
    memcpy(heapSortArray, students, n * sizeof(struct Student));
    memcpy(mergeSortArray, students, n * sizeof(struct Student));

    int heapSortSwapCount = 0;
    int mergeSortSwapCount = 0;

    // Perform Heap Sort
    heapSort(heapSortArray, n, &heapSortSwapCount);
    printf("\nSorted array using Heap Sort:\n");
    displayArray(heapSortArray, n);
    printf("Number of swaps in Heap Sort: %d\n", heapSortSwapCount);

    // Perform Merge Sort
    mergeSort(mergeSortArray, 0, n - 1, &mergeSortSwapCount);
    printf("\nSorted array using Merge Sort:\n");
    displayArray(mergeSortArray, n);
    printf("Number of swaps in Merge Sort: %d\n", mergeSortSwapCount);

    free(students);
    free(heapSortArray);
    free(mergeSortArray);

    return 0;
}
