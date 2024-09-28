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
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k; cin >> n >> k;

    vector<vi> regions;
    int maxX = 0; 
    int maxY = 0;
    REP(i,0,n) {
    	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
    	maxX = max(maxX, x2);
    	maxY = max(maxY, y2);
    	regions.push_back({x1, y1, x2, y2});
    }
// 
    vector<vi> differenceMatrix(maxY+1, vi(maxX+1, 0));

    // for (vi i : differenceMatrix) {
    // 	for (int j : i) {
    // 		cout << j << " ";
    // 	}
    // 	cout << endl;
    // }
    // cout << endl;

    for (vi rect : regions) {
        differenceMatrix[rect[1]][rect[0]]++;
        differenceMatrix[rect[1]][rect[2]]--;
        differenceMatrix[rect[3]][rect[0]]--;
        differenceMatrix[rect[3]][rect[2]]++;
    	// for (vi i : differenceMatrix) {
	    // 	for (int j : i) {
	    // 		cout << j << " ";
	    // 	}
	    // 	cout << endl;
	    // }
	    // cout << endl;
    }

    // for (vi i : differenceMatrix) {
    // 	for (int j : i) {
    // 		cout << j << " ";
    // 	}
    // 	cout << endl;
    // }
    // cout << endl;

    int count = 0;
    
    REP(i,1,maxY+1) {
        REP(j,1,maxX+2) {
            differenceMatrix[i][j] = differenceMatrix[i][j] + differenceMatrix[i][j-1] + differenceMatrix[i-1][j] - differenceMatrix[i-1][j-1];
            if (differenceMatrix[i][j] == k) {
                count++;
            }
        }
    }

    cout << count;

    // cout << endl;
    // for (vi i : differenceMatrix) {
    // 	for (int j : i) {
    // 		cout << j << " ";
    // 	}
    // 	cout << endl;
    // }
    
    return 0;
}