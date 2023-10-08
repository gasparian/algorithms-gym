#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    int size = v.size() - 1, temp;
    for ( int i = 0; i < ( (size + 1) / 2 ); ++i ) {
        temp = v[i];
        v[i] = v[size - i];
        v[size - i] = temp;
    } 
}

int main() {
    /*vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for ( auto x : numbers ) {
        cout << x << " ";
    }
    cout << endl;*/
    return 0;
}
