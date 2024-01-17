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

    int p, q, l, r; cin >> p >> q >> l >> r;

    set<int> z; 
    REP(i,0,p) {
    	int a, b; cin >> a >> b;
    	REP(j,a,b+1) {
    		z.insert(j);
    	}
    }

    vector<pii> x;
    REP(i,0,q) {
    	int a, b; cin >> a >> b;
    	x.push_back(make_pair(a, b));
    }

    int count = 0;
    bool isBreak;
    REP(i,l,r+1) {
    	isBreak = false;
		REP(j,0,q) {
			if (isBreak) {
    			break;
    		}
    		REP(k,x[j].first,x[j].second+1) {
	    			auto it = z.find(k+i);
	    			if (it != z.end()) {
	    				count++;
	    				isBreak = true;
	    				break;
		    		}
	    		}
    	}
    }

    cout << count;
}