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

    ll n; cin >> n;
    vll cows;
    REP(i,0,n) {
        ll c; cin >> c;
        cows.push_back(c);
    }

    ll maximum = *max_element(cows.begin(), cows.end());
    ll range = maximum + 1;

    vi indexArray(range, 0);

    for (ll c : cows) {
        indexArray[c]++;
    }

    vi culmArray(range, 0);
    ll culmInt = 0;

    REP(i,0,range) {
        culmArray[i] += culmInt;
        culmArray[i] += indexArray[i];
        culmInt = culmArray[i];
    }

    vi sortedCows(n);

    for (ll i = n-1; i >= 0; i--) {
        ll c = cows[i];
        ll pos = culmArray[c] - 1;
        sortedCows[pos] = c;
        culmArray[c]--;
    }

    ll greedy = 0;
    ll greedyIndex;
    REP(i,0,n) {
        ll value = sortedCows[i] * (n-i);
        if (value > greedy) {
            greedy = value;
            greedyIndex = sortedCows[i];
        }
    }

    cout << greedy << " " << greedyIndex;
}