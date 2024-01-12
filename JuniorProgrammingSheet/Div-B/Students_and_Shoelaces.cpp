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

    int n, m; cin >> n >> m;
    
	vector<pii> pairs;
    REP(i,0,m) {
    	int a, b; cin >> a >> b;
    	pairs.push_back(make_pair(a, b));
    }

    int count = 0;
    while (true) {
        vi students(n);
        REP(i,0,size(pairs)) {
            students[pairs[i].first-1]++;
            students[pairs[i].second-1]++;
        }

        int badPairs = 0;
        REP(i,0,size(students)) {
            vi visited;
            if (students[i] == 1) {
                REP(j,0,size(pairs)) {
                    auto it1 = find(visited.begin(), visited.end(), pairs[j].first);
                    auto it2 = find(visited.begin(), visited.end(), pairs[j].second);
                    if (it1 != visited.end() || it2 != visited.end()) {
                        break;
                    }

                    if (pairs[j].first == i+1 || pairs[j].second == i+1) {
                        badPairs++;
                        visited.push_back(i+1);
                        pairs.erase(pairs.begin() + j);
                    }
                }
            }
        }   
        
        if (badPairs == 0) {
            break;
        }   
        count++;
    }

    cout << count;

}