#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

// Method 2 (overloading the operator<)
// struct Edge {
// 	int a, b, w;
// 	bool operator<(const Edge &y) const {
// 		return w < y.w;
// 	}
// };

// Method 3
// struct Edge {
// 	int a, b, w;
// };

// Method 4 (overloading on various criteria: w and then a)
struct Edge {
	int a, b, w;
	// if w not the same, use w to compare
	bool operator<(const Edge &y) const {
		if (w != y.w) return w < y.w;
		return a < y.a;
	}
};

// Comparison Function
bool cmp(const Edge &x, const Edge &y) {
	// Ascending Order
	// return x.w < y.w;

	// Descending Order
	return x.w < y.w;
}

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int m; cin >> m;

    // Method 1: Old Version with pair sorting (nested data structure)
    // vector<pair<int, pii>> v;
    // REP(i,0,m) {
    // 	int a, b, w; cin >> a >> b >> w;
    // 	v.push_back({w, {a, b}});
    // }

    // sort(v.begin(), v.end());
    // for (auto e : v) {
    // 	cout << e.second.first << " "
   	// 	<< e.second.second << " " 
   	// 	<< e.first << endl;
    // }

    // Method 2, 4: Newer version with custom comparator
    vector<Edge> v;
    REP(i,0,m) {
    	int a, b, w; cin >> a >> b >> w;
    	v.push_back({a, b, w});
    }

    sort(v.begin(), v.end());
    for (auto e : v) {
    	cout << e.a << " " << e.b << " " << e.w << endl;
    }

    // Method 3: Different version of Method 2, not overloading
    // vector<Edge> v;
    // REP(i,0,m) {
    // 	int a, b, w; cin >> a >> b >> w;
    // 	v.push_back({a, b, w});
    // }

    // sort(v.begin(), v.end(), cmp); // Add boolean at the end
    // for (auto e : v) {
    // 	cout << e.a << " " << e.b << " " << e.w << endl;
    // }

    return 0;
}