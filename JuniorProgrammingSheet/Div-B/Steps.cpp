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

    ll n, m, x, y; cin >> n >> m >> x >> y;
    int k; cin >> k;

    vector<pll> vectors;
        REP(i,0,k) { 
        ll dx, dy; cin >> dx >> dy;        
        vectors.push_back(make_pair(dx, dy));
    }

    ll count = 0;
    pll currentPos = {x, y};
    

    for (pll v : vectors) {
        pll endPos;
        ll minimum;
        if (v.first > 0 && v.second > 0) {
            endPos = {n, m};
        } else if (v.first > 0 && v.second < 0) {
            endPos = {n, 1};
        } else if (v.first < 0 && v.second > 0) {
            endPos = {1, m};
        } else if (v.first < 0 && v.second < 0) {
            endPos = {1, 1};
        }
        if (v.first == 0 && v.second > 0) {
            minimum = (m - currentPos.second) / abs(v.second);
        } else if (v.first == 0 && v.second < 0) {
            minimum = (currentPos.second - 1) / abs(v.second);
        } else if (v.first > 0 && v.second == 0) {
            minimum = (n - currentPos.first) / abs(v.first);
        } else if (v.first < 0 && v.second == 0) { 
            minimum = (currentPos.first - 1) / abs(v.first);
        } else {
            minimum = min(abs(endPos.first-currentPos.first) / abs(v.first), abs(endPos.second-currentPos.second) / abs(v.second));
        }
        count += minimum;
        currentPos = {currentPos.first + (v.first * minimum), currentPos.second + (v.second * minimum)};
    }

    cout << count;

}