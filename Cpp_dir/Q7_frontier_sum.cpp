#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

int add_ends(int array[], int array_size) {
    return array[0] + array[array_size - 1];
}

int main() {
    int nums[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        nums[i] = i * 15 + 7;
    }

    cout << "Frontier sum: " << add_ends(nums, ARRAY_SIZE);

    return 0;
}
