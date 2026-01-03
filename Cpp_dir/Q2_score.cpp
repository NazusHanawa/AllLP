#include <iostream>
using namespace std;

const char* is_pass_or_fail(int score) {
    if (score > 60) {
        return "Pass";
    } else {
        return "Fail";
    }
}

int main() {
    int a_score = 55, b_score = 77;

    cout << "Score A (" << a_score << "): " << is_pass_or_fail(a_score) << endl;
    cout << "Score B (" << b_score << "): " << is_pass_or_fail(b_score) << endl;

    return 0;
}

