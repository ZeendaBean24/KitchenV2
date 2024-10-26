#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n, m, r; cin >> n >> m >> r;

    vi cows(n);
    REP(i,0,n) {
    	cin >> cows[i];
    }

    sort(cows.begin(), cows.end(), greater<>());

    vi prefixSumCows(n+1, 0);
    REP(i,1,n+1) {
    	prefixSumCows[i] = prefixSumCows[i-1] + cows[i-1];
    }

    // for (int p : prefixSum) {
    // 	cout << p << endl;
    // }

    vector<vi> milk;
    REP(i,0,m) {
    	int q, p; cin >> q >> p;
    	milk.push_back({p, q});
    }

    sort(milk.begin(), milk.end(), greater<>());

    // for (vi m : milk) {
    // 	cout << m[0] << " " << m[1] << endl;
    // }

    vector<vi> prefixSumMilk(m+1, vi(2, 0));
    REP(i,1,m+1) {
    	prefixSumMilk[i][0] = prefixSumMilk[i-1][0] + milk[i-1][1];
    	prefixSumMilk[i][1] = prefixSumMilk[i-1][1] + milk[i-1][0] * milk[i-1][1];
    }

    vi rent(r);
    REP(i,0,r) {
    	cin >> rent[i];
    }

    sort(rent.begin(), rent.end(), greater<>());

    vi prefixSumRent(r+1, 0);
    REP(i,1,r+1) {
    	prefixSumRent[i] = prefixSumRent[i-1] + rent[i-1];
    }

    // for (int r : rent) {
    // 	cout << r << endl;
    // }

    int maximum = 0;
    int currentMilkIndex = 1;
    REP(i,1,n+1) {
    	int orderTotal, rentTotal; 
    	int cowCount = prefixSumCows[i];
    	REP(j,currentMilkIndex,m+1) {
    		if (prefixSumMilk[j][0] > cowCount) {
    			break;
    		}
    		currentMilkIndex++;
    	}
    	orderTotal += prefixSumMilk[currentMilkIndex][1];
    	rentTotal = prefixSumRent[n - currentMilkIndex];
    	maximum = max(maximum, orderTotal + rentTotal);
    }

    cout << maximum;

    return 0;
}