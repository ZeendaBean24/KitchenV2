#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	string n;
	cin >> n;

	vector<int> values;

	for (char c : n) {
		int value = c - 'a'+ 1;
		values.push_back(value);
	}

	int lastChar = 1;
	int minimum = 0;

	for (int i : values) {

		minimum += min(26-abs(lastChar-i), abs(lastChar-i));
		lastChar = i;
	}

    cout << minimum;

    return 0;
}