class Solution {
    bool matches(vector<int>& nums, int index, vector<int>& v) {
        if (index + v.size() > nums.size()) return false;
        for (auto i = 0; i < v.size(); ++i) {
            if (nums[index+i] != v[i]) return false;
        }
        return true;
    }
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        auto cur{0};
        for (auto i = 0; i < nums.size(); ++i) {
            // cout << i << "\n";
            if (cur == groups.size()) return true;
            if (matches(nums, i, groups[cur])) {
                // cout << "matched with index " << i << "\n";
                i += groups[cur].size()-1; // account for ++i in the for-loop
                ++cur;
            }
        }
        // cout << cur << " " << groups.size() << "\n";
        return cur == groups.size();
    }
};

// [[1,2,3],[1,2,3,4,5]]
// [1,2,3,4,5,1,2,3]
// [[-5,0]]
// [2,0,-2,5,-1,2,4,3,4,-5,-5]