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

    int n, t1, t2, k; cin >> n >> t1 >> t2 >> k;

    vector<vi> speeds;
    REP(i,0,n) {
    	vi speed;
    	int a, b; cin >> a >> b;
    	if (a > b) {
    		speed.push_back(b);
    		speed.push_back(a);
    	} else {
    		speed.push_back(a);
    		speed.push_back(b);
    	}
    	speed.push_back(i+1);
    	speeds.push_back(speed);
    }

    vector<pair<double, int>> dwarfs;
    for (vi speed : speeds) {
    	double height = max((speed[0] * t1 * (1 - k * 0.01)) + (speed[1] * t2), (speed[1] * t1 * (1 - k * 0.01)) + (speed[0] * t2));
    	dwarfs.push_back(make_pair(height, speed[2]));
    }
x
    auto comparator = [](const pair<double, int>& a, const pair<double, int>& b) {
    	if (a.first != b.first) {
    		return a.first > b.first;
    	} else {
    		return a.second < b.second;
    	}
    };

    sort(dwarfs.begin(), dwarfs.end(), comparator);

    for (pair<double, int> p : dwarfs) {
    	cout << fixed << p.second << " " << setprecision(2) << p.first << setprecision(0) << endl; 
    }

}