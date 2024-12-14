#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int main() {
    fastio;

    int n, f; cin >> n >> f;
    string word; cin >> word;

    unordered_map<string, int> mooToCount;
    set<string> possibleMoos;
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    REP(i,0,n-2) {
        if (word[i+1] == word[i+2] && word[i] != word[i+1]) {
            string moo = word.substr(i,3);
            mooToCount[moo]++;
            if (mooToCount[moo] >= f) {
                possibleMoos.insert(moo);
            }
        }
    }

    REP(i,0,n) {
        char originalChar = word[i];
        for (char c : alphabet) {
            if (c == originalChar) {
            	continue; 
            }

            string newWord = word;
            newWord[i] = c;

            unordered_map<string, int> tempMooToCount;

            REP(j,0,n-2) {
                if (newWord[j+1] == newWord[j+2] && newWord[j] != newWord[j+1]) {
                    string moo = newWord.substr(j, 3);
                    tempMooToCount[moo]++;
                    if (tempMooToCount[moo] >= f) {
                        possibleMoos.insert(moo);
                    }
                }
            }
        }
    }

    vs sortedMoos;
    for (string s: possibleMoos) {
    	sortedMoos.push_back(s);
    }
    sort(sortedMoos.begin(), sortedMoos.end()); 

    cout << sortedMoos.size() << endl;
    for (string moo : sortedMoos) {
        cout << moo << endl;
    }

    return 0;
}