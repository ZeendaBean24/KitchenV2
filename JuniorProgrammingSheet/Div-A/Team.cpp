#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

    int n; 
    cin >> n;

    int implement = 0;
    for (int i = 0; i < n; i++) {
        int p,v,t,sum;
        cin >> p >> v >> t;
        sum = p + v + t;
        if (sum > 1) {
            implement++;
        }
    }

    cout << implement;

    return 0;
}