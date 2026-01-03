#include <iostream>
using namespace std;

int factorial(int num) {
    int result = 1;
    for (int i=1; i<=num; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num = 3;

    cout << num << " factorial: " << factorial(num) << '\n';

    return 0;
}