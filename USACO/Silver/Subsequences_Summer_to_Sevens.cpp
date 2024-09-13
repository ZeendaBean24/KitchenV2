#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n; cin >> n;
    vi cows;

    REP(i,0,n) {
    	int c; cin >> c;
    	cows.push_back(c);
    }

    vll prefix(n+1);
    prefix[0] = 0;

    REP(i,1,n+1) {
    	prefix[i] = prefix[i-1] + cows[i-1];
    }

    int maximum = 0;

    vi firstOccurrence(7,-1);
    vi lastOccurrence(7,-1);

    REP(i,0,n+1) {
    	int mod = prefix[i] % 7;

    	if (firstOccurrence[mod] == -1) {
    		firstOccurrence[mod] = i;
    	}

    	lastOccurrence[mod] = i;

    	maximum = max(maximum, lastOccurrence[mod]-firstOccurrence[mod]);
    }

   cout << maximum;

   return 0;
   
 }

