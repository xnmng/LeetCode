class Solution {
public:
    // each element of the valid array (if it exists) is being used twice (see formula)
    // if we XOR the derived array, it should return 0
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for (int i : derived) ans = ans ^ i;
        return ans == 0;
    }
};