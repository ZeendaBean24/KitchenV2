#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)


struct Edge {
	ll a, b;
	bool operator<(const Edge &y) const {
		if (a != y.a) return a < y.a;
		return b > y.b;
	}
};

int main() {
    fastio;
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int n; cin >> n;

    vector<Edge> pairs;
    REP(i,0,n) {
		ll a, b; cin >> a >> b;
		pairs.push_back({a-b, a+b});
    }

    sort(pairs.begin(), pairs.end());

    // for (auto pair : pairs) {
    // 	cout << pair.a << " " << pair.b << endl;
    // }

    ll tempEnd = pairs[0].b;
    int count = 1;

    REP(i,1,n) {
    	if (pairs[i].b > tempEnd) {
    		count++;
    		tempEnd = pairs[i].b;
    	} 
    }	

    cout << count;

    return 0;
}