#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index of the key if found
        }
    }
    return -1; // Return -1 if the key is not found
}

// Function for Binary Search
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid index

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid; // Return the index if found
        }

        // If the key is greater, ignore the left half
        if (arr[mid] < key) {
            left = mid + 1;
        } else { // If the key is smaller, ignore the right half
            right = mid - 1;
        }
    }
    return -1; // Return -1 if the key is not found
}

// Function to print the array
void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n, key, choice;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Create an array of size n

    printf("Enter %d elements (sorted for binary search):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nChoose an option:\n");
        printf("1. Perform Linear Search\n");
        printf("2. Perform Binary Search\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                
                // Call linear search function
                int linearResult = linearSearch(arr, n, key);
                
                // Output the result
                if (linearResult != -1) {
                    printf("Element %d found at index: %d\n", key, linearResult);
                } else {
                    printf("Element %d not found in the array.\n", key);
                }
                break;

            case 2:
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                
                // Call binary search function
                int binaryResult = binarySearch(arr, n, key);
                
                // Output the result
                if (binaryResult != -1) {
                    printf("Element %d found at index: %d\n", key, binaryResult);
                } else {
                    printf("Element %d not found in the array.\n", key);
                }
                break;

            case 3:
                printArray(arr, n);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0;
}
