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

    int n, k; cin >> n >> k;

    vector<vi> regions;
    int maxX = 0; 
    int maxY = 0;
    REP(i,0,n) {
    	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    	maxX = max(maxX, x2);
    	maxY = max(maxY, y2);
    	regions.push_back({x1, y1, x2, y2});
    }

    vector<vi> differenceMatrix(maxY, vi(maxX+2, 0));

    for (vi i : differenceMatrix) {
    	for (int j : i) {
    		cout << j << " ";
    	}
    	cout << endl;
    }
    cout << endl;

    for (vi rect : regions) {
    	for (int i = maxY-rect[1]; i > maxY-rect[3]-1; i--) {
    		differenceMatrix[i][rect[0]]++;
    		differenceMatrix[i][rect[2]+1]--;
    	}
    	// for (vi i : differenceMatrix) {
	    // 	for (int j : i) {
	    // 		cout << j << " ";
	    // 	}
	    // 	cout << endl;
	    // }
	    // cout << endl;
    }

    for (vi i : differenceMatrix) {
    	for (int j : i) {
    		cout << j << " ";
    	}
    	cout << endl;
    }
    cout << endl;
    
    REP(i,0,maxY) {
    	REP(j,2,maxX+2) {
    		differenceMatrix[i][j] += differenceMatrix[i][j-1];
    	}
    }

    for (vi i : differenceMatrix) {
    	for (int j : i) {
    		cout << j << " ";
    	}
    	cout << endl;
    }
    cout << endl;

    return 0;
}