class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<pair<int,int>> v; // <smallest_left_to_this_num, num>
        int smallest = INT_MAX;
        for (auto i : nums) {
            smallest = min(smallest, i);
            while (!v.empty() && v.back().second < i) {
                v.pop_back();
            }
            if (!v.empty() && v.back().first < i && i < v.back().second) return true;
            v.emplace_back(smallest, i);
        }
        return false;
    }
};