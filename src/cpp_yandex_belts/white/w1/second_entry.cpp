#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int c = 0, pos = -2;
    cin >> input;

    for (auto i=0; i < input.size(); ++i) {
       if (input[i] == 'f') {
           c += 1;
       }
       if (c == 2) {
           pos = i;
           break;
       }
    }
    if (c == 1) {
        pos = -1;
    }
    cout << to_string(pos);

    return 0;
}


