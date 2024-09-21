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

    int n; ll t; cin >> n >> t;

    vll books(n);
    REP(i,0,n) {
    	cin >> books[i];
    }

    int leftPointer = 0;
    int rightPointer = 0;
    int total = books[0];
    ll maximum = 0;

    while (rightPointer < n-1) {
    	if (books[rightPointer+1] + total <= t) {
    		rightPointer++;
    		total += books[rightPointer];
    	} else {
    		leftPointer++;
    		total -= books[leftPointer-1];
    	}
    	maximum = max(maximum, rightPointer - leftPointer + 1);
    }

    cout << rightPointer << " " << leftPointer << endl;
    if (rightPointer == leftPointer && books[leftPointer] > t) {
    	cout << 0;
    } else {
    	cout << maximum;
    }

    return 0;
}