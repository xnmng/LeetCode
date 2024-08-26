class Solution {
public:
    // simulate the process
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        int n = energy.size();
        int diff;
        for (int i = 0; i < n; ++i) {
            if (initialEnergy <= energy[i]) {
                diff = energy[i] - initialEnergy + 1;
                initialEnergy += diff;
                ans += diff;
            }
            if (initialExperience <= experience[i]) {
                diff = experience[i] - initialExperience + 1;
                initialExperience += diff;
                ans += diff;
            }
            initialExperience += experience[i];
            initialEnergy -= energy[i];
        }
        return ans;
    }
};