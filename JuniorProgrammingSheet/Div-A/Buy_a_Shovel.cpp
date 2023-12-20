#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int s, d; // shovels, denomination
	cin >> s >> d;

	int count = 0;
	while (true) {
		count++;
		if ((count * s) % 10 == d || (count * s) % 10 == 0) {
			break;
		}
	}

	cout << count;
    
    return 0;
}