#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <initializer_list>

using namespace std;

template <typename T>
class Deque {
public:
    Deque() : front({}), back({}) {}
    Deque(const vector<T>& inp) : front(inp), back(inp) {
        reverse(front.begin(), front.end());
        count = front.size();
    }
    Deque(initializer_list<T> init) : front(init), back(init) {
        reverse(front.begin(), front.end());
        count = front.size();
    }
    Deque(size_t countIn, const T& value) {
        this->count = value;
        front.resize(countIn, value);
        reverse(front.begin(), front.end());
        back.resize(countIn, value);
    }
    Deque(typename vector<T>::iterator first, typename vector<T>::iterator last) {
        for ( auto it = first; it != last; it++ ) {
            front.push_back(*it);
            back.push_back(*it);
        }
        reverse(front.begin(), front.end());
        this->count = front.size();
    }
    bool Empty() const {
        if ( this->count == 0 )
            return true;
        return false;
    }
    size_t Size() const {
        return this->count;
    }
    T& operator[](size_t index) {
        return this->At(index);
    }
    const T& operator[](size_t index) const {
        return this->At(index);
    }
    T& At(size_t index) {
        if ( index < this->count ) {
            if ( index < front.size() ) {
                return front[front.size() - 1 - index];
            } else {
                return back[index - (this->count - back.size())];
            }
        } else {
            throw out_of_range("");
        }
    }
    const T& At(size_t index) const {
        if ( index < this->count ) {
            if ( index < front.size() ) {
                return front[front.size() - 1 - index];
            } else {
                return back[index - (this->count - back.size())];
            }
        } else {
            throw out_of_range("");
        }
    }
    T& Front() {
        return this->At(0);
    }
    const T& Front() const {
        return this->At(0);
    }
    T& Back() {
        return this->At(this->count-1);
    }
    const T& Back() const {
        return this->At(this->count-1);
    }
    void PushFront(const T& inp) {
        front.push_back(inp);
        count++;
    }
    void PushBack(const T& inp) {
        back.push_back(inp);
        count++;
    }

private:
    vector<T> front;
    vector<T> back;
    int count = 0;
};

int main() {
    // Deque<int> ex0 = {};
    // int val0 = ex0.Front();

    Deque<int> ex1 = {1, 2, 3};

    vector<int> ex2 = {1, 2, 3};
    Deque<int> ex3(ex2.begin(), ex2.end());

    Deque<int> ex4{1, 2, 3};
    int val1 = ex4.At(0);
    cout << val1 << endl;

    int val2 = ex4[2];
    cout << "Size: " << ex4.Size() << endl;
    cout << "Value: " << val2 << endl;

    Deque<int> ex5{1, 2, 3};
    ex5.PushFront(0);
    ex5.PushBack(4);
    ex5.PushBack(5);
    int val3 = ex5[3];
    cout << "Size: " << ex5.Size() << endl;
    cout << "Value: " << val3 << endl;
    return 0;
}