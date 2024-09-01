class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans;
        priority_queue<int> pq;
        for (auto& q : queries) {
            pq.push(abs(q[0]) + abs(q[1]));
            if (pq.size() > k) pq.pop();
            if (pq.size() < k) ans.emplace_back(-1);
            else ans.emplace_back(pq.top());
        }
        return ans;
    }
};