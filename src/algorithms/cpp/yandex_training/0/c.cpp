#include <iostream>
#include <vector>

using namespace std;

vector <double> MovingAverage(const vector <int> &arr, int windowSize) {
	vector<double> res(arr.size()-windowSize+1);
	double windowSum = 0;
	for (int i = 0; i < windowSize; i++) {
		windowSum += arr[i];
	}
	res[0] = windowSum / windowSize;
	for (int i = windowSize; i < (int)arr.size(); i++) {
		windowSum = windowSum - arr[i-windowSize] + arr[i];
		res[i-windowSize+1] = windowSum / windowSize;
	}
	return res;
}

void print(const vector <double> &result) {
	for (double x : result)
		cout << x << " ";
	cout << endl;
}

int main() {
	int n, windowSize;
	cin >> n;
	vector <int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> windowSize;
	print(MovingAverage(arr, windowSize));
}

/*
7
1 2 3 4 5 6 7
4

2.5 3.5 4.5 5.5

9
9 3 2 0 1 5 1 0 0
3

4.6666666667 1.666666667 1 2 2.333333335 2 0.3333333

5
1 2 3 4 5
5

3
*/