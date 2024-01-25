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
    char direction;
    int x, y, grassEaten;
    bool stopped;
};

int timeToHitRut(Cow i, Cow j) {
    if (i.direction == j.direction) return -1;
    if (i.direction == 'N' && j.y >= i.y && i.x >= j.x && j.y - i.y >= i.x - j.x)
        if (j.y - i.y == i.x - j.x) {
            return -1;
        } 
        return i.x - j.y;
    if (i.direction == 'E' && j.x >= i.x && i.y >= j.y && j.x - i.x >= i.y - j.y) {
        if (j.x - i.x == i.y - j.y) {
            return -1;
        } 
        return i.y - j.y;
    }
    return -1;
}

int main() {
    fastio;
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int n; cin >> n;
    vector<Cow> cows(n);

    REP(i,0,n) {
        int x, y;
        char dir; 
        cin >> cows[i].direction >> cows[i].x >> cows[i].y;
        cows[i].grassEaten = 0; cows[i].stopped = false;
    }

    for (Cow cow : cows) {
        for (Cow c : cows) {
            cout << timeToHitRut(cow, c) << "    " << "Cow 1: " << cow.x << " " << cow.y << " " << cow.direction << "   Cow 2: " << c.x << " " << c.y << " " << c.direction << endl;
        }
    }
}