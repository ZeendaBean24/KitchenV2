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

    int n, q; cin >> n >> q;
    set<int> carved;
    int sum = 0;

    vector<vector<int>> xLineCount(n, vector<int>(n, 0));
    vector<vector<int>> yLineCount(n, vector<int>(n, 0));
    vector<vector<int>> zLineCount(n, vector<int>(n, 0));

    vector<vector<bool>> xFullyCarved(n, vector<bool>(n, false));
    vector<vector<bool>> yFullyCarved(n, vector<bool>(n, false));
    vector<vector<bool>> zFullyCarved(n, vector<bool>(n, false));

    REP(i,0,q) {
        int x, y, z; cin >> x >> y >> z;
        int coordToPos = x * n + y * SQ(n) + z;
        carved.insert(coordToPos);

        xLineCount[y][z]++;
        if (xLineCount[y][z] == n && !xFullyCarved[y][z]) {
            xFullyCarved[y][z] = true;
            sum++;
        }

        yLineCount[x][z]++;
        if (yLineCount[x][z] == n && !yFullyCarved[x][z]) {
            yFullyCarved[x][z] = true;
            sum++;
        }

        zLineCount[x][y]++;
        if (zLineCount[x][y] == n && !zFullyCarved[x][y]) {
            zFullyCarved[x][y] = true;
            sum++;
        }

        cout << sum << "\n";
    }

    return 0;
}
