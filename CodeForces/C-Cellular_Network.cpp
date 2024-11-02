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

    vll cities;
    REP(i,0,n) {
        ll a; cin >> a;
        cities.push_back(a);
    }

    set<ll> towers;
    REP(i,0,m) {
        ll b; cin >> b;
        towers.insert(b);
    }

    ll maximum = 0;
    for (ll city : cities) {
        ll tempMax;
        auto it = towers.upper_bound(city);
        if (it == towers.begin()) {
            tempMax = *it - city;
        } else if (it == towers.end()) {
            it--;
            tempMax = city - *it;
        } else {
            ll upper = *it - city;
            it--;
            ll lower = city - *it;
            tempMax = min(upper, lower);
        }
        maximum = max(maximum, tempMax);
    }

    cout << maximum;

    return 0;
}