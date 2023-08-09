// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/discuss/3395952/In-case-you-are-wondering-why-greedy-works-for-this-problem
class Solution {
public:
    // sort then binary search for minimum
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left{0};
        int right{INT_MAX};
        while (left < right) {
            int mid{right - (right - left) / 2};
            if (helper(nums, p, mid)) {
                right = mid-1;                
            } else {
                left = mid;
            }
        }
        return left;
    }
private:
    bool helper(vector<int>& nums, int p, int threshold) {
        int count{0};
        int prev{INT_MAX};
        for (auto i : nums) {
            if (abs(prev - i) < threshold) {
                ++count;
                prev = INT_MAX;
            } else {
                prev = i;
            }
        }
        // cout << threshold << " " << count << " " << p << "\n";
        return count >= p;
    }
};