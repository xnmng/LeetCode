class Solution {
public:
    // note that we can perform the same operation on an unmarked enemy multiple times
    // optimal strategy would be to keep 1 unmarked enemy with smallest value and sum the rest of the energies
    // note the edge case points need to be >= 1
    //
    // make it a habit to use largest size type in question params everywhere!
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long ans = 0;
        long long minimum = INT_MAX;
        int n = enemyEnergies.size();
        long long sum = currentEnergy;
        for (int i = 0; i < n; ++i) {
            // dont add to currentEnergy; will overflow
            sum += enemyEnergies[i];
            minimum = min(minimum, (long long) enemyEnergies[i]);
        }
        if (currentEnergy < minimum) return 0;
        sum -= minimum;
        return sum / minimum;        
    }
};