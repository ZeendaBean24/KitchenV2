#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

bool ycmp(pii p, pii q) {
	return p.second < q.second;
};

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n; cin >> n;
    vector<pll> pairs;

    REP(i,0,n) {
    	ll x, y; cin >> x >> y;
    	pairs.push_back(make_pair(x, y));
    }

    sort(pairs.begin(), pairs.end());
    REP(i,0,n) {
    	pairs[i].first = i + 1;
    }

    sort(pairs.begin(), pairs.end(), ycmp);
    REP(i,0,n) {
    	pairs[i].second = i + 1;
    }

    // REP(i,0,n) {
    // 	cout << pairs[i].first << " " << pairs[i].second << endl;
    // }

    vector<vll> prefixSum(n+1, vll(n+1, 0));
    REP(i,0,n) {
        prefixSum[pairs[i].second][pairs[i].first]++;
    }

    // for (vi v : prefixSum) {
    //     for (int i : v) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    REP(i,1,n+1) {
        REP(j,1,n+1) {
            prefixSum[i][j] += prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }

    // for (vi v : prefixSum) {
    //     for (int i : v) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    ll count = 0;

    REP(i,0,n-1) {
        REP(j,i+1,n) {
            // pii left, right;
            // if (pairs[i].first > pairs[i].second) {
            //     right = make_pair(pairs[i].first, pairs[i].second);
            //     left = make_pair(pairs[j].first, pairs[j].second);
            // } else {
            //     left = make_pair(pairs[i].first, pairs[i].second);
            //     right = make_pair(pairs[j].first, pairs[j].second);
            // }
            ll left, right, up, down;
            left = min(pairs[i].first, pairs[j].first);
            right = max(pairs[i].first, pairs[j].first);
            up = pairs[j].second;
            down = pairs[i].second;
            ll leftCount = prefixSum[up][left] - prefixSum[up][0] - prefixSum[down-1][left] + prefixSum[down-1][0];
            ll rightCount = prefixSum[up][n] - prefixSum[up][right-1] - prefixSum[down-1][n] + prefixSum[down-1][right-1];
            // cout << "Lower Bound " << down << " Upper Bound " << up << " " << leftCount << " " << rightCount << endl;
            count += leftCount * rightCount;
        }
    }

    cout << count + n + 1;

    return 0;
}