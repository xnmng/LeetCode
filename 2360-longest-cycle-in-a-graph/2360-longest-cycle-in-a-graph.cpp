class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<pair<int,int>> took(edges.size()); // did we take the outgoing edge from i?
        auto ans = -1;
        int len; 
        int cur;
        for (auto node = 0; node < edges.size(); ++node) {
            cur = node;
            len = 1;
            while (cur != -1 && took[cur].second == 0) {
                took[cur] = make_pair(node, len);
                cur = edges[cur];
                ++len;
            } 
            if (cur != -1 && took[cur].first == node) {
                ans = max(ans, len-took[cur].second);
            }
        }
        return ans;
    }
};