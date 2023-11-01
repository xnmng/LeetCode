class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        deque<int> q(nums.begin(), nums.end());
        unordered_set<int> s;
        while (!q.empty()) {
            s.insert(q.front() + q.back());
            q.pop_front();
            q.pop_back();
        }
        return s.size();
    }
};