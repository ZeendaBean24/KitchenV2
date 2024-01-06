#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {
    fastio;
    vector<pll> potentialEarnedCustomers;
    vector<pll> store;

    int n, f; cin >> n >> f;
    REP(i,0,n) {
    	ll k, l; cin >> k >> l;
    	ll earnedCustomers;
    	if (2 * k <= l) {
    		earnedCustomers = k;
    	} else {
    		if (l - k < 0) {
    			earnedCustomers = 0;
    		} else {
    			earnedCustomers = l - k;
    		}
    	}
    	potentialEarnedCustomers.push_back(make_pair(earnedCustomers, i));
    	store.push_back(make_pair(k,l));
    }

    sort(potentialEarnedCustomers.begin(), potentialEarnedCustomers.end());
    reverse(potentialEarnedCustomers.begin(), potentialEarnedCustomers.end());

    ll count = 0;
    REP(i,0,f) {
    	int currentStoreIndex = potentialEarnedCustomers[i].second;
    	if (2 * store[currentStoreIndex].first <= store[currentStoreIndex].second) {
    		count += 2 * store[currentStoreIndex].first;
    	} else {
    		count += store[currentStoreIndex].second;
    	}
    }

    REP(i,f,n) {
    	int currentStoreIndex = potentialEarnedCustomers[i].second;
    	if (store[currentStoreIndex].first <= store[currentStoreIndex].second) {
    		count += store[currentStoreIndex].first;
    	} else {
    		count += store[currentStoreIndex].second;
    	}
    }

    cout << count;
}