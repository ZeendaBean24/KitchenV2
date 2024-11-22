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
    
    vector<vi> adj(n);
    REP(i,0,m) {
    	int a, b; cin >> a >> b;
        a--; b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    vi assigned(n, 0); // 0: unvisited; 1 or 2 to represent the teams

    REP(i,0,n) {
    	if (assigned[i] == 0) { 
            assigned[i] = 1;
    		queue<int> q;
			q.push(i);

	    	while (!q.empty()) {
                int current = q.front();
                q.pop();
	    		for (int neighbour : adj[current]) {
                    if (assigned[neighbour] == 0) {
                        assigned[neighbour] = 3 - assigned[current];
                        q.push(neighbour);
                    } else if (assigned[neighbour] == assigned[current]) {
                        cout << "IMPOSSIBLE";
                        return 0;
                   }
	    		}
	   		}
    	}
    }

    REP(i,0,n) {
        cout << assigned[i] << " ";
    }


    return 0;
}