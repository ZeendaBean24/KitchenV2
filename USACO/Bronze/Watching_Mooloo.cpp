#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    ll n, k; cin >> n >> k;
    vll days;
    for (ll i = 0; i < n; i++) {
    	ll d; cin >> d;
    	days.push_back(d);
    }

    sort(days.begin(), days.end());

    // ll prevDay = days[0];
    // ll total = 0;

    // for (ll i = 0; i < n; i++) {
    // 	if (days[i] - prevDay + 1 + k < 2*k + 2) {
    // 		total += days[i] - prevDay + 1 + k;
    // 	} else {
    // 		total += 2*k + 2;
    // 		prevDay = days[i];
    // 	}
    // }

    ll cost = 0;
    ll i = 0;
    while (i < n) {
    	ll startDay = days[i];

    	ll j = i;
    	while (j < n && days[j]-startDay+1+k < 2*k+2) {
    		j++;
    	}

    	ll daysCovered = days[j-1] - startDay + 1;
    	cost += daysCovered + k;
    	// cout << daysCovered + k << endl;

    	i = j;
    }

    cout << cost;

    return 0;
}