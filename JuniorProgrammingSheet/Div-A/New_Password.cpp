#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n, k;
	cin >> n >> k;
	string letters = "abcdefghijklmnopqrstuvwxyz";
	vector<char> distinctChars;

	for (int i = 0; i < k; i++) {
		distinctChars.push_back(letters[i]);
	}

	int index = 0;
	while (index < n) {
		cout << letters[index % k];
		index++;
	}

    return 0;
}