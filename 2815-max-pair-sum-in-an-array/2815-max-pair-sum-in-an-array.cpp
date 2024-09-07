class Solution {
public:
    // cache for each digit, what is the largest number with that digit we have so far
    int maxSum(vector<int>& nums) {
        int ans = -1;
        vector<int> v(10, 0);
        int temp;
        int largest = 0;
        for (int i : nums) {
            temp = i;
            largest = 0;
            while (temp > 0) {
                largest = max(largest, temp % 10);
                temp /= 10;
            }
            if (v[largest] != 0) ans = max(ans, i + v[largest]);
            v[largest] = max(v[largest], i);
        }
        return ans;
    }
};