#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {

	fastio;
	vs weights;
	string weight;
	
	REP(0, 3) {
		cin >> weight;
		weights.push_back(weight);
	}

	int a = 0; int b = 0; int c = 0;

	for (string w : weights) {
		if (w[1] == '<') {
			if (w[0] == 'A') {
				a--;
			} 
			if (w[0] == 'B') {
				b--;
			}
			if (w[0] == 'C') {
				c--;
			}
			if (w[2] == 'A') {
				a++;
			}
			if (w[2] == 'B') {
				b++;
			}
			if (w[2] == 'C') {
				c++;
			}
		} else {
			if (w[0] == 'A') {
				a++;
			} 
			if (w[0] == 'B') {
				b++;
			}
			if (w[0] == 'C') {
				c++;
			}
			if (w[2] == 'A') {
				a--;
			}
			if (w[2] == 'B') {
				b--;
			}
			if (w[2] == 'C') {
				c--;
			}
		}
	}

	if (a == 0 && b == 0 && c == 0) {
		cout << "Impossible";
	} else {
		if (a == -2) {
			cout << "A";
		} 
		if (b == -2) {
			cout << "B";
		} 
		if (c == -2) {
			cout << "C";
		} 
		if (a == 0) {
			cout << "A";
		} 
		if (b == 0) {
			cout << "B";
		} 
		if (c == 0) {
			cout << "C";
		} 
		if (a == 2) {
			cout << "A";
		} 
		if (b == 2) {
			cout << "B";
		} 
		if (c == 2) {
			cout << "C";
		} 
	}

	
    
    return 0;
}