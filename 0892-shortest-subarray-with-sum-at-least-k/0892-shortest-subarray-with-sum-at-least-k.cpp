class Solution {
public:
    // 2 pointer approach is naive and wont work!
    // (even after factoring in heuristics like remove left if its negative)
    //
    // https://youtu.be/FcYMomGCdyM?si=JeppVNRkwcCR4LPK 
    // https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solutions/143726/c-java-python-o-n-using-deque 
    // brute force is O(n^2), TLE
    // prefix sum with min-heap is O(nlogn)
    // (note: the key insight from this solution is that if we have )
    //
    // prefix sum with deque O(n) 
    // (note: we can optimize by combining the prefix sum creation with checking of best answer; 
    // 1 pass instead of 2)
    // 
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int n = nums.size();
        vector<long> prefix{nums[0]};
        prefix.reserve(n);
        for (int i = 1; i < n; ++i) {
            prefix.emplace_back(prefix.back() + nums[i]);
        }
        deque<int> dq; // stores index to prefix sum arr
        for (int i = 0; i < n; ++i) {
            if (prefix[i] >= k) ans = min(ans, i + 1);
            // found a subarray with sum ≥ k, try it in our answer, then remove it.
            // why do we remove the front element from the dq?
            // since we are iterating from left to right, if [left, i] is a possible minimal sum
            // anything to the right of i is worse paired with left is worse
            // so we never need to consider left ever again, hence why we remove it
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            // maintain monotonic property of dq (we want an increasing queue)
            // why should we keep the dq increasing?
            // if we have i < j and prefix[i] >= prefix[j], 
            // we will never get a better solution using i vs using j (due to their positions)
            // (also in the case of >, j might be a good candidate but i is not)
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// [84,-37,32,40,95]
// 167
// [-28,81,-20,28,-29]
// 89
// [-34,37,51,3,-12,-50,51,100,-47,99,34,14,-13,89,31,-14,-44,23,-38,6]
// 151
// [-34,37,51,3,-12,-50,51,100]
// 151