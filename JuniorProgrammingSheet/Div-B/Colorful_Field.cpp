#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {
    fastio;

    int n, m, k, t; cin >> n >> m >> k >> t;

	vll waste;
    REP(i,0,k) {
    	int a, b; cin >> a >> b;
    	waste.push_back((a-1)*m + b);
    }
    sort(waste.begin(), waste.end());

    vll target;
    REP(l,0,t) {
    	int i, j; cin >> i >> j;
    	target.push_back((i-1)*m + j);
    }

    for (int t : target) {
    	int wasteNum = 0;
    	bool isWaste = false;
    	for (int w : waste) {
    		if (w == t) {
    			cout << "Waste" << endl;
    			isWaste = true; 
    			break;
    		} else if (w < t) {
    			wasteNum++;
    		} else {
    			break;
    		}
    	}

    	if (!isWaste) {
    		int targetIndex = (t - wasteNum) % 3;
			if (targetIndex == 1) {
				cout << "Carrots";
			} else if (targetIndex == 2) {
				cout << "Kiwis";
			} else {
				cout << "Grapes";
			}
			cout << endl;
    	}
    	
    }

}