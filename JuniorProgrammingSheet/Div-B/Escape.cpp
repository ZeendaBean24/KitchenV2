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

    int vp, vd, t, f, c; cin >> vp >> vd >> t >> f >> c;

  	if (vp >= vd) {
  		cout << 0;
  		return 0;
  	}

  	int count = 0;
  	double princessPos = vp * t;

  	while (true) {
  		double catchUpTime = princessPos / (vd - vp);
  		princessPos += catchUpTime * vp;

  		if (princessPos >= c) {
  			break;
  		}

  		count++;

  		double returnTime = (princessPos / vd) + f;
  		princessPos += returnTime * vp;
  	}

  	cout << count;
}