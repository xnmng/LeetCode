class Solution {
public:
    // trick: to optimize from brute force checking [i - k, i + k]
    // keep track of prev, if prev doesnt exist, smallest possible is i-k
    // otherwise, smallest possible is i-k+1 or i2-k
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        int prev = INT_MAX;
        for (int i : nums) {
            if (prev == INT_MAX) {
                s.insert(i - k);
                prev = i - k;
            }
            else {
                if (prev + 1 > i + k) continue;
                prev = max(prev + 1, i - k);
                s.insert(prev);
            }
            // if (s.contains(i + k)) continue;
            // for (int j = -k; j <= k; ++j) {
            //     if (!s.contains(i + j)) {
            //         s.insert(i + j);
            //         break;
            //     }
            // }
        }
        return s.size();
    }
};