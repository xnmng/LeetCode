class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cur(26, INT_MAX);
        vector<int> temp;
        for (string& s : words) {
            temp = vector<int>(26, 0);
            for (char c : s) {
                ++temp[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                cur[i] = min(cur[i], temp[i]);
            }
        }
  
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cur[i]; ++j) {
                ans.emplace_back(1, 'a' + i);
            }
        }
        return ans;
    }
};