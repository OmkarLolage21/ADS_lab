#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the structure for an employee record
struct Employee
{
    int empId;
    char name[50];
    // You can include other employee information here
    struct Employee *left;
    struct Employee *right;
};

// Function to create a new employee node
struct Employee *createEmployee(int empId, const char *name)
{
    struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
    newEmployee->empId = empId;
    strcpy(newEmployee->name, name);
    newEmployee->left = NULL;
    newEmployee->right = NULL;
    return newEmployee;
}

// Function to insert an employee into the BST
struct Employee *insertEmployee(struct Employee *root, int empId, const char *name)
{
    if (root == NULL)
    {
        return createEmployee(empId, name);
    }
    if (empId < root->empId)
    {
        root->left = insertEmployee(root->left, empId, name);
    }
    else
    {
        root->right = insertEmployee(root->right, empId, name);
    }
    return root;
}

// Function to search for an employee by emp-id in the BST
struct Employee *searchEmployee(struct Employee *root, int empId)
{
    if (root == NULL || root->empId == empId)
    {
        return root;
    }
    if (empId < root->empId)
    {
        return searchEmployee(root->left, empId);
    }
    return searchEmployee(root->right, empId);
}

// Function to perform an in-order traversal to print employees in ascending order
void printEmployeesAscending(struct Employee *root)
{
    if (root != NULL)
    {
        printEmployeesAscending(root->left);
        printf("Emp ID: %d, Name: %s\n", root->empId, root->name);
        printEmployeesAscending(root->right);
    }
}

int main()
{
    struct Employee *root = NULL;
    int n; // Number of employees

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int empId;
        char name[50];
        printf("Enter Emp ID for employee %d: ", i + 1);
        scanf("%d", &empId);
        printf("Enter name for employee %d: ", i + 1);
        scanf("%s", name);
        root = insertEmployee(root, empId, name);
    }

    int searchEmpId;
    printf("Enter Emp ID to search: ");
    scanf("%d", &searchEmpId);

    struct Employee *foundEmployee = searchEmployee(root, searchEmpId);
    if (foundEmployee)
    {
        printf("Employee found: Emp ID: %d, Name: %s\n", foundEmployee->empId, foundEmployee->name);
    }
    else
    {
        printf("Employee not found.\n");
    }

    printf("\nEmployees Sorted by Emp ID (Ascending Order):\n");
    printEmployeesAscending(root);

    return 0;
}
