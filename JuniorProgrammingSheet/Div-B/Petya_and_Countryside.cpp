#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<char> vc;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define REP(a,b) for (int i = a; i <= b; i++);
#define SQ(a) (a)*(a);

int main() {

	int c; cin >> c;
	vi numbers;

	while (c--) {
		int input; cin >> input;
		numbers.push_back(input);
	}

	int most = 0;
	int index = 0;

	for (int i : numbers) {
		int currentIndex = index;
		int maximum = 1;

		while (currentIndex > 0) { // Check left
			if (numbers[currentIndex] < numbers[currentIndex-1]) {
				break;
			}
			maximum++;
			currentIndex--;
		} 

		currentIndex = index;
		while (currentIndex < numbers.size()-1) { // Check right
			if (numbers[currentIndex] < numbers[currentIndex+1]) {
				break;
			}
			maximum++;
			currentIndex++;
		} 

		index++;
		most = max(most, maximum);
	}

	cout << most;

    return 0;
}