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
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n; cin >> n;
    vector<vi> cows;

    REP(i,0,n) {
    	vi cowRow;
    	string row; cin >> row;
    	for (char r : row) {
    		cowRow.push_back(r - '0');
    	}
    	cows.push_back(cowRow);
    }

    int flips = 0;

    for (int i=n-1; i>=0; i--) {
    	for (int j=n-1; j>=0; j--) {
    		if (cows[i][j] == 1) {
    			flips++;
    			for (int x=0; x<=i; x++) {
    				for (int y=0; y<=j; y++) {
    					if (cows[x][y] == 0) {
    						cows[x][y] = 1;
    					} else {
    						cows[x][y] = 0;
    					}
    				}
    			}
    		}
    	}
    }

    cout << flips;
}