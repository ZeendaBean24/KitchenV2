#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

double calculate(double r1, double p1, double p2, double A, double B) {
	double a = B * p1 + A * p2;
	double c = -B * p1 * r1 * r1; 
	double discriminant = -4 * a * c;

	if (discriminant < 0) {
		return -1;
	}

	double r2 = sqrt(discriminant) / (2 * a);

	if (0 < r2 && r2 < r1) {
		return r2; 
	}

	return -1;
}

int main() {
    fastio;

    int n; cin >> n; 

    vd x; 
    REP(i,0,n) {
    	double a; cin >> a;
    	x.push_back(a);
    }

    int m; cin >> m;

    vd y; 
    REP(i,0,m) {
    	double a; cin >> a;
    	y.push_back(a);
    }

    int k; cin >> k;
    vd z; 
    REP(i,0,k) {
    	double a; cin >> a;
    	z.push_back(a);
    }

    double a, b; cin >> a >> b;

    sort(x.begin(), x.end());
    reverse(x.begin(), x.end()); 

    double maximum = 0;
    for (double o : x) {
    	for (double p : y) {
    		for (double q : z) {
    			double r2 = calculate(o, p, q, a, b);
    			if (r2 > 0) {
    				maximum = max(r2, maximum);
    			}
    		}
    	}
    	if (maximum > 0) {
    		break;
    	}
    }

    cout << fixed << setprecision(12) << maximum;

}