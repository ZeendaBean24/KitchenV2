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
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n; cin >> n;
    vi cows;

    REP(i,0,n) {
    	int c; cin >> c;
    	cows.push_back(c);
    }

    vll prefix(n+1);
    prefix[0] = 0;

    REP(i,1,n+1) {
    	prefix[i] = prefix[i-1] + cows[i-1];
    }

    int maximum = 0;

    vi firstOccurrence(7,-1);
    vi lastOccurrence(7,-1);

    REP(i,0,n+1) {
    	int mod = prefix[i] % 7;

    	if (firstOccurrence[mod] == -1) {
    		firstOccurrence[mod] = i;
    	}

    	lastOccurrence[mod] = i;

    	maximum = max(maximum, lastOccurrence[mod]-firstOccurrence[mod]);
    }

    cout << maximum;

   	return 0;

 }

    // vector<vi> multiples(7, vi(2, -1));

    // REP(i,0,n) {
    // 	if (cows[i] == 0) {
    // 		if (multiples[0][0] == -1) {
    // 			multiples[0][0] = i;
    // 		} else {
    // 			multiples[0][1] = i;
    // 		}
    // 	} else if (cows[i] == 1) {
    // 		if (multiples[1][0] == -1) {
    // 			multiples[1][0] = i;
    // 		} else {
    // 			multiples[1][1] = i;
    // 		}
    // 	} else if (cows[i] == 2) {
    // 		if (multiples[2][0] == -1) {
    // 			multiples[2][0] = i;
    // 		} else {
    // 			multiples[2][1] = i;
    // 		}
    // 	} else if (cows[i] == 3) {
    // 		if (multiples[3][0] == -1) {
    // 			multiples[3][0] = i;
    // 		} else {
    // 			multiples[3][1] = i;
    // 		}
    // 	} else if (cows[i] == 4) {
    // 		if (multiples[4][0] == -1) {
    // 			multiples[4][0] = i;
    // 		} else {
    // 			multiples[4][1] = i;
    // 		}
    // 	} else if (cows[i] == 5) {
    // 		if (multiples[5][0] == -1) {
    // 			multiples[5][0] = i;
    // 		} else {
    // 			multiples[5][1] = i;
    // 		}
    // 	} else if (cows[i] == 6) {
    // 		if (multiples[6][0] == -1) {
    // 			multiples[6][0] = i;
    // 		} else {
    // 			multiples[6][1] = i;
    // 		}
    // 	}
    // }

	// int maximum = 0;
	// for (vi pair : multiples) {
	// 	if (pair[0] != -1 && pair[1] != -1) {
	// 		maximum = max(maximum, pair[1] - pair[0]);
	// 	}
    // }

    // cout << maximum;



  	// vector<vi> multiples(7, vi(2));
  	// bool done = false;
  	// int firstNum;
  	// int lastNum; 

    // REP(i,0,n) {
    // 	if (cows[i] == 0 && !done) {
    // 		multiples[0][0] = cows[i]; 
    // 		done = true;
    // 		lastNum = i;
    // 	}
    // }
    // multiples[0][1] = lastNum;

    // done = false;

    // REP(i,0,n) {
    // 	if (cows[i] == 1 && !done) {
    // 		multiples[1][0] = cows[i]; 
    // 		done = true;
    // 		lastNum = i;
    // 	}
    // }
    // multiples[1][1] = lastNum;

    // done = false;

    // REP(i,0,n) {
    // 	if (cows[i] == 2 && !done) {
    // 		multiples[2][0] = cows[i]; 
    // 		done = true;
    // 		lastNum = i;
    // 	}
    // }
	// multiples[2][1] = lastNum;

    // done = false;

    // REP(i,0,n) {
    // 	if (cows[i] == 3 && !done) {
    // 		multiples[3][0] = cows[i]; 
    // 		done = true;
    // 		lastNum = i;
    // 	}
    // }
    // multiples[3][1] = lastNum;


    // done = false;

    // REP(i,0,n) {
    // 	if (cows[i] == 4 && !done) {
    // 		multiples[4][0] = cows[i]; 
    // 		done = true;
    // 		lastNum = i;
    // 	}
    // }
    // multiples[4][1] = lastNum;


    // done = false;

    // REP(i,0,n) {
    // 	if (cows[i] == 5 && !done) {
    // 		multiples[5][0] = cows[i]; 
    // 		done = true;
    // 		lastNum = i;
    // 	}
    // }
    // multiples[5][1] = lastNum;


    // done = false;

    // REP(i,0,n) {
    // 	if (cows[i] == 6 && !done) {
    // 		multiples[6][0] = cows[i]; 
    // 		done = true;
    // 		lastNum = i;
    // 	}
    // }
    // multiples[6][1] = lastNum;

    // int maximum = 0;

    // for (vi pair : multiples) {
    // 	cout << pair[0] << " " << pair[1] << endl;
    // 	maximum = max(maximum, pair[1] - pair[0]);
    // }

    // cout << endl << maximum;
