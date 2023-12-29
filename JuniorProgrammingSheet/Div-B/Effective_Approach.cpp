#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {

    int n; cin >> n;
    vi elements;

    REP(0, n) {
        int e; cin >> e;
        elements.push_back(e);
    }

    int m; cin >> m;
    vi queries;

    REP(0, m) {
        int q; cin >> q;
        queries.push_back(q);
    }

    ll v = 0; ll p = 0;
    map<int, int> nMap;

    REP(0, n) {
        nMap.insert(make_pair(elements[i], i+1));
    }

    for (int query : queries) {
        if (nMap.find(query) != nMap.end()) {
            v += nMap[query];
            p += n - nMap[query] + 1;
        }

    }

    cout << v << " " << p;
    
    return 0;
}