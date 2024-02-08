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

    int n, m; cin >> n >> m;
    vector<vi> matrix;
    pii start;
    pii end;

    REP(i,0,n) {
    	vi row;
		string s; cin >> s;
		REP(j,0,m) {
			if (s[j] == 's') {
				row.push_back(1);
				start = {i, j};
			} else if (s[j] == 'e') {
				row.push_back(2);
				end = {i, j};
			} else if (s[j] == 'X') {
				row.push_back(-1);
			} else {
				row.push_back(0);
			}
		}
    	matrix.push_back(row);
    }

    queue<int> q;
    bool visited[n*m];
    int distance[n*m];

    // Left most = 0, then go right, then go down
    int loc = start.first * m + start.second;

    visited[loc] = true;
    distance[loc] = 0;
    q.push(loc);

    int ans = 100000;

    while (!q.empty()) {
    	int s = q.front();
    	q.pop();

    	int row = s / m; 
    	int col = s % m;

    	// Check up
    	if (row != 0) {
    		if (matrix[row-1][col] == 0) {
    			if (visited[s-m]) {
    				continue;
    			}
    			q.push(s-m);
    			visited[s-m] = true;
    			distance[s-m] = distance[s] + 1;
    		}
    		// if (matrix[row-1][col] == 2) {

    		// }
    	}

    	// Check down
    	if (row != n-1) {
    		if (matrix[row+1][col] == 0) {
    			if (visited[s+m]) {
    				continue;
    			}
    			q.push(s+m);
    			visited[s+m] = true;
    			distance[s+m] = distance[s] + 1;
    		}
    	}

    	// Check left
    	if (col != 0) {
    		if (matrix[row][col-1] == 0) {
    			if (visited[s-1]) {
    				continue;
    			}
    			q.push(s-1);
    			visited[s-1] = true;
    			distance[s-1] = distance[s] + 1;
    		}
    	}

   		// Check right
   		if (col != m-1) {
    		if (matrix[row][col+1] == 0) {
    			if (visited[s+1]) {
    				continue;
    			}
    			q.push(s+1);
    			visited[s+1] = true;
    			distance[s+1] = distance[s] + 1;
    		}
    	}
    }

    // REP(i, 0, m*n) {
    // 	cout << distance[i] << " ";
    // }
}