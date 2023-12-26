#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
typedef long long ll;
 
int main() {
 
	int n;
	cin >> n;
	vector<int> nums;
	int one = 0; int two = 0; int three = 0;
	vector<int> ones, twos, threes;
 
	for (int j = 0; j < n; j++) {
		int i;
		cin >> i;
		nums.push_back(i);
	}
 
	int index = 1;
	for (int r : nums) {
		if (r == 1) {
			one++;
			ones.push_back(index);
		} else if (r == 2) {
			two++;
			twos.push_back(index);
		} else {
			three++;
			threes.push_back(index);
		}
		index++; 
	}
 
	int minimum = min({one, two, three});
	if (minimum == 0 || n < 3) {
		cout << 0;
	} else {
		cout << minimum;
		for (int i = 0; i < minimum; i++) {
			cout << "\n" << ones[i] << " " << twos[i] << " " << threes[i];
		}
	}
    
 
    return 0;
}