class Solution {
public:
    int minSetSize(vector<int>& arr) {
        auto n{arr.size()};
        unordered_map<int,int> mp;
        for (auto i : arr) {
            ++mp[i];
        }
        priority_queue<pair<int,int>> pq; // sorts by first, then second
        for (auto [k,v] : mp) {
            pq.push({v, k});
        }
        auto ans{0};
        auto removed{0};
        while (removed < n % 2 + n/2) {
            auto p{pq.top()};
            pq.pop();
            ++ans;
            removed += p.first;
        }
        return ans;
    }
};