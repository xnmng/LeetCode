class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int count = 1;
            long next = nums[i];
            while (s.find(next * next) != s.end()) {
                s.erase(next);
                if (next * next > INT_MAX) break;
                next = next * next;
                ++count;
            }
            ans = max(ans, count);
        }
        return ans == 1 ? -1 : ans;
    }
};
// [4,16,256,65536]