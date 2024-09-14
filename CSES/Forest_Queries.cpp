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

    int n, q; cin >> n >> q;
    vector<vi> trees;

    REP(i,0,n) {
    	string tree; cin >> tree;
    	vi row;
    	for (char c : tree) {
    		if (c == '.') {
    			row.push_back(0);
    		} else {
    			row.push_back(1);
    		}
    	}
    	trees.push_back(row);
    }

    // for (vi i : trees) {
    // 	for (int j : i) {
    // 		cout << j << " ";
    // 	}
    // 	cout << endl;
    // }

    vector<vi> prefixSum(n+1, vi(n+1, 0));

    REP(i,1,n+1) {
    	REP(j,1,n+1) {
    		prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + trees[i-1][j-1];
    	}
    }

    // for (vi i : prefixSum) {
    // 	for (int j : i) {
    // 		cout << j << " ";
    // 	}
    // 	cout << endl;
    // }

    REP(i,0,q) {
    	int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
    	int numberOfTrees = prefixSum[y2][x2] - prefixSum[y1-1][x2] - prefixSum[y2][x1-1] + prefixSum[y1-1][x1-1];
    	cout << numberOfTrees << endl;
    }


    return 0;
}