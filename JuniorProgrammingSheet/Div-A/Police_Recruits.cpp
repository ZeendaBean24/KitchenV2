#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n; 
	cin >> n;

	vector<int> crimes;
	int count = 0;
	int power = 0;

	for(int i = 0; i < n; i++) {
		int c;
		cin >> c;
		crimes.push_back(c);
	}	

	for (int c : crimes) {
		power += c;
		if (power < 0) {
			count++;
			power = 0;
		}
	}

    cout << count;

    return 0;
}