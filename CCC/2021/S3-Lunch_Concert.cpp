// Unfinished

#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a);

int main() {
    fastio;

    int n; cin >> n;
    vector<vi> people;

    REP(i, 0, n) {
    	int p, w, d; cin >> p >> w >> d;
		people.push_back({p, w, d});
    }

    sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
    	return a[0] < b[0];
    });

    int minimum; int k = people[0][0] + people[0][2] + 1;
    for (vi person : people) {
			if (abs(k - (person[0] + person[2])) > 3) {
				minimum += abs(k - (person[0] + person[2])) * person[1];
			}
		}

	cout << minimum << " " << k;

    REP(i, people[0][0], people[n-1][0]+1) {
    	int sum = 0;
		for (vi person : people) {
			if (abs(i - (person[0] + person[2])) > 3) {
				sum += abs(i - (person[0] + person[2])) * person[1];
			}
		}
		minimum =  min(minimum, sum);
    }

    cout << minimum;

}