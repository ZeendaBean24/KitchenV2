#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main() {

    vector<string> streets = {"HOME"};
    vector<string> directions;

    while (true) {
        string instruction;
        cin >> instruction;
        if (instruction == "SCHOOL") {
            break;
        }
        if (instruction == "R") {
            directions.insert(directions.begin(), "LEFT");
        } else if (instruction == "L") {
            directions.insert(directions.begin(), "RIGHT");
        } else {
            streets.insert(streets.begin(), instruction);
        }
        
    }

    int length = directions.size();

    for (int i = 0; i < length; i++) {
        if (streets[i] == "HOME") {
            cout << "Turn " << directions[i] << " into your HOME." << endl;
        } else {
            cout << "Turn " << directions[i] << " onto " << streets[i] << " street." << endl;
        }
    }
    
    return 0;
}