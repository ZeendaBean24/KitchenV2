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
    // freopen("measurement.in", "r", stdin);
    // freopen("measurement.out", "w", stdout);

    ll n, g; cin >> n >> g;

    vector<pair<ll, pll>> logs; 
    map<ll, ll> cowIdToMilkQuantity;
    REP(i,0,n) {
    	ll day, id; string c; cin >> day >> id >> c;
    	ll change;
    	if (c[0] == '+') {
    		change = stoi(c.substr(1));
    	} else {
    		change = stoi(c.substr(1)) * -1;
    	}
    	cowIdToMilkQuantity[id] = g;
    	logs.push_back(make_pair(day, make_pair(id, change)));
    }

    sort(logs.begin(), logs.end());

    map<ll, ll> milkQuantityToCows;
    milkQuantityToCows[g] = n;

    int count = 0;
    ll currentTopProduction = g;
    ll currentTopProductionCows = n;
    ll currentTopProductionCowId = 0;
    // cout << "Cycle -1 " << " Top Production " << currentTopProduction << " Top Production Cows " << currentTopProductionCows << endl;  
    REP(i,0,n) {
    	ll id = (logs[i].second).first;
    	ll change = (logs[i].second).second;
    	ll prevQuantity = cowIdToMilkQuantity[id];

    	// Update quantity 
    	cowIdToMilkQuantity[id] += change;
    	ll newQuantity = cowIdToMilkQuantity[id];
    	milkQuantityToCows[prevQuantity]--;
    	if (milkQuantityToCows[prevQuantity] == 0) {
    		milkQuantityToCows.erase(prevQuantity);
    	}
    	milkQuantityToCows[newQuantity]++;

    	// Find top producer, number of cows at that quantity
    	auto topProducerPointer = milkQuantityToCows.rbegin();
    	ll topProducer = topProducerPointer->first;
    	ll topProducerCows = topProducerPointer->second;

    	if (topProducer != currentTopProduction) { // Case 1: top milk output changes
    		if (topProducerCows == 1) {	// Case 1a: Only 1 cow on top
    			ll topProducerCowId = id;
    			if (topProducerCowId != currentTopProductionCowId) { // Check that it's not the same leader
    				count++;
    			}
    			currentTopProductionCowId = id;
    		} else { // Case 1b: Multiple cows on top, ignore id
    		   count++;	
    		   currentTopProductionCowId = 0;
    		}
    	} else { // Case 2: number of cows with top milk producers changes
    		if (topProducerCows != currentTopProductionCows) {
    			count++;
    		}
    	}

    	// Update tracking variables
    	currentTopProduction = topProducer;
    	currentTopProductionCows = topProducerCows;
    	// cout << "Cycle " << i << " Top Production " << currentTopProduction << " Top Production Cows " << currentTopProductionCows << endl;  
    }

    cout << count;

    return 0;
}