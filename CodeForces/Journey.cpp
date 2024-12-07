#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int MAX_SIZE = 10e5 + 1;
vb visited(MAX_SIZE, false);
vector<vi> adj(MAX_SIZE);
ld ans = 0.0;

void dfs(int node, int length, float prob) {
	visited[node] = true;
	int childCount = 0;

	for (int child : adj[node]) {
		if (!visited[child]) {
			childCount++;
		}
	}

	if (childCount == 0) {
		ans += length * prob;
		return;
	} 

	ld newProb = prob / childCount;
	for (int child : adj[node]) {
		if (!visited[child]) {
			dfs(child, length + 1, newProb);
		}
	}
}

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n; cin >> n;
    REP(i,0,n-1) {
    	int a, b; cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    dfs(1, 0, 1.0);
    cout << fixed << setprecision(15) << ans;

    return 0;
}