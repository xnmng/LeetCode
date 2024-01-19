class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while (k > 0) {
            --k;
            ans += pq.top();
            pq.push(ceil(1.0 * pq.top() / 3));
            pq.pop();
        }
        return ans;
    }
};