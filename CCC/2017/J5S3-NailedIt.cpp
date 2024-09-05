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

    int n; cin >> n;
    vi heights(2001, 0);

    REP(i,0,n) {
    	int h; cin >> h;
    	heights[h]++;
    }

    vi lengths(4001, 0);

    // REP(i,2,4001) {
    //     for (int target = 1; target <= i / 2; target++) {
    //         if (i - target == target) {
    //             lengths[i] += heights[target] / 2;
    //         } else {
    //             lengths[i] += min(heights[target], heights[i - target]);
    //         }
    //     }
    // }

    REP(i,1,2001) {
        if (heights[i] > 1) {
            lengths[2*i] += heights[i]/2;
        }
        REP(j,i+1,2001) {
            lengths[i+j] += min(heights[i], heights[j]);
        }
    }

    // for (int l : heights) {
    //     cout << l << endl;
    // }

    int maximum = 0;
    int frequency = 0;
    
    REP(i,0,4001) {
        // cout << maximum << " " << frequency << endl;
        if (lengths[i] > maximum) {
            frequency = 1;
            maximum = lengths[i];
        } else if (lengths[i] == maximum) {
            frequency++;
        }
    }

    cout << maximum << " " << frequency;
}