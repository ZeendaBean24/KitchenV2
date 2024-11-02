#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

bool ycmp(pii p, pii q) {
	return p.second < q.second;
};

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n; cin >> n;
    vector<pll> pairs;

    REP(i,0,n) {
    	ll x, y; cin >> x >> y;
    	pairs.push_back(make_pair(x, y));
    }

    sort(pairs.begin(), pairs.end());
    REP(i,0,n) {
    	pairs[i].first = i + 1;
    }

    sort(pairs.begin(), pairs.end(), ycmp);
    REP(i,0,n) {
    	pairs[i].second = i + 1;
    }

    REP(i,0,n) {
    	cout << pairs[i].first << " " << pairs[i].second << endl;
    }

    // sort(pairs.begin(), pairs.end());

    return 0;
}