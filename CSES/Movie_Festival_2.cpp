#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<pll> movies;
    REP(i,0,n) {
        ll a, b;
        cin >> a >> b;
        movies.push_back({b, a}); 
    }

    sort(movies.begin(), movies.end());

    multiset<ll> endTimes;
    REP(i,0,k) {
        endTimes.insert(0); 
    }

    int count = 0;
    for (pll movie : movies) {
        ll endTime = movie.first;
        ll startTime = movie.second;

        auto it = endTimes.upper_bound(startTime); 
        if (it == endTimes.begin()) {
            continue; 
        }
        
        --it; 
        endTimes.erase(it); 

        endTimes.insert(endTime);
        count++; 
    }

    cout << count; 
    return 0; 
}
