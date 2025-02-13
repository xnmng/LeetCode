class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        for (int i : nums) {
            pq.push(i);
        }
        int ans = 0;
        long temp;
        long temp2;
        while (pq.top() < k) {
            temp = pq.top();
            pq.pop();
            temp2 = pq.top();
            pq.pop();
            pq.push(min(temp, temp2) * 2 + max(temp, temp2));
            ++ans;
        }
        return ans;
    }
};