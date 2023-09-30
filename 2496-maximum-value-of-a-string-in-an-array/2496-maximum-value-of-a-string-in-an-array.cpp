class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (auto& i : strs) {
            bool isNum = true;
            int val = 0;
            for (auto j : i) {
                if (isdigit(j)) {
                    val *= 10;
                    val += j - '0';
                } else {
                    isNum = false;
                    break;
                }
            }
            ans = max(ans, isNum ? val : (int)i.size());
        }
        return ans;
    }
};