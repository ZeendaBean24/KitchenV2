#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	string s;
	cin >> s;

	vector<int> nums;

	for (char c : s) {
		if (isdigit(c)) {
			int digit = c - '0';
			nums.push_back(digit);
		}
	}

	int length = nums.size();
	sort(nums.begin(), nums.end());

	for (int i = 0; i < length-1; i++) {
		cout << nums[i] << '+';
	}

	cout << nums[length-1];

    return 0;
}