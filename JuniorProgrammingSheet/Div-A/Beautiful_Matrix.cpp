#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	vector<vector<int>> matrix;
	int r,c;

	for (int i = 0; i < 5; i++) {
		vector<int> row{};
		for (int j = 0; j < 5; j++) {
			int input;
			cin >> input;
			if (input == 1) {
				r = i;
				c = j;
			}
			row.push_back(input);
		}
		matrix.push_back(row);
	}

	int moves = (abs(r-2) + abs(c-2));
	cout << moves;
    
    return 0;
}