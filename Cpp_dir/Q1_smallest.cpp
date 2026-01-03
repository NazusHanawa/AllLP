#include <iostream>
using namespace std;

int find_smallest(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int main() {
    int a = 5, b = 17;

    cout << "The smallest between " << a << " and " << b << " is " << find_smallest(a, b);

    return 0;
}
