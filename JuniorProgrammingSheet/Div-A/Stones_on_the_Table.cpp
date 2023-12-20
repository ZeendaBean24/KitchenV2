#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n; 
	cin >> n;

	string colors;
	cin >> colors;

	char prevColor = 'Z';
	int count = 0;
 	for (char c : colors) {
 		if (c == prevColor) {
 			count++;
 		}
 		prevColor = c;
 	}

 	cout << count;
    
    return 0;
}