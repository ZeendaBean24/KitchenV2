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
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n; cin >> n;

    vi isElsie(2*n); // 1-index
    REP(i,0,n) {
        int c; cin >> c;
        isElsie[c-1]++;
    }

    vi elsie; vi bessie;
    REP(i,0,2*n) {
        if (isElsie[i] == 1) {
            elsie.push_back(i);
        } else {
            bessie.push_back(i);
        }
    }

    int count = 0;
    int elsieIndex = 0;
    int bessieIndex = 0;
    while (elsieIndex < n && bessieIndex < n) {
        if (bessie[bessieIndex] > elsie[elsieIndex]) {
            count++;
            bessieIndex++;
            elsieIndex++;
        } else {
            bessieIndex++;
        }
    }
    
    cout << count;

    return 0;
}