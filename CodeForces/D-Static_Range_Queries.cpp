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

    int n, q; cin >> n >> q;

    vector<vll> updates;
    REP(i,0,n) {
    	ll l, r, v; cin >> l >> r >> v;
    	updates.push_back({l, r, v});
    }

    vector<vll> queries;
    REP(i,0,q) {
    	ll l, r; cin >> l >> r;
    	queries.push_back({l, r});
    }

    set<ll> l1;
    for (vll update : updates) {
    	l1.insert(update[0]);
    	l1.insert(update[1]);
    }
    for (vll query : queries) {
    	l1.insert(query[0]);
    	l1.insert(query[1]);
    }

    vll setToVector; 
    for (const auto &it : l1) {
    	setToVector.push_back(it);
    }

    ll s1 = setToVector.size();
    map<ll, ll> compressedToOriginal;
    map<ll, ll> originalToCompressed;
    REP(i,0,s1) {
    	compressedToOriginal[setToVector[i]] = i;
    	originalToCompressed[i] = setToVector[i];
    }

    vll differenceArray(s1+1, 0);
    REP(i,0,n) {
    	ll l = compressedToOriginal[updates[i][0]];
    	ll r = compressedToOriginal[updates[i][1]];
    	ll v = updates[i][2];
    	differenceArray[l+1] += v;
    	differenceArray[r+1] -= v; 
    }

    // for (ll d : differenceArray) {
    // 	cout << d << " ";
    // }
    // cout << endl;

    vll intervalArray(s1+1, 0);
    intervalArray[0] = 0;
    REP(i,1,s1+1) {
    	intervalArray[i] += intervalArray[i-1] + differenceArray[i];
    }

    // for (ll i : intervalArray) {
    // 	cout << i << " ";
    // }
    // cout << endl;

    vll widthArray(s1+1, 0);
    widthArray[0] = 0;
    REP(i,1,s1) {
    	widthArray[i] = originalToCompressed[i] - originalToCompressed[i-1];
    }	

    // for (ll w : widthArray) {
    // 	cout << w << " ";
    // }
    // cout << endl;

    vll psa(s1, 0);
    psa[0] = 0;
    REP(i,1,s1) {
    	psa[i] += psa[i-1] + widthArray[i] * intervalArray[i];
    }

    // for (ll p : psa) {
    // 	cout << p << " ";
    // }
    // cout << endl;

    REP(i,0,q) {
    	ll l = queries[i][0];
    	ll r = queries[i][1];
    	// cout << psa[compressedToOriginal[r]] << " " << psa[compressedToOriginal[l]] << " " << psa[compressedToOriginal[r]]-psa[compressedToOriginal[l]] << endl;
    	cout << psa[compressedToOriginal[r]]-psa[compressedToOriginal[l]] << endl;
    }

    return 0;
}