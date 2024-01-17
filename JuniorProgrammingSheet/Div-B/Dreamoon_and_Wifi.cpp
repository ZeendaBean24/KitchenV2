#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int count(int questionMark, int currentPos, int finalPos) {
	if (questionMark == 0) { // alternatively use ternary for shorthand
		if (currentPos == finalPos) {
			return 1;
		} else {
			return 0;
		}
	}

	int countPlus = count(questionMark-1, currentPos+1, finalPos);
	int countMinus = count(questionMark-1, currentPos-1, finalPos);

	return countPlus + countMinus;
}

int main() {
    fastio;

    string s1, s2;
    cin >> s1 >> s2; 

    int ans1 = 0;
    int ans2 = 0;
    int questionMark = 0;

    REP(i,0,size(s1)) {
    	if (s1[i] == '+') {
    		ans1++;
    	} else {
    		ans1--;    	
    	}
    	if (s2[i] == '+') {
    		ans2++;
    	} else if (s2[i] == '-') {
    		ans2--;
    	} else {
    		questionMark++;
    	}
    }	

    if (questionMark == 0) {
    	if (ans1 == ans2) {
    		cout << fixed << setprecision(12) << (double)1;
    	} else {
    		cout << fixed << setprecision(12) << (double)0;
    	}
    } else {
    	int num = count(questionMark, ans2, ans1);
    	cout << fixed << setprecision(12) << (double)(num/pow(2, questionMark));
    }

}