#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	string word;
	cin >> word;

	int lowercase = 0; 
	int uppercase = 0;

	for (char c : word) {
		if (islower(c)) { // If it equals to True
			lowercase++;
		} else {
			uppercase++;
		}
	}

	if (uppercase > lowercase) {
		for (char c : word) {
			c = toupper(c);
			cout << c;
		}
	} else {
		for (char c : word) {
			c = tolower(c);
			cout << c;
		}
	}


    return 0;
}