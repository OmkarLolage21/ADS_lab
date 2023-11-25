#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table
#define TABLE_SIZE 10

// Structure for each element in the hash table
struct HashElement
{
    int key;
    int data;
};

// Structure for the hash table
struct HashTable
{
    struct HashElement table[TABLE_SIZE];
};

// Initialize the hash table
void initializeHashTable(struct HashTable *hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable->table[i].key = -1; // -1 indicates an empty slot
    }
}

// Hash function for linear probing
int linearProbingHash(int key, int attempt)
{
    return (key + attempt) % TABLE_SIZE;
}

// Hash function for quadratic probing
int quadraticProbingHash(int key, int attempt)
{
    return (key + attempt * attempt) % TABLE_SIZE;
}

// Hash function for double hashing
int doubleHashingHash(int key, int attempt)
{
    // Use a second hash function (e.g., a simple one like linear probing)
    int secondHash = 3; // a constant for simplicity
    return (key + attempt * secondHash) % TABLE_SIZE;
}

// Function to insert an element into the hash table using linear probing
int insertLinearProbing(struct HashTable *hashTable, int key, int data)
{
    int attempt = 0;
    int index;

    do
    {
        index = linearProbingHash(key, attempt);

        // Check if the slot is empty
        if (hashTable->table[index].key == -1)
        {
            hashTable->table[index].key = key;
            hashTable->table[index].data = data;
            return attempt; // Return the number of attempts (collisions)
        }

        attempt++;
    } while (attempt < TABLE_SIZE);

    return -1; // Unable to insert (table is full)
}

// Function to insert an element into the hash table using quadratic probing
int insertQuadraticProbing(struct HashTable *hashTable, int key, int data)
{
    int attempt = 0;
    int index;

    do
    {
        index = quadraticProbingHash(key, attempt);

        // Check if the slot is empty
        if (hashTable->table[index].key == -1)
        {
            hashTable->table[index].key = key;
            hashTable->table[index].data = data;
            return attempt; // Return the number of attempts (collisions)
        }

        attempt++;
    } while (attempt < TABLE_SIZE);

    return -1; // Unable to insert (table is full)
}

// Function to insert an element into the hash table using double hashing
int insertDoubleHashing(struct HashTable *hashTable, int key, int data)
{
    int attempt = 0;
    int index;

    do
    {
        index = doubleHashingHash(key, attempt);

        // Check if the slot is empty
        if (hashTable->table[index].key == -1)
        {
            hashTable->table[index].key = key;
            hashTable->table[index].data = data;
            return attempt; // Return the number of attempts (collisions)
        }

        attempt++;
    } while (attempt < TABLE_SIZE);

    return -1; // Unable to insert (table is full)
}

// Function to display the contents of the hash table
void displayHashTable(struct HashTable *hashTable)
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable->table[i].key != -1)
        {
            printf("Index %d: Key=%d, Data=%d\n", i, hashTable->table[i].key, hashTable->table[i].data);
        }
        else
        {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main()
{
    struct HashTable linearProbingTable, quadraticProbingTable, doubleHashingTable;
    initializeHashTable(&linearProbingTable);
    initializeHashTable(&quadraticProbingTable);
    initializeHashTable(&doubleHashingTable);

    int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int dataSize = sizeof(data) / sizeof(data[0]);

    // Insert data into hash tables using different probing techniques
    int linearCollisions = 0, quadraticCollisions = 0, doubleHashingCollisions = 0;

    for (int i = 0; i < dataSize; i++)
    {
        linearCollisions += insertLinearProbing(&linearProbingTable, data[i], data[i]);
        quadraticCollisions += insertQuadraticProbing(&quadraticProbingTable, data[i], data[i]);
        doubleHashingCollisions += insertDoubleHashing(&doubleHashingTable, data[i], data[i]);
    }

    // Display the contents of hash tables
    printf("\nLinear Probing:\n");
    displayHashTable(&linearProbingTable);
    printf("Collisions: %d\n", linearCollisions);

    printf("\nQuadratic Probing:\n");
    displayHashTable(&quadraticProbingTable);
    printf("Collisions: %d\n", quadraticCollisions);

    printf("\nDouble Hashing:\n");
    displayHashTable(&doubleHashingTable);
    printf("Collisions: %d\n", doubleHashingCollisions);

    return 0;
}
