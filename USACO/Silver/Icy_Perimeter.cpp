#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int MAXSIZE = 1000;
// vector<vi> grid(MAXSIZE, vi(MAXSIZE));
vector<vi> grid(6, vi(6));
// vector<vb> visited(MAXSIZE, vb(MAXSIZE, false));
vector<vb> visited(6, vb(6, false));

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);
    int n; cin >> n;
    REP(i,0,n) {
        string chars; cin >> chars;
        REP(j,0,n) {
            if (chars[j] == '#') {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    // for (vi row : grid) {
    //     for (int i : row) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    pii maximumArea = {0, 0};

    return 0;
}