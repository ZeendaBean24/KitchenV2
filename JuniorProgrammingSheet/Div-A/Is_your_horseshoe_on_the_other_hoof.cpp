#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

    set<int> s;
    for (int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        s.insert(n);
    }

    cout << 4 - s.size();
    
    return 0;
}
