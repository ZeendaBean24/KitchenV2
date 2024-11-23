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
    fastio;
    freopen("measurement.in", "r", stdin); 
    freopen("measurement.out", "w", stdout); 

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
        bool wasTopProducer = false;
        if (currentMilk == productionCounts.begin()->first) {
            wasTopProducer = true;
        }

        // Get the count of cows producing at the cow's current milk level
        int oldCount = productionCounts[currentMilk];
        bool wasLastTopCow = false;
        if (oldCount == 1) {
            wasLastTopCow = true;
        }

        // Update productionCounts to remove the cow's previous milk production
        productionCounts[currentMilk]--;
        if (productionCounts[currentMilk] == 0) {
            productionCounts.erase(currentMilk); // Remove this production level if no cows produce this amount anymore
        }

        // Update the cow's milk production with the delta
        currentMilk += log.delta;

        // Add the new milk production to the productionCounts map
        productionCounts[currentMilk]++;
        int newCount = productionCounts[currentMilk];

        bool isNowTopProducer = false;
        if (currentMilk == productionCounts.begin()->first) {
            isNowTopProducer = true;
        }

        bool isOnlyTopCow = false;
        if (newCount == 1) {
            isOnlyTopCow = true;
        }

        // Handle display changes
        if (wasTopProducer) {
            // If the cow was a top producer before the update
            if (!isNowTopProducer || !wasLastTopCow || !isOnlyTopCow) {
                // The display changes if:
                // - This cow is no longer a top producer, OR
                // - It was the last top producer at its level before, OR
                // - It is now not the sole top producer at the new level
                displayChanges++;
            }
        } else {
            if (isNowTopProducer) {
                // If the cow wasn't a top producer before, but it is now
                displayChanges++;
            }
        }
    }

    // Output the result
    cout << displayChanges << endl;
    return 0;
}