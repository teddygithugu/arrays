#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 9

void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate an array of random numbers
    int arr[MAX_ELEMENTS];
    for (int i = 0; i < MAX_ELEMENTS; ++i) {
        arr[i] = rand() % 100; // Generating random numbers between 0 and 99
    }

    // Print the original array
    printArray(arr, MAX_ELEMENTS);

    // Sort the array in ascending order
    qsort(arr, MAX_ELEMENTS, sizeof(int), compare);

    // Print the array in ascending order
    printf("Array in Ascending Order: ");
    printArray(arr, MAX_ELEMENTS);

    // Omit the middle element from the original array
    int omitIndex = MAX_ELEMENTS / 2;
    for (int i = omitIndex; i < MAX_ELEMENTS - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    // Print the array after omitting the middle element
    printf("Array after omitting middle element: ");
    printArray(arr, MAX_ELEMENTS - 1);

    // Insert the omitted element back into the array
    arr[omitIndex] = arr[MAX_ELEMENTS - 1];

    // Print the array after inserting the element back
    printf("Array after inserting element back: ");
    printArray(arr, MAX_ELEMENTS);

    // Delete the inserted element (set it to 0 or another sentinel value)
    arr[omitIndex] = 0;

    // Print the array after deleting the inserted element
    printf("Array after deleting inserted element: ");
    printArray(arr, MAX_ELEMENTS);

    return 0;
}
