#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;

    vector<pii> shift;
    int n, m, x; cin >> n >> m >> x;
    vector<vc> keyboard;

    REP(i,0,n) {
    	vc row = {};
    	REP(j,0,m) {
    		char c; cin >> c;
    		if (c == 'S') {
    			shift.push_back(make_pair(i, j));
    		}
    		row.push_back(c);
    	}
    	keyboard.push_back(row);
    }

    int q; cin >> q;
    string text; cin >> text;

    int ans = 0;
    int capital = 0;
    int impossibleLetter = 0;
    vi goodLetters; vi badLetters;

    for (char c : text) {
    	vector<pii> queryPosition;
    	bool isBreak = false;
    	for (char l : badLetters) {
    		if (l == c) {
    			ans++;
    			isBreak = true;
    		} 
    	}
    	for (char l : goodLetters) {
    		if (l == c) {
    			isBreak = true;
    		} 
    	}

    	if (!isBreak) {
    		int letter = 0;
			REP(i,0,n) {
	    		REP(j,0,m) {
	    			if (islower(keyboard[i][j]) && toupper(keyboard[i][j]) == c) {
	    				queryPosition.push_back(make_pair(i, j));
	    				letter++;
	    			}
	    			if (islower(keyboard[i][j]) && keyboard[i][j] == c) {
	    				letter++;
	    			}
			    }
			}

			if (letter == 0) {
				impossibleLetter++;
				break;
			}

			bool doable = false;
	    	if (isupper(c)) {
	    		capital++;
		    	for (pii s : shift) {
		    		if (doable) {
		    			break;
		    		}
		    		for (pii q : queryPosition) {
		    			double distance = sqrt(SQ(q.first-s.first)+SQ(q.second-s.second));
			    		if (distance <= static_cast<double>(x)) {
			    			doable = true;
			    			break;
			    		}
		    		}
		    	}
			}

			if (!doable && isupper(c)) {
	    		ans++;
	    		badLetters.push_back(c);
	    	} else {
	    		goodLetters.push_back(c);
	    	}
    	}
    }

    if (capital == 0 && impossibleLetter == 0) {
    	cout << 0;
    } else if (size(shift) == 0 || impossibleLetter > 0) {
    	cout << -1;
    } else {
    	cout << ans;
    }
}