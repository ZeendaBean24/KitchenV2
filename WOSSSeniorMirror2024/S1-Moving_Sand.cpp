#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;

    int n, q; cin >> n >> q;

    vi sand;
    REP(i,0,n) {
    	int s; cin >> s;
    	sand.push_back(s);
    }

    vi psa(n, 0); psa[0] = sand[0];
    REP(i,1,n) {
    	psa[i] += sand[i] + psa[i-1];
    }

    vector<vi> queries;
    REP(i,0,q) {
    	int a, b, c; cin >> a >> b >> c;
    	queries.push_back({a, b, c});
    }

    for (vi q : queries) {
    	if (q[0] == 3) {
    		cout << psa[q[2]-1]-psa[q[1]-2] << endl;
    	} else {
    		if (q[0] == 1) {
	    		psa[q[1]-2] += q[2];
    		}
    		if (q[0] == 2) {
	    		psa[q[1]-1] -= q[2];
    		}
    	}

    }
}