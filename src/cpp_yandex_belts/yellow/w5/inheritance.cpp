#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& n = "Animal") : Name(n) {
    }
    const string Name;
};


class Dog : public Animal {
public:
    Dog(const string& n = "Dog") : Animal(n) {
    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

// int main() {
//     Dog d;
//     d.Bark();
//     return 0;
// }
