#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n;
	cin >> n;
	vector<vector<int>> games;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		games.push_back({a, b});
	}

	int count = 0;
	vector<int> track = {0, 0};

	for (vector<int> i : games) {
		for (vector<int> j : games) {
			if (i[0] == j[1] and i != j) {
				count++;
			}
		}
	}

	cout << count;
    
    return 0;
}