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

    queue<pii> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vi> distance(n, vi(m, INT_MAX));

    q.push(start);
    visited[start.first][start.second] = true;
    distance[start.first][start.second] = 0;

    // Directions
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        auto s = q.front();
        q.pop();

        if (s == end) {
            cout << distance[s.first][s.second]-1;
            return 0;
        }

        for (auto dir : directions) {
            int newRow = s.first + dir[0];
            int newCol = s.second + dir[1];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] != -1 && !visited[newRow][newCol]) {
                q.push({newRow, newCol});
                visited[newRow][newCol] = true;
                distance[newRow][newCol] = distance[s.first][s.second] + 1;
            }
        }
    }

    cout << -1;
}