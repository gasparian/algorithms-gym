#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector <int> TwoSum(const vector <int> &arr, int targetSum) {
	unordered_set<int> s;
	for (int i = 0; i < (int)arr.size(); i++) {
		auto it = s.find(arr[i]);
		if (it != s.end()) {
			return {targetSum-arr[i], arr[i]};
		}
		s.insert(targetSum-arr[i]);
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
	vector <int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> targetSum;
	print(TwoSum(arr, targetSum));
}