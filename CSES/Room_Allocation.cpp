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
    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    // map original list index to sorted list index

    int n; cin >> n;
    vector<pll> customers;

    REP(i,0,n) {
        ll a, b; cin >> a >> b;
        customers.push_back(make_pair(a, b));
    }

    sort(customers.begin(), customers.end());

    for (pii pair : customers) {
        cout << pair.first << " " << pair.second << endl;
    }

    priority_queue<pll> pq;

    ll count = 0;
    vll order;

    for (pll customer : customers) {
        if (!pq.empty() && (-1 * pq.top().first) < customer.first) {
            ll roomNumber = pq.top().second;
            order.push_back(roomNumber);
            pq.pop();
            pq.push(make_pair(-1 * customer.second, roomNumber));
        } else {
            count++;
            order.push_back(count);
            pq.push(make_pair(-1 * customer.second, count));
        }
    }

    cout << count << endl;
    for (ll o : order) {
        cout << o << " ";
    }

    return 0;
}