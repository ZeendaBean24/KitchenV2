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

    vi schedule;
    REP(i,0,n) {
    	int a; cin >> a;
    	schedule.push_back(a);
    }

    int rest = 0;
    pii numberIndex = {0, -1};
    REP(i,0,n) {
        if (schedule[i] == 0) {
            rest++;
            numberIndex = {i, -1};
        }
        if (schedule[i]  == 1 || schedule[i] == 2) {
            if (numberIndex.second == schedule[i]) {
                if ((i-numberIndex.first) % 2 == 1) {
                    rest++;
                    numberIndex = {i, -1};
                } else {
                    numberIndex = {i, schedule[i]};
                }
            } else if (numberIndex.second != -1) {
                if ((i-numberIndex.first) % 2 == 0) {
                    rest++;
                    numberIndex = {i, -1};
                } else {
                    numberIndex = {i, schedule[i]};
                }
            } else {
                numberIndex = {i, schedule[i]};
            }
        }
    }

    cout << rest;
}