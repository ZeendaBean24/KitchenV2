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
    vi array;

    REP(i,0,n) {
    	int element; cin >> element;
    	array.push_back(element);
    }

    int firstSwapElement = 0;
   	int lastSwapElement = 0;
   	bool swapping = false;
   	bool ans = false;
   	int count = 0;

  	REP(i,1,n) {
  		if (swapping == false && array[i-1] > array[i]) {
  			firstSwapElement = i;
  			swapping = true;
  		}
  		if (swapping == true && array[i-1] <= array[i]) {
  			lastSwapElement = i;
  			if (array[firstSwapElement-1] <= array[i]) {
  				ans = true;
  			}
  			swapping = false;
  			count++;
  		}
    }

    if (count == 0) {
    	ans = true;
    	if (swapping == false) {
	    	firstSwapElement = 1;
	    	lastSwapElement = 1;
    	}
	    if (swapping == true) {
	    	lastSwapElement = n;
	    }
    }

    if (swapping == true) {
    	count++;
    }

    if (count > 1) {
    	ans = false;
    }

    if (count == 1 && firstSwapElement > 1) {
    	if (array[lastSwapElement-1] < array[firstSwapElement-2]) {
    		ans = false;
    	}
    }

    if (ans == false) {
    	cout << "no";
    } else {
    	cout << "yes" << endl;
    	cout << firstSwapElement << " " << lastSwapElement;
    }

}