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

    vector<vll> differences = {
    	{45, 49, 5},
    	{445, 499, 55},
    	{4445, 4999, 555},
    	{44445, 49999, 5555},
    	{444445, 499999, 55555},
    	{4444445, 4999999, 555555},
    	{44444445, 49999999, 5555555},
    	{444444445, 499999999, 55555555}
    };

    int t; cin >> t;
    REP(i,0,t) {
    	ll n; cin >> n;
    	ll tot = 0;
    	for (vll d : differences) {
    		if (n >= d[1]) {
    			tot += d[2];
    		} else if (n >= d[0]) {
    			tot += n - d[0] + 1;
    		} else {
    			break;
    		}
    	}
    	cout << tot << endl;
    }

    return 0;
}