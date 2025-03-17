#include <stdio.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void linearSearch(int arr[], int n, int key);
void binarySearch(int arr[], int n, int key);
void displayArray(int arr[], int n);

int main() {
    int n, key, choice;

    // Asking for number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Array declaration

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Asking if the user wants to search first
    printf("\nDo you want to perform a search?\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Array must be sorted first)\n");
    printf("3. No, show sorting options\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter element to search: ");
            scanf("%d", &key);
            linearSearch(arr, n, key);
            return 0; // End program after search
        case 2:
            printf("Enter element to search: ");
            scanf("%d", &key);
            binarySearch(arr, n, key);
            return 0; // End program after search
        case 3:
            break; // Proceed to sorting menu
        default:
            printf("Invalid choice! Exiting program.\n");
            return 0;
    }

    // Sorting Menu
    do {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                printf("Array sorted using Bubble Sort.\n");
                break;
            case 2:
                selectionSort(arr, n);
                printf("Array sorted using Selection Sort.\n");
                break;
            case 3:
                insertionSort(arr, n);
                printf("Array sorted using Insertion Sort.\n");
                break;
            case 4:
                displayArray(arr, n);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort Algorithm
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort Algorithm
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Linear Search Algorithm
void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d\n", key, i + 1);
            return;
        }
    }
    printf("Element %d not found in the array.\n", key);
}

// Binary Search Algorithm (Array must be sorted first)
void binarySearch(int arr[], int n, int key) {
    bubbleSort(arr, n); // Ensure the array is sorted before binary search
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid + 1);
            return;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element %d not found in the array.\n", key);
}

// Function to display the array
void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
