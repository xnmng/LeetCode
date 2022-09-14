class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto i : nums) {
            ++mp[i];
        }
        auto ans{-1};
        auto count{0};
        for (auto i : mp) {
            if (i.first % 2 == 0) {
                if (i.second > count 
                    || (i.second == count && i.first < ans)) {
                    ans = i.first;
                    count = i.second;
                }
            }
        }
        return ans;
    }
};