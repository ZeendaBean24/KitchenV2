#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {
    fastio;

    int n, k; cin >> n >> k;
    vi heights;

    REP(0, n) {
    	int h; cin >> h;
    	heights.push_back(h);
    }

    int sum = 0;
    REP(0, k) {
    	sum += heights[i];
    }

    int ans = 1;
    int minimum = sum;
    REP(1, n+1-k) {
    	sum -= heights[i-1];
    	sum += heights[i+k-1];
    	if (sum < minimum) {
    		ans = i + 1;
    		minimum = sum;
    	}
    }

    cout << ans;
    
}