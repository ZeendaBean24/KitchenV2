#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n;
	cin >> n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		int length = input.size();
		if (length > 10) {
			cout << input[0] << length-2 << input[length-1] << "\n";
		} else {
			cout << input << "\n";
		}
		
	} 

    return 0;
}