#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    int n; cin >> n;

    vector<ll> g(n);
    REP(i,0,n) {
    	cin >> g[i];
    }

    ll b = -g[0];
    ll ans = abs(g[0]);
    ll t = -g[0];

    REP(i,1,n) {
    	t += b;
    	b -= g[i] + t;
    	ans += abs(g[i] + t);
    	t -= g[i] + t;
    }

    cout << ans;
}
