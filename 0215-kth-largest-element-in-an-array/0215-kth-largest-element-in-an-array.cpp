// read: 
// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C++-STL-partition-and-heapsort
// https://leetcode.com/problems/kth-largest-element-in-an-array/solution/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};