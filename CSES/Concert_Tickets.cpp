#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n, m; cin >> n >> m;

    multiset<ll> ms;
    REP(i,0,n) {
    	ll h; cin >> h;
    	ms.insert(h);
    }

    vll prices(m);
    REP(i,0,m) {
    	cin >> prices[i];
    }

    for (ll price : prices) {
    	auto it = ms.upper_bound(price);
    	if (it != ms.begin()) {
    		it--;
	    	cout << *it;
	    	ms.erase(ms.find(*it));
    	} else {
    		cout << -1;
    	}
    	cout << endl;
    }

    return 0;
}