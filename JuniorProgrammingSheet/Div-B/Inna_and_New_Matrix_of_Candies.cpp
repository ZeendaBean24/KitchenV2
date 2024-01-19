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

        int n, m; cin >> n >> m;

    vs matrix;
    REP(i,0,n) {
        string line; cin >> line;
        matrix.push_back(line);
    }

    vector<pii> positions;
    for (string l : matrix) {
        int posG, posS;
        REP(i,0,size(l)){
            if (l[i] == 'G') {
                posG = i;
            }
            if (l[i] == 'S') {
                posS = i;
            }
        }
        positions.push_back(make_pair(posG, posS));
    }

    set<int> difference;
    bool isDoable = true;
    for (pii p : positions) {
        int diff = p.second - p.first;
        if (diff < 0) {
            isDoable = false;
            break;
        }
        difference.insert(diff);
    }

    if (!isDoable) {
    	cout << -1;
    } else {
    	cout << size(difference);
    }

}

