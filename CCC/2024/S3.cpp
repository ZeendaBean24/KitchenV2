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

    vi initial; 
    REP(i,0,n) {
        int a; cin >> a;
        initial.push_back(a);
    }

    vi final; 
    REP(i,0,n) {
        int b; cin >> b;
        final.push_back(b);
    }

    vi swipes;
    REP(i,0,n) {
        if (initial[i] != final[i]) {
            swipes.push_back(i);
        }
    }

    int l = swipes.size();
    if (l == 0) {
        cout << "YES" << endl << 0;
        return 0;
    } else {
        int lastIndex = swipes[0];
        int lastNumber = final[swipes[0]];
        bool possible = true;
        

        if (l != 0) {
            REP(i,1,l) {
                if (swipes[i] - lastIndex != 1) {
                    possible = false;
                    break;
                }
                if (final[swipes[i]] != lastNumber) {
                    possible = false;
                    break;
                }
                lastNumber = final[swipes[i]];
                lastIndex = swipes[i];
            } 
        } 

        if (!possible) {
            cout << "NO";
        } else {
            if (swipes[0] == 0 && swipes[l-1] == n-1) {
                cout << "NO";
            } else {
                if (swipes[0] != 0) {
                    if (initial[swipes[0]-1] == lastNumber) { // right swipe
                        cout << "YES" << endl << 1 << endl << "R " << swipes[0]-1 << " " << swipes[l-1];
                        return 0;
                    } 
                }
                if (swipes[l-1] != n-1) {
                    if (initial[swipes[l-1]+1] == lastNumber) { // left swipe
                        cout << "YES" << endl << 1 << endl << "L " << swipes[0] << " " << swipes[l-1]+1;
                        return 0;
                    }
                }
                cout << "NO";
            }
        }
    }
}