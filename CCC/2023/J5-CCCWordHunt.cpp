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

    string word; cin >> word;
    int r; cin >> r;
    int c; cin >> c;
    vector<vc> grid;

    REP(i,0,r) {
        vc row;
        REP(j,0,c) {
            char c; cin >> c;
            row.push_back(c);
        }
        grid.push_back(row);
    }

    // row first, then column
    vector<pii> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    int ans = 0; 

    // perpendicularity -> 
    // {-1, 1} and {1, -1} --> {-1, -1 and {1, 1}
    // {-1, -1} and {1, 1} --> {-1, 1} and {1, -1}
    // {1, 0} and {-1, 0} --> {0, 1}, {0, -1}
    // {0, 1} and {0, -1} --> {1, 0}, {-1, 0}

    REP(i,0,r) {
        REP(j,0,c) {
            if (grid[i][j] == word[0]) {
                // int test = 0;
                for (pii dir : directions) {
                    pii pos = {i, j};
                    bool possible = true;
                    int count = 1;
                    int len = size(word);
                    while (count < len) {
                        pos = {pos.first + dir.first, pos.second + dir.second};
                        if (pos.first >= 0 && pos.first < r && pos.second >= 0 && pos.second < c) {
                            if (grid[pos.first][pos.second] == word[count]) {
                                if (count != len - 1) {
                                    // Check switches
                                    vector<pii> perpendicularDir;
                                    if ((dir.first == -1 && dir.second == 1) || (dir.first == 1 && dir.second == -1)) {
                                        perpendicularDir = {{-1, -1}, {1, 1}};
                                    } else if ((dir.first == -1 && dir.second == -1) || (dir.first == 1 && dir.second == 1)) {
                                        perpendicularDir = {{-1, 1}, {1, -1}};
                                    } else if ((dir.first == 1 && dir.second == 0) || (dir.first == -1 && dir.second == 0)) {
                                        perpendicularDir = {{0, 1}, {0, -1}};
                                    } else if ((dir.first == 0 && dir.second == 1) || (dir.first == 0 && dir.second == -1)) {
                                        perpendicularDir = {{1, 0}, {-1, 0}};
                                    }

                                    for (pii d : perpendicularDir) {
                                        pii switchPos = pos;
                                        bool possible2 = true;
                                        int count2 = count + 1;
                                        while (count2 < len) {
                                            switchPos = {switchPos.first + d.first, switchPos.second + d.second}; 
                                            if (switchPos.first >= 0 && switchPos.first < r && switchPos.second >= 0 && switchPos.second < c) {
                                                if (grid[switchPos.first][switchPos.second] != word[count2]) {
                                                    possible2 = false;
                                                    break;
                                                }
                                            } else {
                                                possible2 = false;
                                                break;
                                            }
                                            count2++;
                                        }
                                        if (possible2) {
                                            ans++;
                                            // cout << "Switch " << i << " " << j << " " << switchPos.first << " " << switchPos.second << endl;
                                        }
                                    }
                                }
                            }
                            if (grid[pos.first][pos.second] != word[count]) {
                                possible = false;
                                break;
                            }
                        } else {
                            possible = false;
                            break;
                        }  
                        count++;
                    }

                    if (possible) {
                        ans++;
                        // cout << "Dir " << dir.first << " " << dir.second << " " << i << " " << j << endl;
                    }
                    // cout << "Dir "  << dir.first << " " << dir.second << endl;
                    // cout << test << endl;
                    // test++;
                }
            }
        }
    }

    cout << ans;
}