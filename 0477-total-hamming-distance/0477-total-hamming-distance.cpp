class Solution {
public:
    // calculate the number of bits for each position
    // calculate the hamming distance for the entire arr for that bit
    int totalHammingDistance(vector<int>& nums) {
        vector<int> v(32, 0);
        for (auto i : nums) {
            int count = 0;
            while (i != 0) {
                if (i % 2 == 1) ++v[count];
                i /= 2;
                ++count;
            }
        }
        int n = nums.size();
        int ans = 0;
        for (auto i : v) {
            ans += i * (n - i);
        }
        return ans;
    }
};