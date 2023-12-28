#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define REP(a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {

	int n, m; cin >> n >> m;
	vector<vi> containers;

	REP(0, m) {
		int x, y; cin >> x >> y;
		containers.push_back({x, y});
	}

	sort(containers.begin(), containers.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] > b[1];
    });

	int currentIndex = 0;
	int count = 0;
	while (n != 0 && containers[m-1][0] != 0) {
		if (containers[currentIndex][0] == 0) {
			currentIndex++;
		}
		count += containers[currentIndex][1];
		containers[currentIndex][0]--;
		n--;
	}

	cout << count;
    
    return 0;
}