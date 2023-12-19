#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

    int n;
    cin >> n;

    string input;
    cin >> input;

    vector<char> characters;
    for (char c : input) {
        characters.push_back(c);
    }

    int a = 0;
    int d = 0;

    for (char game : characters) {
        if (game == 'A') {
            a++;
        } else {
            d++;
        }
    }

    if (a > d) {
        cout << "Anton";
    } else if (d > a) {
        cout << "Danik";
    } else {
        cout << "Friendship";
    }

    
    return 0;
}