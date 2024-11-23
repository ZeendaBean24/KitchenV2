#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int dfs(int node, vb &visited, vector<vi> adj) {
    int count = 1;
    visited[node] = true;
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            count += dfs(neighbour, visited, adj);
        }
    }
    return count;
}

int main() {
    fastio;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n; cin >> n;

    vector<vi> cows;
    REP(i,0,n) {
        int x, y, p; cin >> x >> y >> p;
        cows.push_back({x, y, p});
    }

    vector<vi> adj(n);
    REP(i,0,n) {
        REP(j,i+1,n) {
            int x1, x2, y1, y2, p1, p2;
            x1 = cows[i][0]; x2 = cows[j][0]; y1 = cows[i][1]; y2 = cows[j][1]; p1 = cows[i][2]; p2 = cows[j][2];
            if (SQ(x2 - x1) + SQ(y2 - y1) <= SQ(p1)) {
                adj[i].push_back(j);
            } 
            if (SQ(x1 - x2) + SQ(y1 - y2) <= SQ(p2)) {
                adj[j].push_back(i);
            }
        }
    }

    // for (vi v : adj) {
    //     for (int i : v) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    int maximum = 0;
    REP(i,0,n) {
        vb visited(n, false);
        maximum = max(maximum, dfs(i, visited, adj));
    }

    cout << maximum;

    return 0;
}