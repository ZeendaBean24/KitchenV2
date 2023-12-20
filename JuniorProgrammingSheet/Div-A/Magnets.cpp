#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n;
	cin >> n;
	vector<int> magnets;

	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		int a = m / 10;
		int b = m % 10;
		magnets.push_back(a);
		magnets.push_back(b);
	} 

	int count = 1;
	int lastNumber = 2;
	for (int m : magnets) {
		if (m == lastNumber) {
			count++;
		}
		lastNumber = m;

	}

    cout << count;

    return 0;
}