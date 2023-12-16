#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

    int x;
    int m;
    cin >> x;
    cin >> m;

    int n = 0;


    for(int i = 1; i <= m; i++) {
        if((x * i) % m == 1) {
            n = i;
        }
    }

    if(n != 0) {
        cout << n;
    } else {
        cout << "No such integer exists.";
    }

    return 0;
}