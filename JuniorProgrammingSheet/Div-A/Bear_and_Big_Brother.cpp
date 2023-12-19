#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

    int a, b; // Limak, Bob
    cin >> a >> b;
    
    int years = 0;

    while (a <= b) {
        a *= 3;
        b *= 2;
        years += 1;
    }

    cout << years;

    return 0;
}