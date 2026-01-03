#include <stdio.h>

char* is_pass_or_fail(int score) {
    if (score > 60) {
        return "Pass";
    } else {
        return "Fail";
    }
}

int main() {
    int a_score = 55, b_score = 77;

    printf("Score A (%d): %s\n", a_score, is_pass_or_fail(a_score));
    printf("Score B (%d): %s\n", b_score, is_pass_or_fail(b_score));

    return 0;
}