// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1064793/Binary-Search-or-with-Intuition-and-explanation
class Solution {
private:
    bool check(vector<int>& nums, int size, int maxOperations) {
        auto ans{0};
        for (auto i : nums) {
            if (i <= size) continue;
            i % size == 0 ? ans += i/size - 1 : ans += i/size;
        }
        return ans <= maxOperations;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        auto left{1};
        auto right{INT_MAX};
        while (left < right) {
            auto mid{left + (right - left) / 2};
            // cout << left << " " << right << " " << mid << " " << "\n";
            if (check(nums, mid, maxOperations)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};