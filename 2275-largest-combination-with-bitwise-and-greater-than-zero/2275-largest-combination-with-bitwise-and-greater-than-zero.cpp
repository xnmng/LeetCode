class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        auto ans{0};
        auto count{1};
        bool hasNext{true};
        while (hasNext) {
            count = 0;
            hasNext = false;
            for (auto& i : candidates) {
                if (i > 0) hasNext = true;
                if (i % 2 == 1) ++count;
                i /= 2;
            }
            ans = max(count, ans);
        }
        return ans;
    }
};