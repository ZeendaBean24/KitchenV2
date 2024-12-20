#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

const int SZ = 2e5;
vi countArr(SZ+1, 0);
vector<vi> adj(SZ+1);

void dfs(int s, int e) {
	countArr[s] = 1;
	for (auto u : adj[s]) {
		if (u == e) continue;
		dfs(u, s);
		countArr[s] += countArr[u];
	}
}

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n; cin >> n;
    REP(i,2,n+1) {
    	int e; cin >> e;
    	adj[e].push_back(i);
    }

    dfs(1, 0);

    REP(i,1,n+1) {
    	cout << countArr[i]-1 << " ";
    }


    return 0;
}