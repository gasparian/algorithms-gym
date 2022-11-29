#include <iostream>
#include <vector>

using namespace std;

vector <int> Zip(const vector <int> &a, const vector <int> &b) {
	int n = a.size();
	vector<int> res(2*n);
	for (int i = 0; i < n; i++) {
		res[2*i] = a[i];
		res[2*i+1] = b[i];
	}
	return res;
}

void print(const vector <int> &result) {
	for (int x : result)
		cout << x << " ";
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	print(Zip(a, b));
}

/*
3
1 2 3
4 5 6

1 4 2 5 3 6

1
1
2

1 2

3
1 8 9
2 3 1

1 2 8 3 9 1
*/