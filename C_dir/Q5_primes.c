#include <stdio.h>

int is_prime(int num) {
    for (int i=2; i<num; ++i) {
        if (num % i == 0) { 
            return 0;
        }
    }

    return 1;
}

int main() {
    int num = 73, num_isprime;

    num_isprime = is_prime(num);
    if (num_isprime == 1) {
        printf("%d is prime.", num);
    } else {
        printf("%d is not prime.", num);
    }

    return 0;
}