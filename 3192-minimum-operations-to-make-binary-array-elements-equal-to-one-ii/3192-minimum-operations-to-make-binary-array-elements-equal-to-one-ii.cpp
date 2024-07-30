class Solution {
public:
    // go through the arr, check the current parity of the index (count + arr[i])
    // if already 1, continue. 
    // otherwise we need to perform a flip.
    // increment flip count AKA ans
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (auto i : nums) {
            if ((ans + i) % 2 == 1) continue;
            ++ans;
        }
        return ans;
    }
};