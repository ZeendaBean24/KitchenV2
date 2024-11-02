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

    int n; cin >> n;

    vector<pll> pairs;
    REP(i,0,n) {
    	ll a, b; cin >> a >> b;
    	pairs.push_back(make_pair(b, a));
    }

    sort(pairs.begin(), pairs.end());

    int count = 0;
    int currentTime = -1;
    REP(i,0,n) {
    	if (pairs[i].second >= currentTime) {
    		count++;
    		currentTime = pairs[i].first;
    	}
    }

    cout << count;

    return 0;
}