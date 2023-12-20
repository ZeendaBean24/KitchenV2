#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n; 
	vector<int> strips;

	for (int i = 0; i < 4; i++) {
		int s; 
		cin >> s;
		strips.push_back(s);
	}

	string seconds;
	cin >> seconds;

	vector<int> digits;
	for (char c : seconds) {
		int calories = c - '0';
		digits.push_back(calories);
	}

	int count = 0;
	for (int i : digits) {
		count += strips[i-1];
	}

	cout << count;
    
    return 0;
}