#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int b;
	cin >> b;

	vector<int> birds;

	for (int i = 0; i < b; i++) {
		int x;
		cin >> x;
		birds.push_back(x);
	}

	int s;
	cin >> s;

	vector<vector<int>> shots;

	for (int i = 0; i < s; i++) {
		int x, y;
		cin >> x >> y;
		shots.push_back({x, y});
	}

	for (vector<int> v : shots) {
		if (b == 1) {
			birds[v[0]-1] = 0;
		} else if (v[0] == 1) {
			birds[v[0]] += birds[v[0]-1] - v[1];
			birds[v[0]-1] = 0;
		} else if (v[0] == b) {
			birds[v[0]-2] += v[1]-1;
			birds[v[0]-1] = 0;
		} else {
			birds[v[0]-2] += v[1]-1;
			birds[v[0]] += birds[v[0]-1] - v[1];
			birds[v[0]-1] = 0;
		}
	}

	for (int n : birds) {
		cout << n << endl;
	}
    
    return 0;
}