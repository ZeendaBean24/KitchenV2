#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	string s, t;
	cin >> s;
	cin >> t;
	int count = 1;

	for (char c : t) {
		if (s[count-1] == c) {
			count++;
		}

	}

	cout << count;

    return 0;
}