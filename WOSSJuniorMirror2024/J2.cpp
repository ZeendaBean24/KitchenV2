#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;

    int a, b, c; cin >> a >> b >> c;
    cout << max(a + b + c, max((a + b) * c, max((b + c) * a, max((a + c) * b, max(a * b + c, max(a * c + b, max(b * c + a, a * b * c)))))));

}