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
    
    int t; cin >> t;
    vector<vi> cows;

    REP(i,0,t) {
    	int n; cin >> n;
    	vi cow;
    	REP(j,0,n) {
    		int i; cin >> i;
    		cow.push_back(i);
    	}
    	cows.push_back(cow);
    }

    for (vi cow : cows) {
    	set<int> ans;
    	REP(i,1,size(cow)) {
    		if (i > 1) {
    			if (cow[i-2] == cow[i]) {
    				ans.insert(cow[i]);
    			}
    		} 
    		if (cow[i-1] == cow[i]) {
    			ans.insert(cow[i]);
    		}
    	}

    	if (ans.empty()) {
		    cout << "-1" << endl;
		} else {
		    int n = ans.size();
		    int i = 0;
		    for (int hay : ans) {
		        cout << hay;
		        if (i < n - 1) {
		            cout << " ";
		        }
		        i++;
		    }
		    cout << endl;
		}
    }
}