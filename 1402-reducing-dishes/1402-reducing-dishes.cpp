class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // sort in descending order
        sort(satisfaction.rbegin(), satisfaction.rend());
        auto sum{0}; // sum of arr[0] * i + ... + arr[i]
        auto prefixSum{0}; // sum of arr[0] + ... + arr[i]
        auto ans{0};
        for (auto i = 0; i < satisfaction.size(); ++i) {
            prefixSum += satisfaction[i];
            sum += prefixSum;
            ans = max(ans, sum);
        }
        return ans;
    }
};