#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Dog {
    string name;
    int age;
};

int main() {
    vector<Dog> dogs;

    while (true) {
        Dog dog;

        cout << "Dog name: ";
        getline(cin, dog.name);
        if (dog.name.empty()) {
            break;
        }

        cout << dog.name << "'s age: ";
        cin >> dog.age;
        cin.ignore();

        dogs.push_back(dog);
        cout << "Dog added!\n\n";
    }

    cout << "\n--- Dogs ---\n";
    int i = 1;
    for (const Dog& dog : dogs) {
        cout << "Dog " << i++ << ": " << dog.name << ", " << dog.age << " years\n";
    }

    getchar();
    return 0;
}
