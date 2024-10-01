#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vi> adj(n+1);
    REP(i,0,m) {
    	int a, b; cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    vb visited(n+1, false);
    vi reps;

    REP(i,1,n+1) {
    	if (!visited[i]) {
    		reps.push_back(i);
    		queue<int> q;
    		q.push(i);
    		visited[i] = true;
    		while (!q.empty()) {
    			int city = q.front();
    			q.pop();
    			for (int neighbour : adj[city]) {
    				if (!visited[neighbour]) {
    					visited[neighbour] = true;
    					q.push(neighbour);
    				}
    			}
    		}
    	}
    }

    int numRoads = reps.size() - 1;
    cout << numRoads << endl;
    REP(i,1,numRoads+1) {
    	cout << reps[i-1] << " " << reps[i] << endl;
    }

    return 0;
}