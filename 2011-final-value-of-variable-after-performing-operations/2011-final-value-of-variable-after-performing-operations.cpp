class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans;
        for (string& s : operations) {
            ans += s[1] == '+' ? 1 : -1;
        }
        return ans;
    }
};