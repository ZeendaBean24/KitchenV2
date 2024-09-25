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
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n; cin >> n;
    vector<pll> cows;

    REP(i,0,n) {
        ll x, y; cin >> x >> y;
        cows.push_back({y, x});
    }

    sort(cows.begin(), cows.end());

    // for (pll c : cows) {
    //     cout << c.first << " " << c.second << endl;
    // }

    ll maximum = 0;
    int leftPointer = 0;
    int rightPointer = n-1;

    while (true) {
        ll pairSum = cows[leftPointer].first + cows[rightPointer].first;
        maximum = max(maximum, pairSum);

        if (leftPointer == rightPointer) {
            break;
        }

        ll numPairs = min(cows[leftPointer].second, cows[rightPointer].second);
        cows[leftPointer].second -= numPairs;
        cows[rightPointer].second -= numPairs;

        if (cows[leftPointer].second == 0) {
            leftPointer++;
        }

        if (cows[rightPointer].second == 0) {
            rightPointer--;
        } 

        // if (cows[leftPointer].second == cows[rightPointer].second) {
        //     maximum = max(maximum, cows[leftPointer].first + cows[rightPointer].first);
        //     leftPointer++;
        //     rightPointer--;
        // } else if (cows[leftPointer].second > cows[rightPointer].second) {
        //     maximum = max(maximum, cows[leftPointer].first + cows[rightPointer].first);
        //     cows[leftPointer].first -= cows[rightPointer].first;
        //     rightPointer--;
        // } else if (cows[leftPointer].second < cows[rightPointer].second) {
        //     maximum = max(maximum, cows[leftPointer].first + cows[rightPointer].first);
        //     cows[rightPointer].first -= cows[leftPointer].first;
        //     leftPointer++;
        // }
    }

    cout << maximum;

    return 0;
}