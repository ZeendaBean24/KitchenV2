#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {
	fastio;
	ll n, m; cin >> n >> m;
	vector<pair<int, int>> c(m);

	REP(0, m) {
		int fir, sec; cin >> sec >> fir;
		c[i].first = fir, c[i].second = sec;
	}

	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());

	int id = 0;
	int rem = n; 
	ll count = 0;

	while (id != m) {
		if (rem >= c[id].second) {
			count += c[id].first * c[id].second;
			rem -= c[id].second;
			id++;
		} else {
			count += rem * c[id].first;
			break;
		} 
	}

	cout << count;
    
    return 0;
}