#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> numbers;

    numbers.push_front(15);
    numbers.push_front(25);
    numbers.push_front(300);

    cout << "List: ";
    for (int value : numbers) {
        cout << value << " -> ";
    }
    cout << "NULL\n";

    return 0;
}
