#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

	int n;
	cin >> n;
	vector<int> cards;

	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;
		cards.push_back(card);
	}

	// Even = s, Odd = d;
	int s = 0;
	int d = 0;
	int length = cards.size();


	    for (int i = 0; i < n; i++) {

	        if (i % 2 == 0) {
	        	if (cards.size() == 1) {
						s += cards[0];
						break;
					}
	            if (cards[0] > cards[cards.size() - 1]) {
	                s += cards[0];
	                cards.erase(cards.begin());
	            } else {
	                s += cards[cards.size() - 1];
	                cards.pop_back();
	            }
	        } else {
	        	if (cards.size() == 1) {
						d += cards[0];
						break;
					}
	            if (cards[0] > cards[cards.size() - 1]) {
	                d += cards[0];
	                cards.erase(cards.begin());
	            } else {
	                d += cards[cards.size() - 1];
	                cards.pop_back();
	            }
        }
    }

	cout << s << " " << d << " "; 
    
    return 0;
}