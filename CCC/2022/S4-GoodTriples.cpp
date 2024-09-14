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

    int n, c; cin >> n >> c;

    vi freq(c, 0);

    REP(i,0,n) {
    	int p; cin >> p; 
    	freq[p]++;
    }

    // for (int p : freq) {
    //     cout << p;
    // }
    // cout << endl;
    

    vll prefixSum(c+1);
    prefixSum[0] = 0;


    REP(i,1,c+1) {
        prefixSum[i] = prefixSum[i-1] + freq[i-1];
    }

    // for (int p : prefixSum) {
    //     cout << p;
    // }
    // cout << endl;

    ll triplets = 0;

    REP(i,0,floor(c/2)) {
        REP(j,i+1,c) {
            if (c % 2 == 0) {
                if (freq[j] >= 1 && freq[i] >= 1 && j-i > 1 && j < (c/2) + i) {
                    int opposite1 = (c/2) + i;
                    int opposite2 = (c/2) + j;
                    if (opposite2 >= c) {
                        opposite2 = c;
                    }
                    ll sum = prefixSum[opposite2] - prefixSum[opposite1+1];
                    if (sum >= 1) {
                        // cout << i << " " << j << sum * freq[j] * freq[i] << endl;
                        triplets += sum * freq[j] * freq[i];
                    }       
                }
            } else {
                if (freq[j] >= 1 && freq[i] >= 1 && j <= floor(c/2) + i) {
                    int opposite1 = floor(c/2) + i; 
                    int opposite2 = floor(c/2) + j + 1;
                    if (opposite2 >= c) {
                        opposite2 = c;
                    }
                    ll sum = prefixSum[opposite2] - prefixSum[opposite1+1];
                    if (sum >= 1) {
                        // cout << i << " " << j << sum * freq[j] * freq[i] << endl;
                        triplets += sum * freq[j] * freq[i];
                    }   
                }
            }
        }
    }
    
    // cout << endl;
    cout << triplets;

    return 0;
}