#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n, b, d;
	cin >> n >> b >> d;

	vector<int> oranges;
	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		oranges.push_back(n);
	}

	int capacity = 0;
	int count = 0;
	for (int o : oranges) {
		if (b >= o) {
			capacity += o;
			if (capacity > d) {
				count++;
				capacity = 0;
			}
		}
	}
    
    cout << count;
    
    return 0;
}