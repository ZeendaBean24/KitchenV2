#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {
    list<string> adjectives = {};
    list<string> nouns = {};
    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        adjectives.push_back(word);
    }

    for (int i = 0; i < m; i++) {
        string word;
        cin >> word;
        nouns.push_back(word);
    }
    
    for (string adjective : adjectives) {
        for (string noun : nouns) {
            cout << adjective << " as " << noun << endl;
        }
    }

    return 0;
}