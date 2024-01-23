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
    freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

    int m, n, k; cin >> m >> n >> k;
    REP(i,0,m) {
    	string row; cin >> row;
    	REP(j,0,k) {
    		for (char c : row) {
	    		REP(l,0,k) {
	    			cout << c;
	    		}
	    	}
	    	cout << endl;
    	}
    }
}