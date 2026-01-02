#include <stdio.h>

int find_smallest(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int main() {
    int a = 5, b = 17;

    printf("The smallest between %d and %d is %d", a, b, find_smallest(a, b));

    return 0;
}
