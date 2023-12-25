#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n, t, k, d;
	cin >> n >> t >> k >> d;

    int timeElapsed = 0;
    int baked = 0;

    while (baked < n) {
        timeElapsed++;
        if (timeElapsed > 0 && timeElapsed % t == 0) {
            baked += k;
        }
        if (timeElapsed > d && (timeElapsed - d) % t == 0) {
            baked += k;
        }
    }

    if (timeElapsed < ceil(static_cast<double>(n) / k) * t) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }

}