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

    int n; cin >> n;

    vll nums; 
    REP(i,0,n) {
    	ll a; cin >> a;
    	nums.push_back(a);
    }

    bool isPossible = true;
    vll validNums;

    for (ll n : nums) {
    	bool inValidNums = false;
    	for (ll m : validNums) {
			if (n == m) {
				inValidNums = true;
			}
		}
    	if (size(validNums) == 3) {
    		if (!inValidNums) {
    			isPossible = false;
    			break;
    		}
    	} else {
    		if (!inValidNums) {
    			validNums.push_back(n);
    		}
    	}
    }	

    if (!isPossible) {
    	cout << "NO";
    } else {
    	sort(validNums.begin(), validNums.end());
    	if (size(validNums) == 1 || size(validNums) == 2) {
    		cout << "YES";
    	} else if (validNums[1]-validNums[0] == validNums[2]-validNums[1]) {
    		cout << "YES";
    	} else {
    		cout << "NO";
    	}
    }

}