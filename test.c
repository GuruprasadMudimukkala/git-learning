#include <stdio.h>

int main() {
    int array[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int i, j;
    
    // Find the maximum value in the array to dynamically size the count array
    int maxValue = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }

    // Initialize count array
    int count[maxValue + 1];
    for (i = 0; i <= maxValue; i++) {
        count[i] = 0;
    }

    // Count occurrences of each number in the array
    for (i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Print occurrences for each number (up to the maximum value found)
    for (j = 0; j <= maxValue; j++) {
        if (count[j] > 0) {
            printf("Occurrences of [%d]: %d\n", j, count[j]);
        }
    }

    // Create a new array without duplicates
    int newarray[size];
    int newsize = 0;
    
    for (i = 0; i < size; i++) {
        if (count[array[i]] > 0) {
            newarray[newsize++] = array[i];
            count[array[i]] = 0;  // Mark as added to the new array
        }
    }

    // Print the new array with unique elements
    printf("\nNew Array (without duplicates):\n");
    for (j = 0; j < newsize; j++) {
        printf("%d ", newarray[j]);
    }
    printf("\n");

    return 0;
}
