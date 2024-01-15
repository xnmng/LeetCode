class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto i : nums) {
            ++mp[i];
        }
        int freq = 0;
        int count = 0;
        for (auto& [k,v] : mp) {
            if (freq < v) {
                freq = v;
                count = v;
            }
            else if (freq == v) count += v;
        }
        return count;
    }
};