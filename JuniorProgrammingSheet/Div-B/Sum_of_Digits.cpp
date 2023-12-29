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
	string n; 
	cin >> n;
	int count = 0;

	while (n.size() != 1) {
		int sum = 0;
		REP(0, n.size()) {
			sum += n[i] - '0';
		}
		n = to_string(sum);
		count++;
	}

	cout << count;

    return 0;
}