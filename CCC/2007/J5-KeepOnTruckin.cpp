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

    int a, b, n; cin >> a >> b >> n;

    vi motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

    REP(i,0,n) {
    	int motel; cin >> motel;
    	motels.push_back(motel);
    }

    sort(motels.begin(), motels.end());
    ll motelSize = motels.size();

    vll dp(motelSize, 0);
    dp[0] = 1;

    REP(i,0,motelSize) {
    	REP(j,i+1,motelSize) {
    		ll distance = motels[j] - motels[i];
    		if (distance >= a && distance <= b) {
    			dp[j] += dp[i];
    		}
    	}
    }

    cout << dp.back() << endl;

    return 0;
}
