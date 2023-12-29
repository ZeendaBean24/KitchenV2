#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {

	int n; cin >> n;
 	cout << "ROYGBIV";

 	string repeat = "GBIV";
	REP(0, n-7) {
		cout << repeat[i % 4];
	}
	
    return 0;
}