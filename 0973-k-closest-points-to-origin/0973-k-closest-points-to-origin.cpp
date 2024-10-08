class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        
        for (int i = 0; i < points.size(); ++i) {
            pq.emplace(pow(points[i][0], 2) + pow(points[i][1], 2), i);
            if (i >= k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto [_, index] = pq.top();
            pq.pop();
            ans.emplace_back(points[index]);
        }
        return ans;
    }
};