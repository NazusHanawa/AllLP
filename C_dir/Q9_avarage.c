#include <stdio.h>

int NUMS_SIZE = 10;

double get_avarage_value(int* nums, int size) {
    int total_value = 0;
    for (int i=0; i<size; ++i) {
        total_value += nums[i];
    }

    return (double) total_value / size;
}

int main() {
    int nums[NUMS_SIZE];

    for (int i=0; i<NUMS_SIZE; ++i) {
        nums[i] = 7 * (i + 1);
    }

    printf("Avarage: %.2lf", get_avarage_value(nums, NUMS_SIZE));

    return 0;
}