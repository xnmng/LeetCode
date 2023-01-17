class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> s;
        int cur;
        for (auto i : nums) {
            cur = 2;
            while (i != 1) {
                if (i % cur == 0) {
                    i /= cur;
                    s.insert(cur);
                } else ++cur;
            }
        }
        return s.size();
    }
};