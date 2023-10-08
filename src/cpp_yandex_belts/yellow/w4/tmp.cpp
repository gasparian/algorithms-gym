#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

bool f(int inp) {
    if ( inp % 2 )
      return true;
    return false;
}

template<typename T>
void PrintVec(T V) {
    for ( auto el : V )
        cout << el << " ";
    cout << endl;
}

int main() {
    // set<int> s = { 1, 6, 4, 9 };
    // vector<int> v;

    // v.assign(begin(s), end(s));
    // auto it = remove_if(begin(v), end(v),
    //                     [](int x) { return !f(x); });
    // v.erase(it, end(v));

    // v.assign(begin(s), end(s));
    // auto it = partition(begin(v), end(v), f);
    // v.erase(begin(v), it);

    // vector<int> garbage;
    // partition_copy(
    //     begin(s), end(s),
    //     back_inserter(v), back_inserter(garbage), f);

    // v.assign(begin(s), end(s));
    // sort(begin(v), end(v),
    //     [](int lhs, int rhs) { return f(lhs) > f(rhs); });
    // auto it = partition_point(begin(v), end(v), f);
    // v.erase(begin(v), it);

    // v.assign(begin(s), end(s));
    // auto it = partition(begin(v), end(v), f);
    // v.erase(it, end(v));

    // copy_if(begin(s), end(s), back_inserter(v), f);

    // vector<int> garbage;
    // partition_copy(
    //     begin(s), end(s),
    //     back_inserter(garbage), back_inserter(v), f);

    // remove_copy_if(begin(s), end(s), back_inserter(v), f);

    // copy_if(begin(s), end(s), back_inserter(v),
    //         [](int x) { return !f(x); });

    // auto it = partition(begin(s), end(s), f);
    // copy(it, end(s), back_inserter(v));

    // v.assign(begin(s), end(s));
    // auto it = remove_if(begin(v), end(v), f);
    // v.erase(it, end(v));

    // v.assign(begin(s), end(s));
    // sort(begin(v), end(v),
    //     [](int lhs, int rhs) { return f(lhs) > f(rhs); });
    // auto it = partition_point(begin(v), end(v), f);
    // v.erase(it, end(v));

    // remove_copy_if(begin(s), end(s), back_inserter(v),
    //             [](int x) { return !f(x); });

    // auto it = remove_if(begin(s), end(s),
    //                     [](int x) { return !f(x); });
    // copy(it, end(s), back_inserter(v));

    // PrintVec(v);

    /////////////////////////////////////////////////////////////////////////////

    vector<int> vec;
    auto vector_begin = begin(vec);
    auto vector_end = end(vec);

    string str;
    auto string_begin = begin(str);
    auto string_end = end(str);

    set<int> s;
    auto set_begin = begin(s);
    auto set_end = end(s);

    // partial_sum(set_begin, set_end, back_inserter(vec));
    // auto res = next_permutation(set_begin, set_end);
    // auto res = is_heap(string_begin, string_end);
    // auto res = is_heap(set_begin, set_end);
    // auto res = is_permutation(vector_begin, vector_end, vector_begin);
    // partial_sum(set_begin, set_end, vector_begin);
    // auto res = next_permutation(string_begin, string_end);
    // partial_sum(vector_begin, vector_end, set_begin);
    // auto res = is_permutation(set_begin, set_end, back_inserter(vec));
    // auto res = accumulate(vector_begin, vector_end, 0);
    // auto res = accumulate(set_begin, set_end, 0);
    // auto res = is_permutation(set_begin, set_end, vector_begin);

    // vec = {9, 4, 5, 10, 1};
    // auto it = is_sorted_until(vec.begin(), vec.end());
    // cout << *it << " " << vec[*it] << endl;

    return 0;
}
