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
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    pii position = {0, 0};
    int n; cin >> n;
    
    vector<pair<char, int>> instructions;
    REP(i,0,n) {
    	char dir; int num; cin >> dir >> num;
    	instructions.push_back(make_pair(dir, num));
    }

	map<pii, int> visitedSquares;
	int minimum = 1000;
	int ans = 0;
	REP(i,0,n) {
		REP(j,0,instructions[i].second) {
			if (instructions[i].first == 'N') {
				position.first++;
			}
			if (instructions[i].first == 'S') {
				position.first--;
			}
			if (instructions[i].first == 'E') {
				position.second++;
			}
			if (instructions[i].first == 'W') {
				position.second--;
			}
			ans++;

			if (visitedSquares.count(position) > 0) {
				// cout << position.first << " " << position.second << endl;
				minimum = min(minimum, ans-visitedSquares[position]);
			}

			visitedSquares[position] = ans;
		}
	}
	
	if (minimum == 1000) {
		cout << -1;
	} else {
		cout << minimum;
	}
}