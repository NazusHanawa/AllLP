#include <stdio.h>

int factorial(int num) {
    if (num == 1) {
        return 1;
    }

    return factorial(num-1) * num;
}

int main() {
    int num = 5;

    printf("%d factorial: %d", num, factorial(num));

    return 0;
}