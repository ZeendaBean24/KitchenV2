#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {

	int n; cin >> n;
	vc word; 
	vc newWord(n);

	REP(0, n) {
		char c; cin >> c;
		word.push_back(c);
	}

	// int index = ceil(static_cast<double>(n / 2.0)) - 1;
	int index;
	int counter = 0;
	int direction;
	if (n % 2 == 0) {
		direction = -1;
		index = (n/2) - 1;
	} else {
		direction = 1;
		index = (n-1) / 2;
	}

	for (char c : word) {
		newWord[counter * direction + index] = c;
		index += counter * direction;
		direction = (direction == -1) ? 1 : -1;
		counter++;
	}

	for (char c : newWord) {
		cout << c;
	}

    return 0;
}