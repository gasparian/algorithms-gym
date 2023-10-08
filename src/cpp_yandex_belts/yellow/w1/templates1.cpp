#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>
#include <string>
#include <tuple>
#include <map>

using namespace std;

// Предварительное объявление шаблонных функций
template<typename T> T Sqr(T x);
template<typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2);
template<typename First, typename Second> map<First, Second> operator*(const map<First, Second>& m1, const map<First, Second>& m2);
template<typename T> vector<T> operator*(const vector<T>& v1, const vector<T>& v2);

// Объявляем шаблонные функции
template <typename T>
T Sqr(T x) {
    return x * x;
}

template<typename First, typename Second> 
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;
    return make_pair(f, s);
}

template<typename First, typename Second> map<First, Second> operator*(const map<First, Second>& m1, const map<First, Second>& m2) {
    map<First, Second> res;
    for ( pair<First, Second> kv : m1) {
        res[kv.first] = kv.second * m2.at(kv.first);
    }
    return res;
}

template<typename T> vector<T> operator*(const vector<T>& v1, const vector<T>& v2) {
    vector<T> res(v1.size());
    for ( int i=0; i < v1.size(); i++ ) {
        res[i] = v1[i] * v2[i];
    }
    return res;
}

int main() {
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
    cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}

// vector: 1 4 9
// map of pairs:
// 4 4 4
// 7 16 9
