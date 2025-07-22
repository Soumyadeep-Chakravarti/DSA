#include <stdio.h>
#include <stdlib.h>

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}

// Test both versions
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\nChoose Number to search: ");
    scanf("%d",&key);


    // Iterative version
    int resultIter = binarySearchIterative(arr, n, key);
    if (resultIter != -1)
        printf("Iterative: Element %d found at index %d\n", key, resultIter);
    else
        printf("Iterative: Element %d not found\n", key);

    // Recursive version
    int resultRec = binarySearchRecursive(arr, 0, n - 1, key);
    if (resultRec != -1)
        printf("Recursive: Element %d found at index %d\n", key, resultRec);
    else
        printf("Recursive: Element %d not found\n", key);

    return 0;
}
