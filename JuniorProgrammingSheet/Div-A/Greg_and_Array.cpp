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
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    vll arr(n);
    REP(i,0,n) {
    	cin >> arr[i];
    }

    vector<vll> operations;
    REP(i,0,m) {
    	ll l, r, d; cin >> l >> r >> d;
    	operations.push_back({l, r, d});
    }

   	vll operationsDifferenceArray(m+2, 0);
   	REP(i,0,k) {
    	int x, y; cin >> x >> y;
    	operationsDifferenceArray[x] += 1;
    	operationsDifferenceArray[y+1] -= 1;
    }

    REP(i,2,m+2) {
    	operationsDifferenceArray[i] += operationsDifferenceArray[i-1];
    }

    // for (int i : operationsDifferenceArray) {
    // 	cout << i << " ";
    // }
    // cout << endl;

    vll differenceArray(n+2, 0);
    REP(i,0,m) {
    	differenceArray[operations[i][0]] += operations[i][2] * operationsDifferenceArray[i+1];
    	differenceArray[operations[i][1]+1] -= operations[i][2] * operationsDifferenceArray[i+1];
    }

    // for (int i : differenceArray) {
    // 	cout << i << " ";
    // }
    // cout << endl;

    REP(i,2,n+2) {
    	differenceArray[i] += differenceArray[i-1];
    }

    // for (int i : differenceArray) {
    // 	cout << i << " ";
    // }
    // cout << endl;

    REP(i,0,n) {
    	arr[i] += differenceArray[i+1];
    	cout << arr[i] << " ";
    }

    return 0;
}