#include <bits/stdc++.h>

using namespace std;

int main() {
    string row1 = " ***";
    string row2 = "*   *";
    string row3 = "*    ";
    string row4 = "    *";
    string row5 = "     ";

    int N{};
    cin >> N;

    if (N==0 or N==2 or N==3 or N==5 or N==6 or N==7 or N==8 or N==9) {
        cout << row1 << endl;
        if (N==2 or N==3 or N==7) {
            cout << row4 << endl << row4 << endl << row4 << endl;

        }
        else if (N==5 or N==6) {
            cout << row3 << endl << row3 << endl << row3 << endl;
        }
        else {
            cout << row2 << endl << row2 << endl << row2 << endl;
        }

    }
    else if (N==1 or N==4) { // 1, 4
        cout << endl;
        if (N==1) {
            cout << row4 << endl << row4 << endl << row4 << endl;
        }

        else {
            cout << row2 << endl << row2 << endl << row2 << endl;
        }
    }

    if (N==2 or N==3 or N==4 or N==5 or N==6 or N==8 or N==9)
        cout << row1 << endl;
    
    else if (N==0 or N==1 or N==7) {
        cout << endl;
    }

    if (N==1 or N==3 or N==4 or N==5 or N==7 or N==9) {
        cout << row4 << endl << row4 << endl << row4 << endl;
    }
    else if (N==2) {
        cout << row3 << endl << row3 << endl << row3 << endl;
    }
    else if (N==0 or N==6 or N==8) {
        cout << row2 << endl << row2 << endl << row2 << endl;
    }

    if (N==1 or N==4 or N==7) {
        cout << endl;
    }
    else if (N==0 or N==2 or N==3 or N==5 or N==6 or N==8 or N==9) {
        cout << row1 << endl;
    }
    return 0;
}