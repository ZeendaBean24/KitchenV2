#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int a, b;
	cin >> a >> b;
	int maximum = max(a, b);
	int numerator = 6-maximum+1;
	int denominator = 6;
	int cf = gcd(numerator, denominator);
	numerator /= cf;
	denominator /= cf;

	if (maximum == 1) {
		cout << "1/1";
	} else {
		cout << numerator << "/" << denominator;
	}
    
    return 0;
}