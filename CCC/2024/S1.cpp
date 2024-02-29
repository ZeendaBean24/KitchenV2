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

    vi hats;
    REP(i,0,n) {
        int h; cin >> h;
        hats.push_back(h);
    }   

    int ans = 0;
    REP(i,0,(n/2)) {
        if (hats[i] == hats[i+(n/2)]) {
            ans += 2;
        }
    }
    
    cout << ans;
    
}