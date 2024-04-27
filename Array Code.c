#include <stdio.h>

int l_search(int nums[], int size, int key);
int b_search(int nums[], int size, int key);

int main() {
    int nums[20];
    int key, index,i;

    for ( i = 0; i < 20; i++) {
        nums[i] = 3 * i;
    }

    printf("Array:");
    for (i = 0; i < 20; i++) {
        printf(" %d", nums[i]);
    }
    printf("\n");

    printf("Please Enter the Search Key: ");
    scanf("%d", &key);

    index = l_search(nums, 20, key);
    if (index != -1) {
        printf("Linear Search Result: %d is found in the element with index %d\n", key, index);
    } else {
        printf("Linear Search Result: %d cannot be found.\n", key);
    }

    index = b_search(nums, 20, key);
    if (index != -1) {
        printf("Binary Search Result: %d is found in the element with index %d\n", key, index);
    } else {
        printf("Binary Search Result: %d cannot be found.\n", key);
    }

    return 0;
}

int l_search(int nums[], int size, int key) {
int i;
    for (i = 0; i < size; i++) {
        if (nums[i] == key) {
            return i;
        }
    }
    return -1;
}

int b_search(int nums[], int size, int key) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == key) {
            return mid;
        } else if (nums[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}