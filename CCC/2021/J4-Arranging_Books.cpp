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

    string word; cin >> word;
    vi unsortedArray(3, 0);

    for (char c : word) {
    	if (c == 'L') {
    		unsortedArray[0]++;
    	} else if (c == 'M') {
    		unsortedArray[1]++;
    	} else {
    		unsortedArray[2]++;
    	}
    }

	// vi boundaries(3); 
	// int padding = 0;
	// REP(i,0,3) {
	// 	boundaries[i] += padding;
	// 	boundaries[i] += unsortedArray[i];
	// 	padding = boundaries[i];
	// } 

    vi psa(3);
    psa[0] = unsortedArray[0];
	REP(i, 1, 3) {
		psa[i] = psa[i-1] + unsortedArray[i];
	}

    int misL_in_M = 0, misL_in_S = 0;
    int misM_in_L = 0, misM_in_S = 0;
    int misS_in_L = 0, misS_in_M = 0;

    // 'L' should be in range [0, psa[0])
    for (int i = 0; i < psa[0]; i++) {
        if (word[i] == 'M') misM_in_L++;
        else if (word[i] == 'S') misS_in_L++;
    }

    // 'M' should be in range [psa[0], psa[1])
    for (int i = psa[0]; i < psa[1]; i++) {
        if (word[i] == 'L') misL_in_M++;
        else if (word[i] == 'S') misS_in_M++;
    }

    // 'S' should be in range [psa[1], psa[2])
    for (int i = psa[1]; i < psa[2]; i++) {
        if (word[i] == 'L') misL_in_S++;
        else if (word[i] == 'M') misM_in_S++;
    }

    int direct_swaps = min(misL_in_M, misM_in_L)
                     + min(misL_in_S, misS_in_L)
                     + min(misM_in_S, misS_in_M);

    int remaining_swaps = (max(misL_in_M, misM_in_L) - min(misL_in_M, misM_in_L))
                        + (max(misL_in_S, misS_in_L) - min(misL_in_S, misS_in_L))
                        + (max(misM_in_S,misS_in_M) - min(misM_in_S, misS_in_M));

    int cycle_swaps = remaining_swaps * 2 / 3;

    int total_swaps = direct_swaps + cycle_swaps;

    cout << total_swaps << endl;
}