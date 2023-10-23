class Solution {
    // groups will either have k or (k+1) people in them
    int helper(unordered_map<int,int>& mp, int k) {
        int groups = 0;
        for (auto& [_,v] : mp) {
            int a = v / (k+1); // use (k+1), not k!
            int b = v % (k+1); // use (k+1), not k!
            if (b == 0) {
                groups += a;
            }
            else if (k - b <= a) {
                groups += a + 1;
            }
            else return -1; // impossible to split v people into groups with either k or k+1 people
        }
        return groups;
    }
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto i : nums) {
            ++mp[i];
        }
        int minimum = INT_MAX;
        for (auto& [k,v] : mp) minimum = min(minimum, v);
        int res;
        for (auto i = minimum; i > 0; --i) {
            res = helper(mp, i);
            if (res != -1) break;
        }
        return res;
        
    }
};
// [3,3,1,3,1,1,3,3,3,1,1]

// not possible to binary search on the answer (counterexample above)
// printing i = 1 to 9 and helper() gives:
// 1 6
// 2 4
// 3 -1
// 4 -1
// 5 2
// 6 -1
// 7 -1
// 8 -1
// 9 -1
// no monotonic property
