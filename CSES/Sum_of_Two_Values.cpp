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

    int n; ll x; cin >> n >> x;

    vector<pll> nums; 
    REP(i,0,n) {
    	ll a; cin >> a;
    	nums.push_back({a, i});
    }

    sort(nums.begin(), nums.end());

    // for (pll pair : nums) {
    // 	cout << pair.first << " " << pair.second << endl;
    // }

    int leftPointer = 0;
    int rightPointer = n-1;

    while (leftPointer != rightPointer) {
    	ll sum = nums[leftPointer].first + nums[rightPointer].first;
    	if (sum == x) {
    		cout << nums[leftPointer].second + 1 << " " << nums[rightPointer].second + 1;
    		return 0;
    	}
    	if (sum < x) {
    		leftPointer++;
    	}
    	if (sum > x) {
    		rightPointer--;
    	}
    }

    cout << "IMPOSSIBLE";

    return 0;
}