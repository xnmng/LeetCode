class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        unordered_map<int,int> freq;
        for (auto i : nums) {
            ++freq[i];
        }
        unordered_map<int,int> ends;
        for (auto& i : nums) {
            if (freq[i] == 0) continue;
            if (ends[i-1] > 0) {
                --ends[i-1];
                ++ends[i];
                --freq[i];
            } else if (freq[i+1] > 0 && freq[i+2] > 0) {
                --freq[i];
                --freq[i+1];
                --freq[i+2];
                ++ends[i+2];
            } else {
                return false;
            }
        }        
        return true;
    }
};