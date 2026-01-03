#include <stdio.h>

int NUMS_SIZE = 10;

int get_max_value(int* nums, int size) {
    int max_value = nums[0];
    for (int i=1; i<size; ++i) {
        if (max_value < nums[i]) {
            max_value = nums[i];
        }
    }

    return max_value;
}

int main() {
    int nums[NUMS_SIZE];

    for (int i=0; i<NUMS_SIZE; ++i) {
        nums[i] = 25 * (i + 1);
    }

    printf("Max: %d", get_max_value(nums, NUMS_SIZE));

    return 0;
}