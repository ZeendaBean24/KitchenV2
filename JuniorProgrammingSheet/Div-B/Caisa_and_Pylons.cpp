#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {

    int n; cin >> n;
    vi pylons = {0};

    REP(0, n) {
        int p; cin >> p;
        pylons.push_back(p);
    }

    int paid = 0;
    int buffer = 0;
    REP(1, n+1) {
        int diff = pylons[i-1] - pylons[i];
        if (diff >= 0 || buffer >= abs(diff)) {
            buffer += diff;
        } else {    
            paid += abs(buffer + diff);
            buffer = 0;
        }
    }

    cout << paid;
    
    return 0;
}