#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	string s;
	getline(cin, s);
	set<char> letters;

	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) {
			letters.insert(s[i]);
		}
	
	}

	cout << letters.size();

    return 0;

}