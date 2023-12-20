#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n;
	cin >> n;
	vector<int> config;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		config.push_back(num);
	}

	sort(config.begin(), config.end());
	for (int column : config) {
		cout << column << " ";
	}


    
    return 0;
}