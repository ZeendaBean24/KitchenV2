#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define cheat ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int N, M;
map<char, char> c{{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

int main() {
    cheat;
    int ans = 0;
    cin >> M >> N;

    for (int i = M; i <= N; ++i) {
        string n = to_string(i);
        string r = "";
        for (auto i: n) {
            if (c.count(i) != 0) {
                r += c[i];
            } else {
                break;
            }
        }
        reverse(r.begin(), r.end()); 
        if (r == n) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}