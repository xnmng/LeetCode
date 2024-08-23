class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<int,int> mp;
        for (int i : nums) ++mp[i];
        while (!mp.empty()) {
            int start = mp.begin()->first;
            for (int i = 0; i < k; ++i) {
                if (mp[start + i] == 0) return false;
                if (mp[start + i] == 1) mp.erase(start + i);
                else --mp[start + i];
            }
        }
        return true;
    }
};