class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if (n % 2 == 1) {
            --n;
            ans.push_back(0);
        }
        auto count{1};
        while (n > 0) {
            ans.push_back(count);
            ans.push_back(-1 * count);
            n -= 2;
            ++count;
        }
        return ans;
    }
};