#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

string spell(string word) {
    vector<char> letters(word.begin(), word.end());
    int length = letters.size();
    // cout << length;
    if(length < 4) {
        return word;
    }
    if (letters[length-2] == 'o' && letters[length-1] == 'r') {
        char thirdLastChar = letters[length-3];
        if (thirdLastChar != 'a' && thirdLastChar != 'e' &&  thirdLastChar != 'i' &&  
            thirdLastChar != 'o' &&  thirdLastChar != 'u' &&  thirdLastChar != 'y') {
            return word.substr(0, length-2) + "our";
        } 
    }
    return word;
}

int main() {

    string word;
    string result;

    while(true) {
        cin >> word;
        if(word == "quit!") break;
        result = spell(word);
        cout << result << endl;
    }

    return 0;
  }