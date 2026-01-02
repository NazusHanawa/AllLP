#include <stdio.h>

int count_digits(int num) {
    int digits_count = 0;
    while (num > 0) {
        num /= 10;
        printf("Num: %d\n", num);
        ++digits_count;
    }
    return digits_count;
}

int main() {
    int num = 31415;

    printf("%d digits count: %d", num, count_digits(num));

    return 0;
}