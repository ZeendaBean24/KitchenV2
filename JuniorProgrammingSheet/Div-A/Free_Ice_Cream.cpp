#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

    int n;
    ll x;
    cin >> n >> x;

    int count = 0;

    for (int i = 0; i < n; i++) {
        string change, amount;
        cin >> change >> amount;
        ll a = stoll(amount);

        if (change == "+") {
            x += a;
        } else {
            if (a <= x) {
                x -= a;
            } else {
                count += 1;
            }
        }
    }  

    cout << x << " " << count;
    
    return 0;
}