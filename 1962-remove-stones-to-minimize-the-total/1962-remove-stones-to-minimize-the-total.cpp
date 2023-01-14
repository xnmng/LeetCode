class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        auto total{0};
        priority_queue<int> pq;
        for (auto i : piles) {
            pq.push(i);
            total += i;
        }
        int cur;
        for (auto i = 0; i < k; ++i) {
            cur = pq.top();
            pq.pop();
            total -= cur/2;
            pq.push((cur+1) / 2);
        }
        return total;
    }
};