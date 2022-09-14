class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> freq(requests.size()+1, 0);
        vector<int> range(nums.size()+1, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        for (auto i : requests) {
            ++range[i[0]];
            --range[i[1]+1];
        }
        
        // cout << "range: ";
        // for (auto i : range) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        
        auto cur{0};
        for (auto i : range) {
            cur += i;
            if (cur >= 1) {
                ++freq[cur];
            }
        }
        
        // cout << "freq: ";
        // for (auto i : freq) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        
        auto ans{0l};
        auto numsIndex{0};
        for (int i = freq.size()-1; i >= 0; --i) {
            if (freq[i] != 0) {
                for (auto j = 0; j < freq[i]; ++j) {
                    ans += (long)nums[numsIndex] * i;
                    // cout << nums[numsIndex] << " " << i << "\n";
                    ans %= (int)(1e9 + 7);
                    ++numsIndex;
                }
            }
        }
        return ans;
    }
};

// https://leetcode.com/submissions/detail/799260101/testcase/