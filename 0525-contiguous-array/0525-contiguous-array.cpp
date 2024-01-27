class Solution {
public:
    // boostdraft Q3 (they used char and int characters, same algo idea otherwise)
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count = 0;
        int ans = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            count += (nums[i] == 0 ? -1 : 1);
            if (count == 0) ans = i+1;
            else if (mp.find(-1 * count) != mp.end()) {
                ans = max(ans, i - mp[-1 * count]);
            } else {
                mp[-1 * count] = i; // -1 to 'cancel' out
            }
        }
        return ans;
    }
};
// [0,0,1,0,0,0,1,1]