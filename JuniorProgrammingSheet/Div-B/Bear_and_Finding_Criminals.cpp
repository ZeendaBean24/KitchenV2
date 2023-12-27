#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {

	int n, a; cin >> n >> a;
	vi criminals;

	REP(0, n) {
		int c; cin >> c;
		criminals.push_back(c);
	}

	int count = 0;
	int direction = 0;
	int minimum = min((a-1), (n-a));
	if (n - a > a - 1) {
		direction++;
	} 
	if (n - a < a - 1) {
		direction--;
	}

	REP(1, minimum + 1) {
		if (criminals[a-1+i] == 1 && criminals[a-1-i] == 1) {
			count += 2;
		}
	}

	if (direction == 1) {
		REP(a + minimum, n) {
			if (criminals[i] == 1) {
				count++;
			}
		}
	}

	if (direction == -1) {
		REP(0, a - minimum - 1) {
			if (criminals[i] == 1) {
				count++;
			}
		}
	}

	if (criminals[a-1] == 1) {
		count++;
	}

	cout << count;
    
    return 0;
}