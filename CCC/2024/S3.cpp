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

    vector<vi> possibleSwipes; // 0 = left swipe, // 1 = right swipe
    bool possible = true;
    int start = 0;
    int end;


    REP(i,0,n) { 
        int target;
        if (initial[i] != final[i]) {
            if (start == 0) {
                start = i;
                target = final[i];
                cout << "Target" << target;
            } 
            if (i == n-1 || final[i] != target) {
                if (i == n-1) {
                    end = i;
                } else {
                    end = i-1;
                }
                cout << start << " " << end;
                int possibleSides = 2;
                if (start != 0) { // check left
                    if (initial[start-1] != target) {
                        possibleSides--;
                    } else {
                        possibleSwipes.push_back({1, start-1, end});
                    }
                } else {
                    possibleSides--;
                }
                if (end != n-1) { // check right
                    if (initial[end+1] != target) {
                        possibleSides--;
                    } else {
                        possibleSwipes.push_back({0, start, end+1});
                    }
                } else {
                    possibleSides--;
                }
                if (possibleSides == 0) {
                    possible = false;
                    break;
                }
                start = 0;
            }
        }
    }

    // for (vi s : possibleSwipes) {
    //     cout << s[0] << " " << s[1] << " " << s[2] << endl;
    // }

    if (possibleSwipes.size() == 0) {
        cout << "YES" << endl << 0;
    } else if (!possible) {
        cout << "NO";
    } else {
        cout << "YES" << endl << possibleSwipes.size() << endl;
        for (vi swipe : possibleSwipes) {
            if (swipe[0] == 0) {
                cout << "L ";
            } else {
                cout << "R ";
            } 
            cout << start << " " << end;
        }
    }
}