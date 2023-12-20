#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	string input;
	cin >> input;

	set<char> characters;
	for (char c : input) {
		characters.insert(c);
	}

	int count = 0;
	for (char c : characters) {
		count++;
	}

	if (count % 2 == 0) {
		cout << "CHAT WITH HER!";
	} else {
		cout << "IGNORE HIM!";
	}
    
    return 0;
}