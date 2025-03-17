class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) {
            if (s.find(i) == s.end()) s.insert(i);
            else s.erase(i);
        }
        return s.empty();
    }
};