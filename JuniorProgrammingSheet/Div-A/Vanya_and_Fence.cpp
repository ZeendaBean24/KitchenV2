#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;


int main() {

    // First input line
    string inputString;
    vector<int> inputNumbers;
    
    getline(cin, inputString);
    stringstream ss(inputString);
    
    int i;
    while (ss >> i) {
        inputNumbers.push_back(i);
    }

    int n, h, minimumValue;
    h = inputNumbers[1];

    // Second input line
    vector<int> peopleHeight;

    string inputHeight;
    
    getline(cin, inputHeight);
    stringstream ssh(inputHeight);

    while (ssh >> i) {
        peopleHeight.push_back(i);
    }

    int count = 0;

    for (int height : peopleHeight) {
        if (height > h) {
            count += 2;
        } else {
            count += 1;
        }
    }

    cout << count;

    return 0;
}