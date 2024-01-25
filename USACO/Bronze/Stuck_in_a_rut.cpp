#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

int Infinity = 1000000001;

struct Cow {
    int time_stopped;
    int x, y;
    char dir;
};

int n;
Cow cows[50];

int when_hits(int i, int j, int currentTime) {
    Cow I = cows[i]; 
    Cow J = cows[j];
    if (I.dir == J.dir) {
        return Infinity;
    }
    if (I.dir == 'E') { // I moves North, J moves East
        swap(I.x, I.y);
        swap(J.x, J.y);
    }
    if (I.y >= J.y) {
        return Infinity;
    }
    if (J.time_stopped == Infinity) {
        
    }


    return Infinity;
}

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);


}