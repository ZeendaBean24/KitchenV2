#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

    int n; 
    cin >> n;

    int count = 0;

    for (int i = 0; i < (n/4); i++) {
        if ((n - (i * 4)) % 5 == 0) {
            count++;
        }
    }

    if (n % 4 == 0) {
        count++;
    }

    cout << count;
    
    return 0;
}