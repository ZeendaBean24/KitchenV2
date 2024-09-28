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
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n; cin >> n; 
    vector<pll> pairs;

    REP(i,0,n) {
    	ll a, b; cin >> a >> b;
    	pairs.push_back({a, 1});
    	pairs.push_back({b, -1});
    }

    sort(pairs.begin(), pairs.end());

    int maximumCount = 0;
    int tempCount = 0;

    for (pll pair : pairs) {
    	if (pair.second == 1) {
    		tempCount++;
    	} else if (pair.second == -1) {
    		tempCount--;
    	}
    	maximumCount = max(maximumCount, tempCount);
    }

    cout << maximumCount;
    
    return 0;
}