#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If element is smaller than mid, search the left half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // Otherwise, search the right half
        else {
            left = mid + 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n-1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
