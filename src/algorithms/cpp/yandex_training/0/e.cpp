#include <iostream>
#include <vector>

using namespace std;

vector <int> TwoSum(const vector <int> &sortedArr, int targetSum) {
	int i, j;
	for (i = 0, j = (int)sortedArr.size()-1; i < j;) {
		int sum = sortedArr[i] + sortedArr[j];
		if (sum > targetSum) {
			j--;
		} else if (sum < targetSum) {
			i++;
		} else {
			return {sortedArr[i], sortedArr[j]};
		}
	}
	return {};

}

void print(const vector <int> &result) {
	if (result.size() != 2)
		cout << "None" << endl;
	else
		cout << result[0] << " " << result[1] << endl;
}

int main() {
	int n, targetSum;
	cin >> n;
	vector <int> sortedArr(n);
	for (int i = 0; i < n; ++i)
		cin >> sortedArr[i];
	cin >> targetSum;
	print(TwoSum(sortedArr, targetSum));
}

/*
6
-9 -7 -6 -1 -1 3
2

-1 3

8
-3 1 1 2 6 6 8 10
100

None
*/