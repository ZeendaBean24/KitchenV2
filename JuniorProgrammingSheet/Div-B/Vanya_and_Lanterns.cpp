#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {
    fastio;
    int n; ll l; cin >> n >> l;
    set<ld> lanterns;


    REP(0, n) {
        ld lantern; cin >> lantern;
        lanterns.insert(lantern);
    }

    ld jump = 0; ld maximum = max(*lanterns.begin() * 2, (l - *--lanterns.end()) * 2);
    for (ld s : lanterns) {
        maximum = max(maximum, abs(jump - s));
        jump = s;
    }

    cout << fixed << setprecision(10) << (double)maximum / 2;

    return 0;
}
