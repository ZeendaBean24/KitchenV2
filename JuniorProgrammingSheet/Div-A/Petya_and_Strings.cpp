#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	string p, m;
	cin >> p;
	cin >> m;

	int n = 0;
	int value = 0;

	for (char c : m) {
		if (tolower(p[n]) < tolower(c)) {
			value = -1;
			break;
		} 
		if (tolower(p[n]) > tolower(c)) {
			value = 1;
			break;
		}
		n++;
	}

	cout << value;

    return 0;
}