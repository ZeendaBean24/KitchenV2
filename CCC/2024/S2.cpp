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

    int t, n; cin >> t >> n;

    vs strings;
    REP(i,0,t) {
    	string s; cin >> s;
    	strings.push_back(s);
    }

    for (string s : strings) {
    	vi letters(26, 0);
    	for (char c : s) {
    		letters[c-'a']++;
    	}

    	bool alternate = true;
    	int heavy = -1;

    	for (char c : s) {
    		if (letters[c-'a'] > 1) {
    			if (heavy == 1) {
    				alternate = false;
    			}
    			heavy = 1;
    		} else if (letters[c-'a'] == 1) {
    			if (heavy == 0) {
    				alternate = false;
    			}
    			heavy = 0;
    		}
    	}

    	if (!alternate) {
    		cout << "F" << endl;
    	} else {
    		cout << "T" << endl;
    	}
    }
}