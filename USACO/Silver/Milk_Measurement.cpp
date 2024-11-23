#include <bits/stdc++.h>

using namespace std;

typedef long long ll; typedef long double ld;
typedef vector<int> vi; typedef vector<double> vd; typedef vector<string> vs; typedef vector<char> vc; typedef vector<long long> vll; typedef vector<bool> vb;
typedef pair<int, int> pii; typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)
 
// Structure to represent a measurement log
struct Measurement {
    int day;
    int cow;
    int delta;
};

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("measurement.in", "r", stdin);  // Input file
    // freopen("measurement.out", "w", stdout); // Output file

    int N, G; // Number of logs and the initial milk production level
    cin >> N >> G;

    // Vector to store all measurements
    vector<Measurement> logs(N);

    // Read the logs
    for (auto& log : logs) {
        cin >> log.day >> log.cow >> log.delta;
    }

    // Sort the logs by day
    sort(logs.begin(), logs.end(), [](const Measurement& a, const Measurement& b) {
        return a.day < b.day;
    });

    // Map to store the count of cows producing a specific amount of milk
    map<int, int, greater<int>> productionCounts;
    productionCounts[0] = N + 1; // Start with all cows producing 0 milk (a dummy baseline)

    // Map to track the current milk production of each cow
    map<int, int> cowMilkProduction;

    int displayChanges = 0; // Count the number of display changes

    // Process each log
    for (const auto& log : logs) {
        int& currentMilk = cowMilkProduction[log.cow]; // Current milk production of this cow

        // Check if this cow was part of the top producers
        bool wasTopProducer = (currentMilk == productionCounts.begin()->first);

        // Get the count of cows producing at the cow's current milk level
        int oldCount = productionCounts[currentMilk]--;

        // Remove the milk level from the map if no cows are left producing that amount
        if (oldCount == 1) {
            productionCounts.erase(currentMilk);
        }

        // Update the cow's milk production with the delta
        currentMilk += log.delta;

        // Add the new milk production to the productionCounts map
        int newCount = ++productionCounts[currentMilk];

        // Check if this cow is now part of the top producers
        bool isTopProducer = (currentMilk == productionCounts.begin()->first);

        // Determine if the leaderboard has changed
        if (wasTopProducer) {
            // If it was a top producer but something about the leaderboard has changed
            if (!isTopProducer || oldCount != 1 || newCount != 1) {
                ++displayChanges;
            }
        } else if (isTopProducer) {
            // If it wasn't a top producer but is now part of the top producers
            ++displayChanges;
        }
    }

    // Output the result
    cout << displayChanges << endl;
    return 0;
}

// int main() {
//     fastio;
//     // freopen("measurement.in", "r", stdin);
//     // freopen("measurement.out", "w", stdout);

//     ll n, g; cin >> n >> g;

//     vector<pair<ll, pll>> logs; 
//     map<ll, ll> cowIdToMilkQuantity;
//     set<ll> topProducers;
//     REP(i,0,n) {
//     	ll day, id; string c; cin >> day >> id >> c;
//     	ll change;
//     	if (c[0] == '+') {
//     		change = stoi(c.substr(1));
//     	} else {
//     		change = stoi(c.substr(1)) * -1;
//     	}
//     	cowIdToMilkQuantity[id] = g;
//     	logs.push_back(make_pair(day, make_pair(id, change)));
//         topProducers.insert(id);
//     }

//     sort(logs.begin(), logs.end());

//     map<ll, ll> milkQuantityToCows;
//     milkQuantityToCows[g] = n;

//     int count = 0;
//     ll currentTopProduction = g;

//     set<ll> previousTopProducers = topProducers; // Initialize previousTopProducers

//     // cout << "Cycle -1 " << " Top Production " << currentTopProduction << " Top Production Cows " << currentTopProductionCows << endl;  
//     REP(i,0,n) {
//     	ll id = (logs[i].second).first;
//     	ll change = (logs[i].second).second;
//     	ll prevQuantity = cowIdToMilkQuantity[id];

//     	// Update quantity 
//     	cowIdToMilkQuantity[id] += change;
//     	ll newQuantity = cowIdToMilkQuantity[id];
//     	milkQuantityToCows[prevQuantity]--;
//     	if (milkQuantityToCows[prevQuantity] == 0) {
//     		milkQuantityToCows.erase(prevQuantity);
//     	}
//     	milkQuantityToCows[newQuantity]++;

//         // Update topProducers
//         if (newQuantity < currentTopProduction) {
//             topProducers.erase(id); // Remove cow from top producers
//         } else if (newQuantity >= currentTopProduction) {
//             if (newQuantity > currentTopProduction) {
//                 // New top production level, clear previous top producers
//                 currentTopProduction = newQuantity;
//                 topProducers.clear();
//             }
//             topProducers.insert(id); // Add cow to top producers
//         }

//         // Handle display changes
//         auto it = milkQuantityToCows.rbegin(); // Reverse iterator for max
//         ll newTopMilk = it->first;
//         ll newTopCount = it->second;

//         if (newTopMilk != currentTopProduction || topProducers != previousTopProducers) {
//             count++;
//             currentTopProduction = newTopMilk;
//             previousTopProducers = topProducers; // Update previousTopProducers
//         }
//         	// cout << "Cycle " << i << " Top Production " << currentTopProduction << " Top Production Cows " << currentTopProductionCows << endl;  
//     }

//     cout << count;

//     return 0;
// }