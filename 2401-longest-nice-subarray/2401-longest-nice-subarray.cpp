class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        auto ans{1};
        auto l{0};
        auto r{1};
        auto count{1};
        auto cur{nums[0]};
        while (r < nums.size()) {
            while (l < r && (cur & nums[r]) != 0) {
                cur ^= nums[l];
                ++l;
            }
            cur |= nums[r];
            ++r;
            ans = max(r-l, ans);
        }
        return ans;
    }
};

// [84139415,693324769,614626365,497710833,615598711,264,65552,50331652,1,1048576,16384,544,270532608,151813349,221976871,678178917,845710321,751376227,331656525,739558112,267703680]