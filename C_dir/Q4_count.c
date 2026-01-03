#include <stdio.h>

int count_digits(int num) {
    if (num == 0) {
        return 1;
    }

    int digits_count = 0;
    while (num > 0) {
        num /= 10;
        ++digits_count;
    }
    return digits_count;
}

int main() {
    int num = 31415;

    printf("%d digits count: %d", num, count_digits(num));

    return 0;
}