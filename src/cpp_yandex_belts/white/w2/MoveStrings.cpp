#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for ( auto w : source ) {
        destination.push_back(w);
    }
    source.clear();
}

int main() {
    /*vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for ( auto w : destination ) {
        cout << w << " ";
    }
    cout << endl;*/
    return 0;
}
