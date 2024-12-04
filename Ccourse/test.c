#include <stdio.h>

typedef struct {
    int value;
} Element;

int binarySearch(Element nums[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid].value == target) {
            return mid;
        }
        else if (nums[mid].value < target) {
            left = mid + 1;
        }
        else { // nums[mid].value > target
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    Element nums[] = {{1}, {3}, {5}, {7}, {9}};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 5;

    int result = binarySearch(nums, size, target);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
