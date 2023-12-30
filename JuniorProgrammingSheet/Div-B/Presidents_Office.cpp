#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {
    fastio;

    int n, m; char c; cin >> n >> m >> c;
    vector<vc> room;

    REP(i, 0, n) {
    	vc row = {};
    	REP (j, 0, m) {
    		char d; cin >> d;
    		row.push_back(d);
    	}
    	room.push_back(row);
    }

    set<char> deskColors = {c, '.'};
    REP(i, 0, n) {
    	REP(j, 0, m) {
    		if (room[i][j] == c) {
    			if (j != 0) {
    				deskColors.insert(room[i][j-1]);
    			}
    			if (j != m - 1) {
    				deskColors.insert(room[i][j+1]);
    			}
    			if (i != 0) {
    				deskColors.insert(room[i-1][j]);
    			}
    			if (i != n - 1) {
    				deskColors.insert(room[i+1][j]);
    			}
    		}
    	}
    }

    cout << size(deskColors) - 2;
}