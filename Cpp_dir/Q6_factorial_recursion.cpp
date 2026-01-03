#include <iostream>
using namespace std;

int factorial(int num) {
    if (num == 1) {
        return 1;
    }

    return factorial(num - 1) * num;
}

int main() {
    int num = 5;

    cout << num << " factorial: " << factorial(num);

    return 0;
}
