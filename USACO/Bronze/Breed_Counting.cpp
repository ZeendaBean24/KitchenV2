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
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q; cin >> n >> q;
    vi dogs;

    REP(i,0,n) {
    	int d; cin >> d;
    	dogs.push_back(d);
    }

    vi holsteins(n+1); vi guernseys(n+1); vi jerseys(n+1);
    
    holsteins[0] = 0;
    int hcount = 0;
    REP(i,0,n) {
    	bool x = dogs[i] == 1;
    	if (dogs[i] == 1) {
    		hcount++;
    	}
    	holsteins[i+1] = hcount;
    }

    guernseys[0] = 0;
    int gcount = 0;
    REP(i,0,n) {
    	if (dogs[i] == 2) {
    		gcount++;
    	}
    	guernseys[i+1] = gcount;
    }

    jerseys[0] = 0;
    int jcount = 0;
    REP(i,0,n) {
    	if (dogs[i] == 3) {
    		jcount++;
    	}
    	jerseys[i+1] = jcount;
    }

    vector<vi> queries;
    REP(i,0,q) {
    	int a, b; cin >> a >> b;
    	queries.push_back({a, b});
    }

    for (vi query : queries) {
    	cout << holsteins[query[1]] - holsteins[query[0]-1] << " ";
    	cout << guernseys[query[1]] - guernseys[query[0]-1] << " ";
    	cout << jerseys[query[1]] - jerseys[query[0]-1] << endl;
    }

    return 0;
}