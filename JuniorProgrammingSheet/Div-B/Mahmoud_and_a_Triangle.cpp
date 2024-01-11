#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;

    int n; cin >> n;
    vi triangle; 

    REP(i,0,n) {
    	int s; cin >> s;
    	triangle.push_back(s);
    }

    sort(triangle.begin(), triangle.end());

    bool ans = false;
    REP(i,0,n-2) {
    	if (triangle[i] + triangle[i+1] > triangle[i+2]) {
    		ans = true;
    		break;
    	}
    }

    if (ans == false) {
    	cout << "NO";
    } else {
    	cout << "YES";
    }
 
}