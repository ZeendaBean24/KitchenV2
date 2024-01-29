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

    int n, s; cin >> n >> s;
    vector<pii> loc;

    REP(i,0,n) {
    	int q, v; cin >> q >> v;
    	loc.push_back(make_pair(q, v));
    }
    
    int k = 1;
    int direction = 1;
    int ans = 0;
    int pos = s;
    int Infinity = 100000001;
    int count = 0;
    vi reached(n, 0);

    while (count < Infinity) {
    	if (loc[pos-1].first == 1) {
    		if (reached[pos-1] == 0 && k >= loc[pos-1].second) {
    			ans++;
    			reached[pos-1] = 1;
    		} 
    	} else {
    		if (direction == 1) direction = -1;
    		else direction = 1;
    		k = k + loc[pos-1].second;
    	}
    	pos = pos + (direction * k);
    	if (pos < 1 || pos > n) {
    		break;
    	}
    	count++;
    }

    cout << ans;
}