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
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y; cin >> x >> y;
    int jump = 1; int direction = 1;
    int distance = 0;
    int pos = x;

    while (true) {
    	int projectedSquare = x + (jump * direction);
    	if (min(pos, projectedSquare) <= y && max(pos, projectedSquare) >= y) {
    		distance += max(pos, y) - min(pos, y);
    		break;
    	} else {
    		distance += max(pos, projectedSquare) - min(pos, projectedSquare);
    	}
    	pos = projectedSquare;

    	jump *= 2;
    	direction = (direction == 1) ? -1 : 1;    	
    }
    cout << distance;
}