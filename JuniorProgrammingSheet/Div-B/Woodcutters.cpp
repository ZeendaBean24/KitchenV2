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

    vector<pll> trees;

    REP(i,0,n) {
    	ll x, h; cin >> x >> h;
    	trees.push_back(make_pair(x, h));
    }

    int prevTree = trees[0].first;
    int count = 2;

    REP(i,1,n-1) {
		if (trees[i].first - trees[i].second > prevTree) {
			count++;
			prevTree = trees[i].first;
		} else if (trees[i].first + trees[i].second < trees[i+1].first) {
			count++;
			prevTree = trees[i].first + trees[i].second;
		} else {
			prevTree = trees[i].first;
		}
    }

    if (n == 1) {
    	cout << 1;
    } else {
    	cout << count;	
    }
}